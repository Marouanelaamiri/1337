/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:52:46 by malaamir          #+#    #+#             */
/*   Updated: 2025/02/05 12:56:49 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset_variables(int *pid, int *i_bit, char *holder, int *buffer_index)
{
	*pid = 0;
	*i_bit = 0;
	*holder = 0;
	*buffer_index = 0;
}

void	print_buffer(char *buffer, int *buffer_index, int pid)
{
	int	i;

	i = 0;
	while (i < *buffer_index)
	{
		ft_putchar(buffer[i]);
		i++;
	}
	if (buffer[*buffer_index - 1] == '\0')
	{
		kill(pid, SIGUSR1);
	}
	*buffer_index = 0;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	pid;
	static int	i_bit;
	static char	holder;
	static char	buffer[4] = {0};
	static int	buffer_index;

	(void)context;
	if (pid != info->si_pid)
		reset_variables(&pid, &i_bit, &holder, &buffer_index);
	pid = info->si_pid;
	if (sig == SIGUSR1)
		holder |= (1 << i_bit);
	i_bit++;
	if (i_bit == CHAR_BIT)
	{
		buffer[buffer_index++] = holder;
		holder = 0;
		i_bit = 0;
		if (buffer_index == 4 || buffer[buffer_index - 1] == '\0')
			print_buffer(buffer, &buffer_index, pid);
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
