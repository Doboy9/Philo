/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:19:33 by dboire            #+#    #+#             */
/*   Updated: 2024/05/03 17:36:24 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	main(int ac, char **av)
{
	int	i;
	t_philo *philo;

	i = 0;
	philo = ft_calloc(1, sizeof(t_philo *));
	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd("Arguments must be between 4 and 5\n", 1);
		return (1);
	}
	if(ft_parse_av(av) == 1)
		return (1);
	ft_init_struct(philo, av);
	return (0);
}

void	ft_init_struct(t_philo *philo, char **av)
{
	philo->philo_nb = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if(av[5])
		philo->meals = ft_atoi(av[5]);
}

int	ft_parse_av(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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