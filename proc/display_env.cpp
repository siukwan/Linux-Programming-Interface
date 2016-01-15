/*
 * 现实进程环境变量
 * */
#include "../lib/tlpi_hdr.h"

//这是一个全剧变量，只需要extern声明即可
extern char **environ;

int
main(int argc,char *argv[])
{
	char **ep;
	for(ep = environ; *ep != NULL; ep++)
		puts(*ep);
	exit(EXIT_SUCCESS);

}
