/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:07:01 by mosh              #+#    #+#             */
/*   Updated: 2024/02/11 15:47:47 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_handler = &b_server_signal;
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 3)
	{
		ft_printf("You must provide 2 parameters: <PID> & <message>.\n");
		ft_printf("Please try again\n\n");
	}
	else
		b_send_signal(ft_atoi(argv[1]), argv[2]);
	return (0);
}
