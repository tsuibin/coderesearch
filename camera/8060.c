#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <opencv/highgui.h> 
/*
	-lcv -lhighgui
*/

int fc; 

void compare80x60RGB(unsigned char * newFrame, 
		unsigned char * oldFrame, 
		int byteCount) 
{ 
	/* 
	   byteCount 的值一般为 640*480*3 
	   (RGB数据) 
	   块数据大小 80x60x3 
	 */ 
	fc++; 
	char blockNO = 0; 
	const int blockSize = 80 * 60; 
	int i,j; 
	int diffCount; 
	int abs; 
	for(i = 0; i < byteCount; i++){ 
		if ( *(newFrame + i) != *(oldFrame + i) ){ 

			abs = *(newFrame +i) - *(oldFrame + i); 
			if ( abs < 0 ) { 
				abs = -abs; 
			} 
			//printf("!abs %d \n",abs );  

			if(abs > 70 ) { 

				//发送块号 
				printf("第%d帧 第%d 块数据有更新\n",fc,blockNO); 
				printf("!abs %d \n",abs );  
				//send blockNO 

				//发送之后 80*60*3 字节数据 
				unsigned char *ptr = ( newFrame + blockNO * blockSize ); 
				for(j = 0; j < blockSize ; j++){ 
					//send *(ptr +j); 
				} 

				blockNO++;// 块号 
				i = ( blockNO * blockSize ); 
			} 
		} 
	} 
	printf("=== frame ===\n");  
} 

int main(int argc, char* argv[]) 
{ 
	unsigned int i; 
	unsigned char* src; 
	unsigned char * newImg = (unsigned char *)malloc( 640*480 ); 
	unsigned char * oldImg = (unsigned char *)malloc( 640*480 ); 
	unsigned char * ptr; 
	CvCapture* capture = cvCreateCameraCapture( -1 ); 
	
	if( capture == NULL )
	{
		printf("open camera error\n"); 
		return -1; 
	}
	IplImage * frame; 
	int cc = 10; 

	while( cc ) { 

		frame = cvQueryFrame( capture ); 

		if ( !frame ) break; 

		src = (unsigned char *)frame->imageData; 



		ptr = newImg; 

		for ( i = 0; i < 640*480; ++i) 
		{ 
			src++; 
			*ptr++ = *src++; 
			src++; 
			//*ptr++ = *src++; 
			//*ptr++ = *src++; 
		} 


		compare80x60RGB(newImg,oldImg,640*480); 

		ptr = oldImg; 

		src = (unsigned char *)frame->imageData; 
		for (i = 0; i < 640*480; ++i) 
		{ 
			src++; 
			*ptr++ = *src++; 
			src++;             

		} 

		//                usleep( 5000000 ); 
	} 


	cvReleaseCapture( &capture ); 

	return 0; 
}  
