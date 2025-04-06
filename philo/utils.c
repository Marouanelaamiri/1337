/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:56:45 by malaamir          #+#    #+#             */
/*   Updated: 2025/04/06 12:30:28 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	if (*philo->death == 1)
		return (pthread_mutex_unlock(philo->death_lock), 1);
	pthread_mutex_unlock(philo->death_lock);
	return (0);
}

void	send_msg(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->print_lock);
	time = get_time() - philo->start_timer;
	if (!check_dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->print_lock);
}

void	destroy_all(char *str, t_sim *sim, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&sim->print_lock);
	pthread_mutex_destroy(&sim->meal_lock);
	pthread_mutex_destroy(&sim->death_lock);
	while (i < sim->philos[0].philo_nums)
		pthread_mutex_destroy(&forks[i++]);
}

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "Error gettimeofday()\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_pause(t_philo *philo, size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
	{
		if (check_dead_loop(philo))
			return (1);
	}
	return (0);
}
