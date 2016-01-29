/*
 * 一个交互式加锁程序
 * */
#include <sys/stat.h>
#include <fcntl.h>
#include "../lib/tlpi_hdr.h"

#define MAX_LINE 100

static void
displayCmdFmt(void)
{
	printf("\n Format:cmd lock start length [whence]\n\n");
	printf("   'cmd' is 'g'(GETLK), 's'(SETLK),or 'w'(SETLKW)\n");
	printf("   'lock' is 'r'(READ), 'w'(WRITE), or 'u'(UNLOCK)\n");
	printf("   'start' and 'length' specify byte range to lock\n");
	printf("   'whence' is 's' (SEEK_SET,default), 'c'(SEEK_CUR),"
		   "or 'e'(SEEK_END)\n\n");
}
int
main(int argc,char *argv[])
{
	int fd,numRead,cmd,status;
	char lock,cmdCh,whence,line[MAX_LINE];
	struct flock fl;
	long long len, st;

	if(argc!=2||strcmp(argv[1],"--help")==0)
		usageErr("%s file\n",argv[0]);

	fd = open(argv[1],O_RDWR);
	if(fd == -1)
		errExit("open (%s)",argv[1]);

	printf("Enter ? for help\n");

	while(1)
	{
		printf("PID=%ld>",(long)getpid());
		fflush(stdout);//刷新缓冲区

		if(fgets(line,MAX_LINE,stdin)==NULL)//EOF
			exit(EXIT_SUCCESS);
		line[strlen(line)-1]=='\0';//把换行\n改成结束符\0

		if(*line == '\0')//跳过空白行
			continue;
	}

	exit(EXIT_SUCCESS);
}
