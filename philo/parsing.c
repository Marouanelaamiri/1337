/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:25:10 by malaamir          #+#    #+#             */
/*   Updated: 2025/03/05 23:22:32 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_args(char *args)
{
	while (*args)
	{
		if (!(*args >= '0' && *args <= '9'))
			return (1);
		args++;
	}
	return (0);
}
int check_deadlock_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	if (*philo->death == 1)
		return (pthread_mutex_unlock(philo->death_lock), 1);
	pthread_mutex_unlock(philo->death_lock);
	return (0);
}
int check_valid_args(char **av)
{
	if (ft_atoi(av[1]) > PHILO_MAX || ft_atoi(av[1]) <= 0
	|| check_args(av[1]) == 1)
		return (write(2, "Error: Invalid number of philosophers\n", 38), 1);
	if (ft_atoi(av[2]) <= 0 || check_args(av[2]) == 1)
		return (write(2, "Error: Invalid time to die\n", 27), 1);
	if (ft_atoi(av[3]) <= 0 || check_args(av[3]) == 1)
		return (write(2, "Error: Invalid time to eat\n", 28), 1);
	if (ft_atoi(av[4]) <= 0 || check_args(av[4]) == 1)
		return (write(2, "Error: Invalid time to sleep\n", 30), 1);
	if (av[5] && (ft_atoi(av[5]) <= 0 || check_args(av[5]) == 1))
		return (write(2, "Error: Invalid number of meals\n", 32), 1);
	return (0);
}