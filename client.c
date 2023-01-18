/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:50 by rnaka             #+#    #+#             */
/*   Updated: 2023/01/18 22:10:36 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(int pid, char c)
{
	int	n;
	int	er;

	n = 7;
	while (n >= 0)
	{
		er = 0;
		if (!(c & 1 << n))
			er = kill((pid_t)pid, SIGUSR1);
		else
			er = kill((pid_t)pid, SIGUSR2);
		n--;
		usleep(2000);
		if (er == -1)
		{
			write(0, "error", 5);
			exit(1);
		}
	}
}

static void	send_mes(int pid, char *mes)
{
	int	n;

	n = 0;
	while (mes[n] != '\0')
	{
		send_char(pid, mes[n]);
		n++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (argc > 3 || argc <= 0)
	{
		write(0, "error\n", 6);
		exit(1);
	}
	if (kill(pid, 0) == -1 || pid > 4194304 || pid <= 0)
	{
		write(0, "error::Please check pid.\n", 26);
		exit(1);
	}
	send_mes(pid, argv[2]);
	return (0);
}
