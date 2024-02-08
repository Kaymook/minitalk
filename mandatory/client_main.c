/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:03:52 by mosh              #+#    #+#             */
/*   Updated: 2024/02/08 19:04:05 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

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

