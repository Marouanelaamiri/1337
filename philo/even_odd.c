/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_odd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:19:17 by malaamir          #+#    #+#             */
/*   Updated: 2025/04/09 16:26:14 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	even_odd(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		send_msg("has taken a fork", philo, philo->id);
		pthread_mutex_lock(philo->right_fork);
		send_msg("has taken a fork", philo, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		send_msg("has taken a fork", philo, philo->id);
		pthread_mutex_lock(philo->left_fork);
		send_msg("has taken a fork", philo, philo->id);
	}
}
