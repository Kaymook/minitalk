/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:03:52 by mosh              #+#    #+#             */
/*   Updated: 2024/02/13 01:20:36 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_printf("\nYou must provide 2 parameters: <PID> & <message>.\n");
		ft_printf("Please try again.\n");
		return (1);
	}
	if (pid < 0 || (pid >= 0 && 2 >= pid))
	{
		ft_printf("\nPID Error\n");
		return (1);
	}
	else
		send_signal(pid, argv[2]);
	return (0);
}
