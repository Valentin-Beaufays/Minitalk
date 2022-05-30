#include <signal.h>
#include "ft_printf.h"

int send_converted(int pid, char **converted)
{
	size_t i;

	while(*converted)
	{
		i = 0;
		while(*(*converted + i))
		{
			usleep(100);
			if (*(*converted + i) == '0')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
		}
		converted++;
	}
	return (0);
}