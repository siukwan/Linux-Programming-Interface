/*
 * 为SIGINT信号安装一个处理器程序
 * */
#include <signal.h>
#include "../lib/tlpi_hdr.h"

static void
sigHandler(int sig)
{
	printf("Ouch!\n");
}
int
main(int argc,char *argv[])
{
	int j;
	//设置信号SIGINT的处理函数为sigHandler
	if(signal(SIGINT,sigHandler)==SIG_ERR)
		errExit("signal");

	//死循环
	for(j=0;;j++)
	{
		printf("%d\n",j);
		sleep(3);
	}
}
