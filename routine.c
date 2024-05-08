/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:54:57 by dboire            #+#    #+#             */
/*   Updated: 2024/05/08 16:19:30 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	eating(t_philo *philo)
{
	if(*philo->is_dead != 1)
		return ;
	pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	put_message("has taken a fork", philo);
	put_message("has taken a fork", philo);
	pthread_mutex_lock(philo->last_meal_check);
	philo->last_meal = get_current_time() - philo->start_time;
	put_message("is eating", philo);
	ft_usleep(philo->time_to_eat);
	if(*philo->is_dead != 1)
	{
		pthread_mutex_unlock(philo->last_meal_check);
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
}

void	sleeping(t_philo *philo)
{
	put_message("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	put_message("is thinking", philo);
}