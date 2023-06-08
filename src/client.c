/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:42:19 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/08 16:48:35 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	if (!str)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

void	help(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);	
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		while(av[2][i] != '\0')
		{
			help(av[2][i], ft_atoi(av[1]));
			i++;
		}
	}
}