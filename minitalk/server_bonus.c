/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:52:46 by malaamir          #+#    #+#             */
/*   Updated: 2025/02/03 11:59:52 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int sig, siginfo_t *info, void *context)
{
	static int pid; // stores the pid of the client
	static int i_bit; // count the bits received
	static char holder; // accumulate the bits to build the char

	(void)context; // unused so we cast it to void

	// check if the signal is from the same client , if not reset everything
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		i_bit = 0;
		holder = 0;
	}

	// check if the signal is SIGUSR1 or SIGUSR2 and build the chars bit by bit
	if (sig == SIGUSR1)
		holder |= (1 << i_bit);
	i_bit++;

	// when a full char has been received
	if (i_bit == CHAR_BIT)
	{
		ft_putchar(holder); // print it
		if (holder == '\0')
		{
			ft_putchar('\n'); // print a new line if the char is null
			 if (kill(info->si_pid, SIGUSR1) == -1)
                write(2, "Error sending ACK\n", 18);
			pid = 0;
		}
		// reset everything
		holder = 0;
		i_bit = 0;
	}

}
int main()
{
	struct sigaction	sa;
	int					pid;

	pid = getpid(); // retrieve the current process id (system call wrapper)
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');

	// configure the sigaction struct
	sa.sa_sigaction = handler;// set our costum signal handler
	sa.sa_flags = SA_SIGINFO;// use the sa_sigaction field

	// set the signal handler for SIGUSR1 and SIGUSR2
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	// infinite loop to keep the server running and waiting for signals
	while (1)
		pause(); // suspend the process until a signal is received
	return (0);
}