/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:54:57 by dboire            #+#    #+#             */
/*   Updated: 2024/05/07 18:16:26 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	put_message("has taken a fork", philo);
	pthread_mutex_lock(philo->r_fork);
	put_message("has taken a fork", philo);
	pthread_mutex_lock(philo->last_meal_check);
	philo->last_meal = get_current_time();
	put_message("is eating", philo);
}