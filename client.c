/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 05:33:29 by kmoshker          #+#    #+#             */
/*   Updated: 2023/11/21 07:30:03 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>

char	to_send_char(int pid, char c)
{
	
}

char	to_send_string(int pid, char *string)
{
	
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*string_to_be_sent;
	SIGINFO
	if (argc != 3)
	{
		printf("error ditected, please try again\n");
		return (1);
	}
	server_pid = atoi(*argv[1]);
	string_to_be_sent = *argv[2];
	if (kill(server_pid, SIGUSR1) == -1)
	{
		printf("Error PID is incorrect");
		return (1);
	}
	to_send_string(server_pid, string_to_be_sent);
	return (0);
}