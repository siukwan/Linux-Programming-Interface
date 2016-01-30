/*
 * 在父进程和子进程间使用管道通信
 * */
#include <sys/wait.h>
#include "../lib/tlpi_hdr.h"

#define BUF_SIZE 10
int
main(int argc,char *argv[])
{
	int pfd[2];//pipe descriptors，管道描述符

	char buf[BUF_SIZE];
	ssize_t numRead;

	if(argc !=2 || strcmp(argv[1],"--help")==0)
		usageErr("%s string\n",argv[0]);

	if(pipe(pfd) == -1)//创建管道
		errExit("pipe");

	switch(fork())
	{
	case -1:
		errExit("fork");

	case 0:
		if(close(pfd[1]== -1))//关闭管道的写入端
			errExit("close - child");
		while(1)
		{
			numRead = read(pfd[0],buf,BUF_SIZE);
			if(numRead == -1)
				errExit("read");
			if(numRead == 0)
				break;
			if(write(STDOUT_FILENO,buf,numRead)!=numRead)
				fatal("child - partial/failed write");
		}

		write(STDOUT_FILENO,"\n",1);
		if(close(pfd[0])==-1)
				errExit("close");
		_exit(EXIT_SUCCESS);

	default://父进程
		if(close(pfd[0])== -1)//关闭读端
			errExit("close - parent");
		if(write(pfd[1],argv[1],strlen(argv[1]))!=strlen(agv[1]))
			fatal("parent - partial/failed write");

		if(close(pfd[1])==-1)
			errExit("close");
		wait(NULL);//等待孩子进程结束
		exit(EXIT_SUCCESS);
	}

}
