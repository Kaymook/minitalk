/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:06:59 by mosh              #+#    #+#             */
/*   Updated: 2024/02/08 19:40:38 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

void	b_send_signal(int pid, char *str);
void	b_server_signal(int signal);
void	b_handler(int signal, siginfo_t *sig_info, void *context);

# endif