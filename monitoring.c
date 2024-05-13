/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:05:10 by dboire            #+#    #+#             */
/*   Updated: 2024/05/13 11:19:54 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*ft_monitoring(void *observer)
{
	t_prog *prog;
	
	prog = (t_prog*)observer;
	while(1)
	{	
		if(is_he_dead(prog->philos) == 1 || full_belly(prog->philos) == 1)
			return NULL;
	}
	return NULL;
}

int	full_belly(t_philo *philo)
{
	int	i;
	
	i = 0;
	if(philo->meals_eaten == philo->meals)
		return (1);
	return (0);
}

int	check_if_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead);
	if (*philo->is_dead == 1)
	{
		pthread_mutex_unlock(philo->dead);
		return (1);
	}
	pthread_mutex_unlock(philo->dead);
	return (0);
}

int	is_he_dead(t_philo *philo)
{
	int	i;
	int	philo_nb;

	i = 0;
	philo_nb = philo[0].philo_nb;
	while(i < philo_nb)
	{
		if(ate_in_time(philo[i]) == 1)
		{
			put_message("died", philo);
			pthread_mutex_lock(philo->dead);
			*philo->is_dead = 1;
			pthread_mutex_unlock(philo->dead);
			return(1);
		}
		i++;
	}
	return(0);
}

int	ate_in_time(t_philo philo)
{
	int	time;
	
	time = 0;
	pthread_mutex_lock(philo.last_meal_check);
	time = get_current_time() - philo.start_time;
	if(time - philo.last_meal >= philo.time_to_die)
	{
		pthread_mutex_unlock(philo.last_meal_check);
		return (1);
	}
	pthread_mutex_unlock(philo.last_meal_check);
	return(0);
}