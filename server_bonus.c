/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:27:47 by mkaraden          #+#    #+#             */
/*   Updated: 2022/12/20 17:45:11 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_server_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit = 7;
	static int	c = 0;

	(void)context;
	if (signum == SIGUSR1)
	{
		c += 1 << bit;
	}
	else if (signum == SIGUSR2)
	{
		c += 0 << bit;
	}
	bit--;
	if (bit == -1)
	{
		write(1, &c, 1);
		bit = 7;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = ft_server_handler;
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);
	ft_itoa(getpid());
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sigact, NULL);
		sigaction(SIGUSR2, &sigact, NULL);
		pause();
	}
}
