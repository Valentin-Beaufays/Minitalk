#include <signal.h>
#include "ft_printf.h"

int send_converted(int pid, char **converted)
{
	(void)pid;
	(void)converted;
	kill(pid, SIGUSR2);
	return (0);
}