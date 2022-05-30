#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void handler(int sig)
{
	printf("%d\n", sig);
}

void exit_end(int sig)
{
	(void)sig;
	printf("\n");
	exit(EXIT_SUCCESS);
}

int	main()
{
	pid_t pid;
	struct sigaction sa;
	struct sigaction end;

	sa.sa_handler = handler;
	end.sa_handler = exit_end;
	pid = getpid();
	printf("%d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &end, NULL);
	while(1)
		sleep(3000);
	return (EXIT_SUCCESS);
}