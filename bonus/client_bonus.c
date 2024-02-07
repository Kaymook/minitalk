/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:16:27 by mosh              #+#    #+#             */
/*   Updated: 2024/02/07 23:16:28 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	send_signal(int pid, char *str)
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

void	server_signal(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("\nMESSAGE RECEIVED\n\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_handler = &server_signal;
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 3)
	{
		ft_printf("You must provide 2 parameters: <PID> & <message>.\n");
		ft_printf("Please try agian\n\n");
	}
	else
		send_signal(ft_atoi(argv[1]), argv[2]);
	return (0);
}
