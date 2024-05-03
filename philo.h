/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:19:49 by dboire            #+#    #+#             */
/*   Updated: 2024/05/03 17:27:52 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include "libft/libft.h"

typedef struct s_philo
{
	int	philo_nb;
	int	time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	int	meals;
}	t_philo;

void	ft_init_struct(t_philo *philo, char **av);
int	ft_parse_av(char **av);

#endif