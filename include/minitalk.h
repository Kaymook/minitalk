/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:22:16 by mosh              #+#    #+#             */
/*   Updated: 2024/02/13 01:25:05 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

void	send_signal(int pid, char *str);
void	handler(int signal);

#endif
