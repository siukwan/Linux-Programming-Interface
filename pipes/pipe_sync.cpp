#include "../lib/curr_time.h"
#include "../lib/tlpi_hdr.h"

int
main(int argc,char *argv[])
{
	int pfd[2];
	int j,dummy;

	if(argc<2 || strcmp(argv[1],"--help") == 0)
		usageErr("%s sleep-time...\n",argv[0]);

	setbuf(stdout,NULL); //设置标准输出不使用缓冲，因为我们使用_exit()来终止child进程

	printf("%s Parent started\n",currTime("%T"));

	if(pipe(pfd) == -1)
		errExit("pipe");

	for(j = 1;j<argc;j++)
	{
		switch(fork())
		{
		case -1:
			errExit("fork %d",j);

		case 0://子进程
			if(close(pfd[0]) == -1)
				errExit("close");

			//Child does some work,and lets parent know it's done
			sleep(getInt(argv[j],GN_NONNEG,"sleep-time"));

			printf("%s Child %d (PID=%ld) closing pipe\n",currTime("%T"),j,(long)getpid());

			if(close(pfd[1])==-1)
				errExit("close");

			//child now carries on to do other things...
			_exit(EXIT_SUCCESS);

		default:
			break;
		}
	}

	//Parent comes here
	if(close(pfd[1])==-1)
		errExit("close");

	//Parent may do other work, then synchronizes with children

	if(read(pfd[0],&dummy,1)!=0)
		fatal("parent didn't get EOF");
	printf("%s Parent ready to go\n",currTime("%T"));

	//parent can now carry on to do other things...
	exit(EXIT_SUCCESS);
}
