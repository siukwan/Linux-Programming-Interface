#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <iostream>

using namespace std;
int char2int(char*c)
{
	int result=0;
	while(*c!=0)
	{
		result=result*10+*c-'0';
		c++;
	}
	return result;
}

int
main(int argc, char *argv[])
{
	int time[3]={7,1,4};
	setbuf(stdout,NULL);
	if(argc!=4)
	{
		printf("Usage:./multi_wait child1WaitSecond child2WaitSecond child3WaitSecond\n");
		printf("For an example: ./multi_wait 7 1 4\n");
		printf("now will run as above\n");
	}
	else
	{
		printf("%s %s %s\n",argv[1],argv[2],argv[3]);
		time[0]=char2int(argv[1]);
		time[1]=char2int(argv[2]);
		time[2]=char2int(argv[3]);
	}

	for(int i=0;i<3;++i)
	{
		if(fork()==0)
		{//儿子进程
			printf("%d child started!\n",i);
			sleep(time[i]);
			_exit(EXIT_SUCCESS);
		}
	}

	int deadChildCount=0;
	while(1)
	{
		pid_t childPid=wait(NULL);
		if(childPid == -1)
		{
			if(errno == ECHILD)
			{
				printf("no more child\n");
				exit(EXIT_SUCCESS);
			}
		}

		deadChildCount++;
		printf("%d child wait() returned child PID %ld\n",deadChildCount,(long long)childPid);
	}
}
