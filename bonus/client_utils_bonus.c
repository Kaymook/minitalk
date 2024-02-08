/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:16:27 by mosh              #+#    #+#             */
/*   Updated: 2024/02/08 19:40:31 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	b_send_signal(int pid, char *str)
{
	int		i;
	int		c;
	char	*final;

	final = str + ft_strlen(str);
	while (str <= final)
	{
		c = *str;
		i = 0;
		while (i < 8)
		{
			if (1 & (c >> i))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			i++;
		}
		str++;
	}
}

void	b_server_signal(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("\nMESSAGE RECEIVED\n\n");
}
