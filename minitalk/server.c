/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:49:10 by malaamir          #+#    #+#             */
/*   Updated: 2025/04/06 18:19:09 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	pid;
	static int	i_bit;
	static char	holder;

	(void)context;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		i_bit = 0;
		holder = 0;
	}
	if (sig == SIGUSR1)
		holder |= (1 << i_bit);
	i_bit++;
	if (i_bit == CHAR_BIT)
	{
		ft_putchar(holder);
		holder = 0;
		i_bit = 0;
		pid = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
