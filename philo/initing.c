/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:40:15 by malaamir          #+#    #+#             */
/*   Updated: 2025/03/05 23:36:18 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_input(t_philo *philo, char **av)
{
	philo->philo_nums = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->num_of_eat = ft_atoi(av[5]);
	else
		philo->num_of_eat = -1;
	
}
void init_sim(t_sim *sim, t_philo *philo)
{
	sim->dead_flag = 0;
	sim->philos = philo;
	pthread_mutex_init(&sim->dead_lock, NULL);
	pthread_mutex_init(&sim->meal_lock, NULL);
	pthread_mutex_init(&sim->print_lock, NULL);
}
void init_forks(pthread_mutex_t *forks, t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->philo_nums)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
void init_philos(t_philo *philos, t_sim *sim, pthread_mutex_t *forks, char **av)
{
	int i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_input(&philos[i], av);
		philos[i].start_timer = get_time(); // to do
		philos[i].last_meal = get_time();
		philos[i].print_lock = &sim->print_lock;
		philos[i].death_lock = &sim->dead_lock;
		philos[i].meal_lock = &sim->meal_lock;
		philos[i].death = &sim->dead_flag;
		philos[i].left_fork = &forks[i];

		if (i == 0)
			philos[i].right_fork = &forks[philos[i].philo_nums - 1];
		else
			philos[i].right_fork = &forks[i - 1];
	}
}
int init_waiter(t_sim *sim, pthread_mutex_t *forks)
{
	pthread_t observer;
	int i;

	i = 0;
	if (pthread_create(&observer, NULL, &waiter, sim->philos) != 0) // to do
		destroy_all("Error\n", sim, forks);
	while (i < sim->philos[0].philo_nums)
	{
		if (pthread_create(&sim->philos[i].thread, NULL, &routine, // to do
				&sim->philos[i]) != 0)
			destroy_all("Error\n", sim, forks);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		destroy_all("Error\n", sim, forks);
	while (i < sim->philos[0].philo_nums)
	{
		if (pthread_join(sim->philos[i].thread, NULL) != 0)
			destroy_all("Error\n", sim, forks);
		i++;
	}
	return (0);
}