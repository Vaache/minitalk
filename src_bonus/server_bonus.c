/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 03:59:05 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/11 08:19:09 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sighandler(int sig, siginfo_t *info, void *data)
{
	static int	bit = 0;
	static int	i = 0;

	(void)data;
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		kill(info->si_pid, SIGUSR1);
		i = 0;
		bit = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	(void)av;
	sa.sa_sigaction = sighandler;
	if (ac == 1)
	{
		pid = getpid();
		ft_printf("pid == [%d]\n", pid);
		while (1)
		{
			sigaction(SIGUSR1, &sa, NULL);
			sigaction(SIGUSR2, &sa, NULL);
			pause();
		}
	}
	else
	{
		ft_printf("Error\n");
		exit(1);
	}
}
