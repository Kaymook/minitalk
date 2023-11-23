/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:13:01 by kmoshker          #+#    #+#             */
/*   Updated: 2023/11/21 06:13:19 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>

void bit_to_str(int pid, struct __siginfo * c, void *a)
{
	(void) a;


}

int	main ()
{
	int	pid;
	struct sigaction	sa;

	pid = getpid();
	printf("Server PID: %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = bit_to_str;
}