/********************************************************************************** 
 The SJF is written by analyzing ezTAG program, which was written by Jaewook Cheong,
 SEC S/W Centor. 
 Special thanks to Jaewook Cheong and Dale Roberts(the author of GIVEIO.sys)

 In SJF, the following feature is updated from ezTAG
 1. The structure of JTAG functions is changed for speed-up.
 2. The indexs of the pins become coherent with the BSDL file.
 3. SAMPLE/PRELOAD is used for initializing outCellValue[].
 4. The array size error is fixed(S3C2410_MAX_CELLS -> S3C2410_MAX_CELL_INDEX+2)
 5. The array was not followed by '\0', which is fixed.
 6. JTAG_ID reading error is fixed.
 7. Support K9S1208 SMD card for the SMDK2410 board.
 8. The programming speed is enhanced.
 **********************************************************************************/
/*******************************************
 Revision history
 2008.02.23 : 2440 nand flash Linux version
              by asmcos
 2002.06.10:purnnamu:ver 0.1
  -first release
 2002.06.21:purnnamu:ver 0.11
  -trivial display error is fixed.
 *******************************************/

#ifndef __linux__
#include <windows.h>
#include <conio.h>
#endif
#include <stdio.h>
#include "def.h"
#include "pin2440.h"
#include "jtag.h"
#include "ppt.h"
#include "k9s1208.h"

FILE *stream;
U32 imageSize;
U32 flashType=0;

U16 smc_type;

void OpenImageFile(char *filename);
void OpenPpt(void);

void ErrorBanner(void);

int main(int argc,char *argv[])
{
	char num=0;
    	
	printf("\n");
	printf("+------------------------------------+\n");
	printf("|     SEC JTAG FLASH(SJF) v 0.11     +\n");
	printf("|     modified by asmcos 2008.2.23     +\n");
	printf("+------------------------------------+\n");
	
	if(argc<3)
	    ErrorBanner();
	
	if(argv[2][1]=='t')
	    flashType=atoi(&argv[2][3]);
	else
	    ErrorBanner();

	if(argc==3)
	    delayLoopCount=100;
	else if(argv[3][1]=='d')
	    delayLoopCount=atoi(&argv[3][3]);
	else ErrorBanner();

	printf("> flashType=%d\n",flashType,delayLoopCount);
	
	OpenPpt();
	
	OpenImageFile(argv[1]);
	
	JTAG_ReadId();

	S2410_InitCell();
	
	switch(flashType)
	{
	case 1:  //K9S3208 4MB
	case 2:  //K9S6408 8MB
	case 3:  //K9S2808 16MB
	case 4:  //K95608 32MB
	case 5:  //K9S1208 64MB
	    smc_type = flashType - 1;
	    K9S1208_Menu();
	    break;	
	default:
	    break;
	}
}



void OpenImageFile(char *filename)
{
    U32 fileEnd,fileStart;
    stream = fopen(filename,"rb");
    if(stream==NULL)
    {
	printf("\nERROR:can't find the file.\n");
	exit(0);
    }

    fseek(stream,0L,SEEK_END);
    fileEnd=ftell(stream);
    fseek(stream,0L,SEEK_SET);
    fileStart=ftell(stream);

    imageSize=fileEnd-fileStart;  /*fileend == peof+1 */
}


int LoadImageFile(U8 *buf,int size)
{
    int i,readSize=size;
    for(i=0;i<size;i++)
    {
	if(feof(stream))
	{
	    readSize=i;
	    for(;i<size;i++)buf[i]=0;
	    break;
	}
	buf[i] = fgetc(stream);
    }
    return readSize;
}


void OpenPpt(void)
{
#ifndef __linux__	
    if(!InstallGiveIo())
    {
        printf("ERROR: Couldn't open giveio.sys\n");
        exit(0);
    }
#endif
    validPpt = GetValidPpt();
    if(!validPpt)
    {
	printf("ERROR: Unable to find a parallel port\n");
	exit(0);
    }
    SetPptCompMode();
}


void ErrorBanner(void)
{
    printf("Usage: SJF <filename> /t=<flash_type> /d=<delay>\n");
    printf("Flash Type List\n");
    printf("  1:SMDK2440:K9S3208 4MB\n");
    printf("  2:SMDK2440:K9S6408 8MB\n");
    printf("  3:SMDK2440:K9S2808 16MB\n");
    printf("  4:SMDK2440:K9S5608 32MB\n");
    printf("  5:SMDK2440:K9S1208 64MB\n");
    printf("  6:SMDK2440:AM29LV800BB\n");
    
    exit(0);
}
