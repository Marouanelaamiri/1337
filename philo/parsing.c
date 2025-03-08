/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:25:10 by malaamir          #+#    #+#             */
/*   Updated: 2025/03/08 20:40:06 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	if (*philo->death == 1)
		return (pthread_mutex_unlock(philo->death_lock), 1);
	pthread_mutex_unlock(philo->death_lock);
	return (0);
}
int check_valid_num(char *str)
{
	if (!str || !*str)
		return (1);
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (1);
	while (*str >= '0' && *str <= '9')
		str++;
	while (*str == ' ')
		str++;
	if (*str)
		return (1);
	return (0);
}
int check_valid_args(char **av)
{
	// int philo_count;

	// philo_count = ft_atoi(av[1]);
	if (ft_atoi(av[1]) > PHILO_MAX || ft_atoi(av[1]) <= 0
	|| check_valid_num(av[1]) == 1)
		return (write(2, "Error: Invalid number of philosophers\n", 38), 1);
	// if (philo_count == 1)
		// return (write(2, "Error: Invalid number of philosophers\n", 38), 1);
	if (ft_atoi(av[2]) <= 0 || check_valid_num(av[2]) == 1)
		return (write(2, "Error: Invalid time to die\n", 27), 1);
	if (ft_atoi(av[3]) <= 0 || check_valid_num(av[3]) == 1)
		return (write(2, "Error: Invalid time to eat\n", 28), 1);
	if (ft_atoi(av[3]) < 60)
		return (write(2, "Error: Time to eat must be at least 60ms\n", 41), 1);
	if (ft_atoi(av[4]) <= 0 || check_valid_num(av[4]) == 1)
		return (write(2, "Error: Invalid time to sleep\n", 30), 1);
	if (ft_atoi(av[4]) < 60)
		return (write(2, "Error: Time to sleep must be at least 60ms\n", 43), 1);
	if (av[5] && (ft_atoi(av[5]) <= 0 || check_valid_num(av[5]) == 1))
		return (write(2, "Error: Invalid number of meals\n", 32), 1);
	return (0);
}