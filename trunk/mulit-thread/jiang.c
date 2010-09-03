#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/stat.h> 
  
 typedef struct fileinfo { 
                 int size; 
                 char *src_file; 
                 char *dst_file; 
 }FINFO,*PFINFO; 
  
 PFINFO fi = NULL; 
  
 void usage(void); 
 struct fileinfo *file_alloc(char *, char *); 
 void automic_read(FILE *, void *, int, int); 
 void automic_write(FILE *, void *, int, int); 
 void * tcopy(void *); 
 void free_mem(void); 
 void sys_err(void *); 
  
 int main(int argc ,char *argv[])         
 { 
         struct stat buf; 
         pthread_t tid1,tid2; 
         void *rect; 
         if (argc < 3) 
                 usage(); 
         stat(argv[1],&buf); 
         if (!buf.st_size) 
         { 
                 printf("empty file!aborted.\n"); 
                 exit(-1); 
         } 
         fi = file_alloc(argv[1],argv[2]); 
         sys_err(fi); 
         printf("starting copy %s to %s...\n",argv[1],argv[2]); 
         pthread_create(&tid1,NULL,tcopy,(void *)0); 
         pthread_create(&tid2,NULL,tcopy,(void *)1); 
  
         pthread_join(tid1,&rect);        
         pthread_join(tid2,&rect); 
         printf("copy %s to %s,completed.\n",argv[1],argv[2]); 
         free_mem(); 
         return 0;        
 } 
  
 void sys_err(void *p) 
 { 
         if (!p)  
         { 
                 printf("Fatal error found,aborted.\n"); 
                 exit(-1); 
         }        
 } 
  
 void automic_read(FILE *fp,void * buf,int size,int offset) 
 { 
         if (fseek(fp,offset,SEEK_SET) < 0) 
                 perror("fseek"); 
         fread(buf,size,1,fp);          
 } 
  
 void automic_write(FILE *fp,void * buf,int size,int offset) 
 { 
         if (fseek(fp,offset,SEEK_SET) < 0)       
                 perror("fseek"); 
         fwrite(buf,size,1,fp); 
 } 
  
 void * tcopy(void *arg) 
 { 
         int fd1,fd2; 
         char *buf = NULL; 
         int offset,size; 
         FILE *fps,*fpd; 
         if ((int)arg) 
         { 
                 offset = 0; 
                 size = fi->size/2; 
         } 
         else 
         { 
                 offset = fi->size/2; 
                 size = fi->size - fi->size/2; 
         } 
         fps = fopen(fi->src_file,"r"); 
         fpd = fopen(fi->dst_file,"w"); 
         buf = (char *)malloc(size); 
         printf("size = %d, offset = %d\n",size,offset); 
  
         if (fseek(fps,offset,SEEK_SET) < 0) 
                 perror("fseek"); 
         fread(buf,size,1,fps);                 
  
         if (fseek(fpd,offset,SEEK_SET) < 0)      
                 perror("fseek"); 
         fwrite(buf,size,1,fpd); 
  
          
         //automic_read(fps,(void *)buf,size,offset); 
         //automic_write(fpd,(void *)buf,size,offset); 
         fclose(fps); 
         fclose(fpd); 
         free(buf); 
 } 
  
 void usage(void) 
 { 
         printf("usage:\ncopy  <oldfilename>  <newfilename>\n"); 
         exit(1); 
 } 
  
 PFINFO file_alloc(char *srfn, char *dtfn) 
 { 
         PFINFO p; 
         struct stat fstat; 
         p = (PFINFO)malloc(sizeof(FINFO)); 
         stat(srfn,&fstat); 
         p->src_file = srfn; 
         p->dst_file = dtfn; 
         p->size = fstat.st_size;  
         return p; 
 } 
  
 void free_mem(void) 
 { 
         free(fi); 
 } 
