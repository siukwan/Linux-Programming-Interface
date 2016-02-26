#include <signal.h>
#include <ctype.h>
#include <fcntl.h>
#include <termios.h>
#include "tty_functions.h"
#include "tlpi_hdr.h"

static volatile sig_atomic_t gotSigio = 0;

static void
sigioHandler(int sig)
{
	gotSigio = 1;
}

int
main(int argc, char *argv[])
{
	int flags, j,cnt;
	struct termios origTermios;
	char ch;
	struct sigaction sa;
	bool done;

	//Establish handler for "I/O possible" signal
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = sigioHandler;
	if(sigaction(SIGIO,&sa,NULL) == -1)
		errExit("sigaction");

	//Set owner process that is to receive "I/O possible" signal
	//设置属主
	if(fcntl(STDIN_FILENO,F_SETOWN,getpid()) == -1)
		errExit("fcntl(F_SETOWN)");

	//Enable "I/O possible" signaling and make I/O nonblocking for file descriptor
	flags = fcntl(STDIN_FILENO, F_GETFL);
	if(fcntl(STDIN_FILENO,F_SETFL,flags|O_ASYNC|O_NONBLOCK) == -1)
		errExit("fcntl(F_SETFL)");

	//Place terminal in cbreak mode
	if(ttySetCbreak(STDIN_FILENO,&origTermios)==-1)
		errExit("ttySetCbreak");

	for(done = FALSE,cnt=0;!done;cnt++)
	{
		for(j=0;j<100000000;++j)
			continue;

		if(gotSigio)
		{

			while(read(STDIN_FILENO,&ch,1)>0 && !done)
			{
				printf("cnt=%d; read %c\n",cnt,ch);
				done = ch == '#';
			}
			gotSigio = 0;
		}
	}

	if(tcsetattr(STDIN_FILENO,TCSAFLUSH,&origTermios) == -1)
		errExit("tcsetattr");
	exit(EXIT_SUCCESS);
}
