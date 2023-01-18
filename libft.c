/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:56:26 by rnaka             #+#    #+#             */
/*   Updated: 2023/01/18 22:12:59 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*base;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	base = "0123456789";
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	write(fd, &base[n % 10], 1);
}

static int	check_over_long(int sign, unsigned long num, char c)
{
	if (sign == 1 && (LONG_MAX / 10 < num || (LONG_MAX / 10 == num && LONG_MAX
				% 10 < c - '0')))
		return (1);
	if (sign == -1 && (LONG_MAX / 10 < num || (LONG_MAX / 10 == num && LONG_MAX
				% 10 + 1 < c - '0')))
		return (-1);
	return (0);
}

int	ft_atoi(const char *s)
{
	size_t			i;
	int				sign;
	long			result;
	unsigned long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\v' || s[i] == '\f' \
				|| s[i] == '\r' || s[i] == ' ')
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (ft_isdigit(s[i]))
	{
		if (check_over_long(sign, num, s[i]) == 1)
			return ((int)LONG_MAX);
		if (check_over_long(sign, num, s[i]) == -1)
			return ((int)LONG_MIN);
		num = num * 10 + s[i++] - '0';
	}
	result = num * sign;
	return (result);
}

int	ft_isdigit(int a)
{
	if (('0' <= a) && (a <= '9'))
		return (1);
	return (0);
}
