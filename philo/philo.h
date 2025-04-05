/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:01:16 by malaamir          #+#    #+#             */
/*   Updated: 2025/04/05 16:10:17 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

# define PHILO_MAX 200

typedef struct s_philo
{
	int				id;
	int				eating;
	int				meals_eaten;
	int				philo_nums;
	int				num_of_eat;
	int				*death;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_timer;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*death_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

typedef struct s_sim
{
	int				dead_flag;
	t_philo			*philos;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	print_lock;
}	t_sim;

int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
void	init_input(t_philo *philo, char **av);
void	init_mutex(t_sim *sim, t_philo *philo);
void	init_forks(pthread_mutex_t *forks, int philos);
void	init_philos(t_philo *philos, t_sim *sim,
			pthread_mutex_t *forks, char **av);
int		init_threads(t_sim *sim, pthread_mutex_t *forks);
int		check_dead_loop(t_philo *philo);
int		check_valid_args(char **av);
int		check_valid_num(char *str);
void	*routine(void *ptr);
void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);
int		check_death(t_philo *philo, size_t time_to_die);
int		check_if_any_died(t_philo *philo);
int		check_if_all_ate(t_philo *philos);
void	*waiter(void *ptr);
void	send_msg(char *str, t_philo *philo, int id);
void	destroy_all(char *str, t_sim *program, pthread_mutex_t *forks);
size_t	get_time(void);
int		ft_pause(t_philo *philo, size_t milliseconds);

#endif
