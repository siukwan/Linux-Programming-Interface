/*
 * 修改进程环境
 * */
#define _FNU_SOURCWE
#include <stdlib.h>
#include "../lib/tlpi_hdr.h"

extern char **environ;
int
main(int argc,char *argv[])
{
	int j;
	char **ep;

	clearenv();//清除全部的环境变量

	for(j=1;j<argc;++j)
	{
		if(putenv(argv[j])!=0)
			errExit("putenv: %s",argv[j]);
	}

	if(setenv("GREET","Hello world",0) == -1)
		errExit("setenv");

	unsetenv("BYE");

	for(ep = environ; *ep !=NULL;ep++)
		puts(*ep);

	exit(EXIT_SUCCESS);

}
