/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:49:23 by malaamir          #+#    #+#             */
/*   Updated: 2025/04/06 16:12:30 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	pid_check(char *pid_str)
{
	int	i;
	int	pid;

	i = 0;
	pid = 0;
	while (pid_str[i])
	{
		if (pid_str[i] < '0' || pid_str[i] > '9')
		{
			write(2, "Invalid PID\n", 12);
			exit(1);
		}
		i++;
	}
	pid = ft_atoi(pid_str);
	if (pid < 0)
	{
		write(2, "Invalid PID\n", 12);
		exit(1);
	}
	return (pid);
}

void	ft_sending_sig(int pid, char holder)
{
	int	sig;
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (holder & (1 << bit))
			sig = SIGUSR1;
		else
			sig = SIGUSR2;
		if (kill(pid, sig) == -1)
		{
			write(2, "Error in sending signal\n", 25);
			exit(1);
		}
		usleep(110);
		usleep(90);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*message;

	i = 0;
	if (ac == 3 && av[2])
	{
		pid = pid_check(av[1]);
		if (pid)
		{
			message = ft_strdup(av[2]);
			if (!message)
				display_error(message);
			while (message[i])
				ft_sending_sig(pid, message[i++]);
			ft_sending_sig(pid, '\0');
			free(message);
		}
	}
	else
		write(2, "Invalid arguments.\n", 19);
	return (0);
}
