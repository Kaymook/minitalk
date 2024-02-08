/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:09:54 by mosh              #+#    #+#             */
/*   Updated: 2024/02/08 19:39:28 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	b_handler(int signal, siginfo_t *sig_info, void *context)
{
	static int	i;
	static char	c;

	(void)context;
	if (signal == SIGUSR2)
		c += (1 << i);
	i++;
	if (i == 8)
	{
		if (c == '\0')
			kill(sig_info->si_pid, SIGUSR2);
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}