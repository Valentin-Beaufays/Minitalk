/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:55:41 by valentin          #+#    #+#             */
/*   Updated: 2022/05/31 02:55:49 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf.h"

char	g_char;

void	sig_handler(int sig)
{
	static size_t	count;

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

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	g_char = 0;
	pid = getpid();
	ft_printf("%d\n", pid);
	sa.sa_handler = sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
