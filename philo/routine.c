/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:35:31 by malaamir          #+#    #+#             */
/*   Updated: 2025/03/05 23:55:28 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_think(t_philo *philo)
{
	send_msg("Is thinking 🤔...", philo, philo->id); // to do
}
void ft_sleep(t_philo *philo)
{
	send_msg("Is a sleep 😴 ...", philo, philo->id);
	ft_pause(philo->time_to_sleep);
}
void ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	send_msg("Has taken a fork 🍴", philo, philo->id);
	if(philo->philo_nums == 1)
	{
		ft_pause(philo->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	send_msg("Ha taken a fork 🍴", philo, philo->id);
	philo->eating = 1;
	send_msg("Is eating 😋 ...", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time(); // to do
	philo->meals_eaten++;
	pthrea_mutex_unlock(philo->meal_lock);
	ft_pause(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
void *routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_pause(1); // to do
	while(!check_deadlock_loop(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (ptr);
}