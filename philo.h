/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:19:49 by dboire            #+#    #+#             */
/*   Updated: 2024/05/09 17:26:31 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <sys/time.h>
# include <pthread.h>
# include "libft/libft.h"

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				philo_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				start_time;
	int				last_meal;
	int				meals;
	int				meals_eaten;
	int				*is_dead;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*he_dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*write;
	pthread_mutex_t	*last_meal_check;
}	t_philo;


typedef struct s_prog
{
	int				is_dead;
	pthread_mutex_t	write;
	pthread_mutex_t	dead;
	pthread_mutex_t	he_dead;
	pthread_mutex_t	last_meal_check;
	t_philo			*philos;
}	t_prog;

size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);
void	eating(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);

void	*ft_monitoring(void *observer);
int		full_belly(t_philo *philo);

int		is_he_dead(t_philo *philo);
void	put_message(char *msg, t_philo *philo);

void	init_prog(t_prog *prog, t_philo *philos);
void	ft_init_struct(t_prog *prog, t_philo *philos, char **av);
int		ft_parse_av(char **av);

void	ft_philo(t_prog *prog);
void	*ft_routine(void *Philos);


#endif