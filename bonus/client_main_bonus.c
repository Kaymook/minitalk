/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:07:01 by mosh              #+#    #+#             */
/*   Updated: 2024/02/13 01:26:40 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	pid = ft_atoi(argv[1]);
	sa.sa_handler = &b_server_signal;
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 3)
	{
		ft_printf("You must provide 2 parameters: <PID> & <message>.\n");
		ft_printf("Please try again\n\n");
		return (1);
	}
	if (pid < 0 || (pid >= 0 && 2 >= pid))
	{
		ft_printf("\nPID Error\n");
		return (1);
	}
	else
		b_send_signal(pid, argv[2]);
	return (0);
}
