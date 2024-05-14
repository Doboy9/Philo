/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:14:55 by dboire            #+#    #+#             */
/*   Updated: 2024/05/14 15:00:35 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	put_message(char *msg, t_philo *philo)
{
	int	time;

	pthread_mutex_lock(philo->write);
	time = get_current_time() - philo->start_time;
	if (check_if_dead(philo) == 1)
	{
		pthread_mutex_unlock(philo->write);
		return ;
	}
	if (check_if_dead(philo) != 1)
		printf("%d %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->write);
}
