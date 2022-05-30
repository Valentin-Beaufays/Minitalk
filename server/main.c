#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
char g_char;

void handler(int sig)
{
	static size_t count;

	g_char *= 2;
	if (sig == SIGUSR2)
		g_char += 1;
	count++;
	if (count == 8)
	{
		write(1, &g_char, 1);
		count = 0;
	}
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
	
	g_char = 0;
	pid = getpid();
	printf("%d\n", pid);
	sa.sa_handler = handler;
	end.sa_handler = exit_end;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &end, NULL);
	while(1)
		pause();
	return (EXIT_SUCCESS);
}