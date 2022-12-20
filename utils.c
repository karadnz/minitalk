/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:08:47 by mkaraden          #+#    #+#             */
/*   Updated: 2022/12/20 17:08:47 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isspace(int c)
{
	unsigned char	ch;

	ch = c;
	if (ch == '\f' || ch == '\n' || ch == ' ')
		return (1);
	if (ch == '\v' || ch == '\t' || ch == '\r')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	rt;
	int	sign;
	int	i;

	rt = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		rt = (rt * 10) + (str[i] - '0');
		i++;
	}
	return (rt * sign);
}

void	ft_itoa(int num)
{
	char	c;

	if (num >= 10)
		ft_itoa(num / 10);
	c = (num % 10) + 48;
	write(1, &c, 1);
}
