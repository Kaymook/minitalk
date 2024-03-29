/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:11:58 by mosh              #+#    #+#             */
/*   Updated: 2024/02/12 21:19:35 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_signal(int pid, char *str)
{
	int	i;
	int	c;

	while (*str)
	{
		c = *str;
		i = 0;
		while (i < 8)
		{
			if (1 & (c >> i))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(300);
			i++;
		}
		str++;
	}
}
