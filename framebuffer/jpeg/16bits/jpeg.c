#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <jpeglib.h>
#include <jerror.h>

#define DEBUG
#define FBDEV "/dev/fb0"
#ifdef DEBUG
#define debug(fmt,args...)      printf (fmt ,##args)
#define debugX(level,fmt,args...) if (DEBUG>=level) printf(fmt,##args);
#else
#define debug(fmt,args...)
#define debugX(level,fmt,args...)
#endif


struct framebuffer{
	unsigned int fb_w;
	unsigned int fb_h;
	unsigned int fb_depth;
}fb_info;

struct file_display{
	unsigned int w;
	unsigned int h;
	unsigned int dep;
}file_info;
char *fb_device=FBDEV;
char *fbmem;
unsigned char *pbuf;
int actual_file_len;

/*for 16 bits display*/
unsigned short *p16;

int get_fb_info(int fd)
{
	struct fb_fix_screeninfo fb_finfo;
	struct fb_var_screeninfo fb_vinfo;
	if (ioctl(fd, FBIOGET_FSCREENINFO, &fb_finfo)) {
		perror(__func__);
		return (-1);
	}
	if (ioctl(fd, FBIOGET_VSCREENINFO, &fb_vinfo)) {
		perror(__func__);
		return (-1);
	}
	fb_info.fb_w = fb_vinfo.xres;
	fb_info.fb_h = fb_vinfo.yres;
	fb_info.fb_depth = fb_vinfo.bits_per_pixel;
	return 0;
}

int get_file_info(FILE *fd)
{
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;
	unsigned char *p;
	/*
	 * init jpeg decompress object error handler
	 */
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);
	/*
	 * bind jpeg decompress object to infile
	 */
	jpeg_stdio_src(&cinfo,fd);
	/*
	 * read jpeg header
	 */
	jpeg_read_header(&cinfo, TRUE);
	/*
	 * decompress process.
	 * note: after jpeg_start_decompress() is called
	 * the dimension infomation will be known,
	 * so allocate memory buffer for scanline immediately
	 */
	jpeg_start_decompress(&cinfo);
	debug("picture width=%d,hight=%d,color depth bytes=%d\n",cinfo.output_width,cinfo.output_height,cinfo.output_components);
	if ((cinfo.output_width > fb_info.fb_w) || (cinfo.output_height > fb_info.fb_h)) {
		printf("too large JPEG file,cannot display\n");
		return (-1);
	}
	pbuf = (unsigned char *) malloc(cinfo.output_width * cinfo.output_height * cinfo.output_components);
	p=pbuf;
	while (cinfo.output_scanline < cinfo.output_height) {
		jpeg_read_scanlines(&cinfo, &p, 1);
		p+=cinfo.output_width *cinfo.output_components;
	}
	file_info.w=cinfo.output_width;
	file_info.h=cinfo.output_height;
	file_info.dep=cinfo.output_components;
	actual_file_len=cinfo.output_width * cinfo.output_height * cinfo.output_components;
	/*
	 * finish decompress, destroy decompress object
	 */
	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);
	return 0;
}

int color32to16(void)
{
	int i,len;
	unsigned short r,g,b,*p;
	len=2*actual_file_len/file_info.dep;
	debug("file color bytes len =%d changed to len =%d\n",actual_file_len,len);
	p16=(unsigned short *)malloc(len);
	if(p16==NULL){
		printf("malloc error!\n");
		return -1;
	}
	for(i=0,p=p16;i<actual_file_len;i+=3,p++){
		r=((pbuf[i]>>3)<<11)&0xf800;
		g=((pbuf[i+1]>>2)<<5)&0x07e0;
		b=(pbuf[i+2]>>3)&0x001f;
		*p=(unsigned short)(r|g|b);
	}
	return 0;
}

int draw_pixel(void)
{
	int i,j,w,h;
	unsigned short *p,*dst;
	p=p16;
	w=file_info.w;
	h=file_info.h;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++,p++){
			dst=(unsigned short *)fbmem+i*fb_info.fb_w+j;
			*dst=*p;        
		}
	}
	return 0;
}

int main(int argc , char *argv[])
{
	int fbdev;
	int i,screensize;
	FILE *infile;
	int ret;
	fbdev=open(fb_device,O_RDWR);
	if(fbdev<0){
		printf("Open %s error!\n",fb_device);
		return -1;
	}

	get_fb_info(fbdev);

	debug("framebuffer info:width %d,hight %d,depth %d\n",fb_info.fb_w,fb_info.fb_h,fb_info.fb_depth);
	screensize=fb_info.fb_w*fb_info.fb_h*fb_info.fb_depth/8;
	if ((fbmem = mmap(0, screensize,PROT_READ | PROT_WRITE,MAP_SHARED, fbdev, 0)) == MAP_FAILED) {
		perror(__func__);
		return -1;
	}

	if ((infile = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "open %s failed\n", argv[1]);
		exit(-1);
	}

	ret=get_file_info(infile);
	if(ret==-1){
		goto label2;
	}
	/*display according color depth*/
	switch(fb_info.fb_depth){
		case 16:
			debug("***Framebuffer is 16 bits color depth***\n");    
			ret=color32to16();
			if(ret==-1)
				goto label1;
			draw_pixel();
			break;
		default:
			printf("Framebuffer color depth %d is not supported!\n");
	}


	free(p16);
label1:        
	free(pbuf);
label2:
	fclose(infile);
	munmap(fbmem,screensize);
	close(fbdev);
	return 0;
}
