/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:57:25 by rnaka             #+#    #+#             */
/*   Updated: 2023/01/18 22:15:49 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define LIBFT_H
# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include<limits.h>
# include<libc.h>

void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *s);
int		ft_isdigit(int a);
#endif