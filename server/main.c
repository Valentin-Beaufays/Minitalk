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

int	main()
{
	pid_t pid;
	struct sigaction sa;
	
	g_char = 0;
	pid = getpid();
	printf("%d\n", pid);
	sa.sa_handler = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return (EXIT_SUCCESS);
}