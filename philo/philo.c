/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:41:31 by malaamir          #+#    #+#             */
/*   Updated: 2025/03/08 21:11:08 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_sim sim;
    t_philo philos[PHILO_MAX];
    pthread_mutex_t forks[PHILO_MAX];

    if (ac != 5 && ac != 6)
        return (write(2, "Invalid input\n", 15), 1);
    if (check_valid_args(av) == 1)
        return (1);

    init_sim(&sim, philos);
    init_forks(forks, ft_atoi(av[1]));
    init_philos(philos, &sim, forks, av);
    init_waiter(&sim, forks);
    destroy_all(NULL, &sim, forks);
    return(0);
}

