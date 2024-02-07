/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:16:37 by mosh              #+#    #+#             */
/*   Updated: 2024/02/07 23:16:44 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	handler(int signal, siginfo_t *sig_info, void *context)
{
	static int	i;
	static char	c;

	(void)context;
	if (signal == SIGUSR2)
		c += (1 << i);
	i++;
	if (i == 8)
	{
		if (c == '\0')
			kill(sig_info->si_pid, SIGUSR2);
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID | %d\n", getpid());
	while (1)
		pause();
}
