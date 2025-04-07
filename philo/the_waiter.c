/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_waiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:56:33 by malaamir          #+#    #+#             */
/*   Updated: 2025/04/06 16:47:28 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_time() - philo->last_meal >= time_to_die && philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	check_if_any_died(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].philo_nums)
	{
		if (check_death(&philo[i], philo[i].time_to_die))
		{
			send_msg("died", &philo[i], philo[i].id);
			pthread_mutex_lock(philo[0].death_lock);
			*philo->death = 1;
			pthread_mutex_unlock(philo[0].death_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_all_ate(t_philo *philos)
{
	int	i;
	int	finish;

	i = 0;
	finish = 0;
	if (philos[0].num_of_eat == -1)
		return (0);
	while (i < philos[0].philo_nums)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_of_eat)
			finish++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (finish == philos[0].philo_nums)
	{
		pthread_mutex_lock(philos[0].death_lock);
		*philos->death = 1;
		pthread_mutex_unlock(philos[0].death_lock);
		return (1);
	}
	return (0);
}

void	*waiter(void *ptr)
{
	t_philo	*philos;

	if (!ptr)
		return (NULL);
	philos = (t_philo *)ptr;
	while (1)
	{
		if (check_if_any_died(philos) == 1 || check_if_all_ate(philos) == 1)
			break ;
	}
	return (ptr);
}
