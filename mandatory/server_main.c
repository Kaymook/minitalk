/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:05:17 by mosh              #+#    #+#             */
/*   Updated: 2024/02/13 00:57:04 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(void)
{
	struct sigaction	s_sigaction;

	s_sigaction.sa_flags = 0;
	s_sigaction.sa_handler = &handler;
	if (sigaction(SIGUSR1, &s_sigaction, NULL) == -1
		|| sigaction(SIGUSR2, &s_sigaction, NULL) == -1)
	{
		ft_printf("error");
		return (1);
	}
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	ft_printf("PID | %d\n", getpid());
	while (1)
		pause();
	return (0);
}
