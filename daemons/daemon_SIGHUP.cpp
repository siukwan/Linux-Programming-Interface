#include <sys/stat.h>
#include <signal.h>
#include "../lib/become_daemon.h"
#include "../lib/tlpi_hdr.h"

static const char *LOG_FILE = "/tmp/ds.log";
static const char *CONFIG_FILE = "/tmp/ds.conf";

static volatile sig_atomic_t hupReceived = 0;

static void
sighupHandler(int sig)
{
	hupReceived=1;
}

int
main(int argc,char *argv[])
{
	const int SLEEP_TIME = 15;  //time to sleep between messages
	int count = 0;              //number of completed SLEEP_TIME intervals
	int unslept;                //time remaining in sleep
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = sighupHandler;

	if(sigaction(SIGHUP,&sa,NULL) == -1)
		errExit("sigaction");

	if(becomeDaemon(0)==-1)
		errExit("becomeDaemon");

	logOpen(LOG_FILE);
	readConfigFile(CONFIG_FILE);

	unslept = SLEEP_TIME;

	while(1)
	{
		unslept = sleep(unslept);

		if(hupReceived)
		{
			logClose();
			logOpen(LOG_FILE);
			readConfigFile(CONFIG_FILE);
			hupReceived = 0;
		}

		if(unslept == 0)
		{
			count++;
			logMessage("Main:%d",count);
			unslept = SLEEP_TIME;
		}
	}
}
