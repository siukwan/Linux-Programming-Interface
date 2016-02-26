#include <time.h>
#include <poll.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
	int numPipes,j,ready,randPipe,numWrites;
	int (*pfds)[2];//数组指针，是一个指针，指向整个数组
	struct pollfd *pollFd;

	if(argc <2 || strcmp(argv[1],"--help") == 0)
		usageErr("%s num-pipes [num-writes]\n",argv[0]);

	numPipes =getInt(argv[1],GN_GT_0,"num-pipes");

	pfds = (int(*)[2])calloc(numPipes,sizeof(int [2]));//calloc是clear alloc，动态分配内存且清零

	if(pfds==NULL)
		errExit("malloc");

	pollFd = (pollfd*)calloc(numPipes, sizeof(struct pollfd));
	if(pollFd == NULL)
		errExit("malloc");

	for(j=0;j<numPipes;++j)
		if(pipe(pfds[j]) == -1 )
			errExit("pipe %d",j);

	numWrites = (argc > 2)?getInt(argv[2],GN_GT_0,"num-writes"):1;

	//srandom函数利用一个时间因子产生一个不同的队列给random函数调用，这样random函数每次运行就不会产生一样的伪随机输出
	srandom((int)time(NULL));

	for(j=0;j<numWrites;++j)
	{
		randPipe = random() % numPipes;//随即选取管道写入数据
		printf("Writing to fd: %3d (read fd: %3d)\n",pfds[randPipe][0]);

		if(write(pfds[randPipe][1],"a",1)==-1)
			errExit("write %d",pfds[randPipe][1]);
	}

	//build the file descriptor list to be supplied to poll()
	//This list is set to contain the file descriptors for the read ends of all of the pipes.
	for(j=0;j<numPipes;++j)
	{
		pollFd[j].fd = pfds[j][0];
		pollFd[j].events = POLLIN;//因为之前全清零了，直接赋值即可
	}
	ready = poll(pollFd, numPipes,-1);//非阻塞

	if(ready == -1)
		errExit("poll");

	printf("poll() returned: %d\n",ready);

	for(j=0;j<numPipes;++j)
		if(pollFd[j].revents & POLLIN)
			printf("Readable: %d %3d\n",j,pollFd[j].fd);

	exit(EXIT_SUCCESS);

}
