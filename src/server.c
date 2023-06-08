/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:42:11 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/08 16:49:15 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	function(int sig)
{
	static int	bit = 0;
	static int	i = 0;
	
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		i = 0;
		bit = 0;
	}
	
}

int main(int ac, char **av)
{
	int	pid;
	(void)av;
	
	if (ac == 1)
	{
		pid = getpid();
		ft_printf("pid == [%d]\n", pid);
		while (1)
		{
			signal(SIGUSR1, &function);
			signal(SIGUSR2, &function);
			pause();	
		}
	}
	return (0);
}