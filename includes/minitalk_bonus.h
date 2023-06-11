/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 03:23:55 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/11 08:13:58 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <ft_printf.h>

void	function(int sig);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		signal_count(void (*signal));
void	sighandler(int sig, siginfo_t *info, void *data);

#endif