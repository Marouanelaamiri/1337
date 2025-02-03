/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:52:35 by malaamir          #+#    #+#             */
/*   Updated: 2025/02/03 12:10:32 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t ack_received = 0;

void ack_handler(int sig)
{
	(void)sig;
	ack_received = 1;
}
// Check if every character in the PID is a digit and ensure that the converted pid is positive.
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
            write(2, "Invalid PID\n", 12);
            exit(1);
        }
        i++;
    }
    pid = ft_atoi(pid_str); // Convert the string to an integer.
    if (pid < 0)
    {
        write(2, "Invalid PID\n", 12);
        exit(1);
    }
    return (pid);
}

void ft_sending_sig(int pid, char holder)
{
    int sig;
    int bit;

    bit = 0;
    while (bit < CHAR_BIT)
    {
        // Decide which signal to send based on the bit value.
        if (holder & (1 << bit))
            sig = SIGUSR1; // Represents bit 1.
        else
            sig = SIGUSR2; // Represents bit 0.
        // Send the signal to the server.
        if (kill(pid, sig) == -1) // Returns -1 if the signal is not sent.
        {
            write(2, "Error in sending signal\n", 25);
            exit(1);
        }
        // Wait a little between signals.
        usleep(100);
		usleep(90);
        bit++;
    }
}

int main(int ac, char **av)
{
    int pid;
    int i;
    char *message;  // Pointer to the allocated message on the heap.

    i = 0;
    if (ac == 3 && av[2])
    {
        pid = pid_check(av[1]); // Validate the PID.
        if (pid != 0)
        {
            // Allocate a copy of the message on the heap.
            // If you have your own ft_strdup, use that; otherwise, strdup from string.h.
            message = ft_strdup(av[2]); 
            // Alternatively, if you don't have ft_strdup:
            // message = strdup(av[2]);
            if (!message)
            {
                write(2, "Memory allocation error\n", 24);
                exit(1);
            }
            // Send the string to the server character by character.
			
			signal(SIGUSR1, ack_handler);
            while (message[i])
            {
                ft_sending_sig(pid, message[i]);
                i++;
            }
            // Send the null character to indicate the end of the string.
            ft_sending_sig(pid, '\0');
			while (!ack_received)
				pause();
			ft_putstr("Message acknowledged by the server.\n");
            free(message); // Free the allocated memory.
        }
    }
    else
    {
        write(2, "Invalid arguments.\n", 19);
        ft_putstr("\n");
    }
    return (0);
}