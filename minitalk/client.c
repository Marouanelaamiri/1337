/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:49:23 by malaamir          #+#    #+#             */
/*   Updated: 2025/02/02 16:59:31 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// check if every character in the pid is a digit and ensure that the convertd pid is positive

int pid_check(char *pid_str)
{
	int i;
	int pid;

	i = 0;
	pid = 0;
	while (pid_str[i])
	{
		if (pid_str[i] < '0' || pid_str[i] > '9')
		{
			ft_putstr("Invalid PID\n");
			exit(1);
		}
		i++;
	}
	pid = ft_atoi(pid_str); // convert the string to an integer
	if (pid < 0)
	{
		ft_putstr("Invalid PID\n");
		exit(1);
	}
	return (pid);
}
void	ft_sending_sig(int pid, char holder)
{
	int sig;
	int bit;

	bit = 0;
	while(bit < CHAR_BIT)
	{
		// Decide which signal to send based on the bit value
		if (holder & (1 << bit))
			sig = SIGUSR1; // represents bit 1
		else
			sig = SIGUSR2; // represents bit 0
		// send the signal to the server
		if (kill(pid, sig) == -1) // returns -1 if the signal is not sent
		{
			ft_putstr("Error in sending signal\n");
			exit(1);
		}
		usleep(150); // wait for the server to process the signal 100 micro seconds
		bit++;
	}
}
int main(int ac, char **av)
{
	int pid;
	int i;

	i = 0;
	if (ac == 3 && av[2])
	{
		pid = pid_check(av[1]); // validate the pid
		if (pid != 0)
		{
			// send the string to the server character by character
			while (av[2][i])
			{
				ft_sending_sig(pid, av[2][i]);
				i++;
			}
			// send the null character to indicate the end of the string
			ft_sending_sig(pid, '\0');
		}
	}
	else
	{
		ft_putstr("Invalid arguments.\n");
		ft_putstr("\n");
	}
}
