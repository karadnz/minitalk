/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:27:43 by mkaraden          #+#    #+#             */
/*   Updated: 2022/12/18 19:07:07 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_morse(int pid,int c)
{
	int	bit = 8;
	printf("%c",c);
	while(bit--)
	{
		if((c >> bit) & 1)
			kill(pid,SIGUSR1);
		else
			kill(pid,SIGUSR2);
		usleep(100);
		
		//printf("%d\n%d\n%d\n",bit,c,c >> bit);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int	pid = ft_atoi(argv[1]);
		char	*str = argv[2];
		while(*str)
		{
			ft_morse(pid,*str++);
		}
		
	}
	else
	{
		printf("invalid args");
	}
	return (0);
}


// if (kill(ft_atoi(argv[1]), SIGUSR1) == 0)
		// {
		// 	printf("SUCCESS\n");
		// }