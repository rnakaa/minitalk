/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:57:25 by rnaka             #+#    #+#             */
/*   Updated: 2023/01/17 13:32:29 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include <limits.h>

void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *s);
int		ft_isdigit(int a);
#endif