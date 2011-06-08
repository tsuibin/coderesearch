/*注：带参数输入，参数为文件名（不含后缀）*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"init.h"
#define N 1024
#define M 5000

int count=1,sel=1;
FILE *f;
char buf[N];
char data[M][N];
char const head[2][32]={"<a href=\"http://","<img src=\""};//修改此处可进行精确查找或其它文件查找

void accept(int argc, char* argv[]);
int data_read();
void key_word_seek();

int main(int argc, char* argv[])
{
	init();
	accept( argc, argv );
	printf("选择搜索方式（网址：1；图片：2；……）：");
	scanf("%d",&sel);
	if(sel != 1 && sel != 2){
		printf("选择错误！\n");
		exit( -1 );
	}
	while( !feof( f ) )
		data_read();
	key_word_seek();

	return 0;
}

void accept(int argc, char* argv[])
{
	char html[10];

	if( argc != 2 ){
		printf( "未输入参数！\n" );
		exit( -1 );
	}else if( strlen( argv[1] ) >=5 ){//文件名限制
		printf( "参数错误！\n" );
		exit( -1 );
	}

	strcat( strcpy( html, argv[1] ), ".html" );//文件名组合

	if( ( f = fopen( html, "r" ) ) == NULL ){//判断及打开文件
			printf( "文件不存在！\n" );
			exit( -1 );
	}
}

int data_read()//int型为了跳出
{
	int i;
//读头
	for( i = 0; i < strlen( head[sel-1] ) && !feof( f ); i++){
		buf[i] = fgetc( f );
		if( buf[i] == head[sel-1][i] )
			continue;
		else i = 0;
		if(feof(f))//为空跳出
			break;
	}
//重定向buf指针
	memmove( buf, buf+i-1, 1 );
//读域名
	i = 0;
	do{
		buf[i] = fgetc( f );
		if( feof( f ) )
			break;//为空跳出
		i++;
		if( i >= N ){
			printf("缓存不足！\n");
			exit( -1 );
		}
	}while( buf[i - 1] != '"' );
	if( feof(f) )
		return 0;//跳出此函数
//加结束符
	buf[i-1]='\0';
	strcpy( data[count], buf );//数据复制
	printf("%d\thttp://", count++ );
	puts( data[count - 1] );
}

void key_word_seek()
{
	int i,j=0;
	char temp[16];

	printf("请输入关键词(Less than 16byte)：");
	scanf("%s", temp );
	for(i = 0; i < count - 1; i++)
		if( strstr( data[i], temp ) != NULL )
			if( sel == 1 ){
				printf("%d\thttp://%s\n", i, data[i] );
				j=1;
			}
			else{
				printf("%d\t%s\n", i,data[i]);
				j=1;
			}
		else if( (i == count - 2) && (j == 0) )printf("未发现相关内容!\n");
}
