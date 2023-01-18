/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:54 by rnaka             #+#    #+#             */
/*   Updated: 2023/01/18 22:25:12 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_ch;

static void	w0(int non)
{
	if (non == SIGUSR1)
		g_ch *= 2;
	else if (non == SIGUSR2)
	{
		g_ch *= 2;
		g_ch += 1;
	}
}

static void	sig_write(void)
{
	int	cou;

	cou = 0;
	g_ch = 0;
	signal(SIGUSR1, w0);
	signal(SIGUSR2, w0);
	while (1)
	{
		pause();
		cou++;
		if (cou == 8)
		{
			cou = 0;
			write(0, &g_ch, 1);
			g_ch = 0;
		}
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd((int)pid, 0);
	write(0, "\n", 1);
	sig_write();
	return (0);
}
