/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 02:52:17 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/11 08:17:15 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	if (!str)
		return (0);
	if (*str == '+')
		++str;
	if (*str == '0')
	{
		ft_printf("Error\n");
		exit(1);
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (*str)
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (num);
}

int	signal_count(void (*signal))
{
	static int	i = 0;

	if ((int)signal == SIGUSR1)
		i++;
	return (i);
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

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		while (av[2][i] != '\0')
		{
			signal(SIGUSR1, (void *)&signal_count);
			signal(SIGUSR2, (void *)&signal_count);
			help(av[2][i], ft_atoi(av[1]));
			i++;
		}
		if (ft_strlen(av[2]) == signal_count((void *)signal))
			ft_printf("OK\n");
		else
			ft_printf("Error\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(1);
	}
}
