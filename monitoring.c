/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:05:10 by dboire            #+#    #+#             */
/*   Updated: 2024/05/09 18:43:40 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*ft_monitoring(void *observer)
{
	t_prog *prog;
	
	prog = (t_prog*)observer;
	while(1)
	{
		pthread_mutex_lock(&prog->dead);
		if(is_he_dead(prog->philos) == 1 || full_belly(prog->philos) == 1)
		{
			prog->is_dead = 1;
			pthread_mutex_unlock(&prog->dead);
			return NULL;
		}
		pthread_mutex_unlock(&prog->dead);
	}
	return NULL;
}

int	full_belly(t_philo *philo)
{
	int	i;
	
	i = 0;
	pthread_mutex_lock(philo->last_meal_check);
	if(philo->meals_eaten == philo->meals)
	{
		pthread_mutex_unlock(philo->last_meal_check);
		return (1);
	}
	pthread_mutex_unlock(philo->last_meal_check);
	return (0);
}