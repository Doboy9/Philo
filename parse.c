/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:43:35 by dboire            #+#    #+#             */
/*   Updated: 2024/05/07 15:14:19 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	ft_init_struct(t_prog *prog, char **av)
{
	int	i;

	i = 0;
	while(i < 3)
	{
		prog->philos = ft_calloc(3, sizeof(t_prog **));
		i++;
	}
	i = 0;
	while(i < 3)
	{
		prog->philos[i] = malloc(sizeof(t_philo *));
		pthread_mutex_init(&prog->write, NULL);
		i++;
	}
	i = 0;
	while(i < 3)
	{
		prog->philos[i]->id = i;
		prog->philos[i]->eating = 0;
		prog->philos[i]->philo_nb = 3;
		prog->philos[i]->time_to_die = 500;
		prog->philos[i]->time_to_eat = 100;
		prog->philos[i]->time_to_sleep = 100;
		if(av[5])
			prog->philos[i]->meals = 10;
		else
			prog->philos[i]->meals = -1;
		prog->philos[i]->start_time = 0;
		prog->philos[i]->last_meal = 0;
		prog->philos[i]->dead = 0;
		prog->philos[i]->write = &prog->write;
		prog->philos[i]->dead = &prog->dead;
		pthread_mutex_init(&prog->philos[i]->l_fork, NULL);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		prog->philos[i]->r_fork = &prog->philos[(i + 2) % 3]->l_fork;
		i++;
	}
}

int	ft_parse_av(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ft_atoi(av[1]) > 200)
	{
		ft_putstr_fd("200 philosphers maximum\n", 1);
		return (1);
	}
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				ft_putstr_fd("Numeric arguments required\n", 1);
				return (1);
			}
			else
				j++;
		}
		i++;
	}
	return (0);
}
