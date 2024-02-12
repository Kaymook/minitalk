/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:03:52 by mosh              #+#    #+#             */
/*   Updated: 2024/02/12 17:51:39 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int main(int argc, char **argv)
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_printf("\nYou must provide 2 parameters: <PID> & <message>.\n");
		ft_printf("Please try again.\n");
		return (1);
	}
	if (pid == -1 || (pid >= 0 && 6 >= pid))
	{
		ft_printf("\nPID Error\n");
		return(1);
	}
	else
		send_signal(pid, argv[2]);
	return (0);
}

