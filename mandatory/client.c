/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:11:58 by mosh              #+#    #+#             */
/*   Updated: 2024/02/07 23:48:22 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void send_signal(int pid, char *str)
{
	int i;
	int c;

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
			usleep(100);
			i++;
		}
		str++;
	}
	 for (int i = 0; i < 8; ++i)
    {
        kill(pid, SIGUSR1);
        usleep(100);
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("\nYou must provide 2 parameters: <PID> & <message>.\n");
		ft_printf("Please try again.\n");
		return (1);
	}
	if (ft_atoi(argv[1]) == 0)
	{
		ft_printf("\nPID Error\n");
		return(1);
	}
	else
		send_signal(ft_atoi(argv[1]), argv[2]);
	return (0);
}

