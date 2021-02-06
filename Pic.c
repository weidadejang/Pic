/*
 ============================================================================
 Name        : Pic.c
 Author      : Dking
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "bmpRD.h"


#define w 200
#define h 200

void WriteBMP(char*img,const char* filename)
{
    int l=(w*3+3)/4*4;
    int bmi[]= {l*h+54,0,54,40,w,h,1|3*8<<16,0,l*h,0,0,100,0};
    FILE *fp = fopen(filename,"wb");
    fprintf(fp,"BM");
    fwrite(&bmi,52,1,fp);
    fwrite(img,1,l*h,fp);
    fclose(fp);
}


int main(int argc, char **argv)
{
	int i = 0;
	char j = 0;
	char str[50] = "pic";
    char img[w*h*3];
	struct timeval tv;

	gettimeofday(&tv, NULL);
	printf("second: %ld \n", tv.tv_sec); // 秒
	printf("millisecond: %ld \n", tv.tv_sec * 1000 + tv.tv_usec / 1000); // 毫秒

	clLoadImage(argv[1]);
	/*
    for(j = 0;j<100;j++)
    {
    	sprintf(str+3, "%d.png", j);
		for(i=0; i<w*h*3; i++)
		{
			img[i]=rand()%256;
		}
		//printf("%s\n",str);
		WriteBMP(img,str);
    }
    */
	gettimeofday(&tv, NULL);
	printf("second: %ld \n", tv.tv_sec); // 秒
	printf("millisecond: %ld \n", tv.tv_sec * 1000 + tv.tv_usec / 1000); // 毫秒

    //system("test.bmp");
    return 0;
}
