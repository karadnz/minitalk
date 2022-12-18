/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:27:47 by mkaraden          #+#    #+#             */
/*   Updated: 2022/12/18 19:06:38 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void my_handler(int signum)
{
	static int bit = 7; //bit to shift
	static int i = 0; //iter
	static int c = 0; //char to print
	int bitValue = 0; //insert
    if (signum == SIGUSR1)
    {
        //printf("Received 1!\n");
		bitValue = 1;

    }
	else if (signum == SIGUSR2)
    {
        //printf("Received 0!\n");
		bitValue = 0;
    }
	c += bitValue << bit;
	i++;
	bit --;
	//printf("%d\n",i);
	//printf("%d\n",(i == 8));
	if (i == 8)
	{
		
		write(1,&c,1);
		bit = 7;
		i = 0;
		c = 0;
	}
}

int main()
{
	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	printf("%d \n", getpid());
	
		
	while(1)
	{
		pause();
	}
	
	

	return (0);
}