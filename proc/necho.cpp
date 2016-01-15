/*
 * 回显命令行参数
 * */
#include "../lib/tlpi_hdr.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int
main(int argc,char *argv[])
{
	int j;
	for(j =0 ; j<argc;j++)
		printf("argv[%d] = %s\n",j,argv[j]);

	exit(EXIT_SUCCESS);

}
