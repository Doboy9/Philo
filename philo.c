/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:19:33 by dboire            #+#    #+#             */
/*   Updated: 2024/05/09 18:46:53 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	main(int ac, char **av) // Pas le droit a la libft
{
	int	i;
	t_prog	prog;
	t_philo	*philos;

	i = 0;
	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd("Arguments must be between 4 and 5\n", 1);
		return (1);
	}
	if(ft_parse_av(av) == 1)
		return (1);
	philos = ft_calloc(ft_atoi(av[1]), sizeof(t_philo));
	init_prog(&prog, philos);
	ft_init_struct(&prog, philos, av);
	ft_philo(&prog);
	return (0);
}

void	ft_philo(t_prog *prog)
{
	int	i;
	int	philos_nb;
	pthread_t	monitor;

	i = 0;
	philos_nb = prog->philos[0].philo_nb;
	pthread_create(&monitor, NULL, ft_monitoring, (void *)prog);
	while (i < philos_nb)
	{
		pthread_create(&prog->philos[i].thread, NULL, ft_routine, (void *)&prog->philos[i]);
		i++;
	}
	i = 0;
	pthread_join(monitor, NULL);
	while (i < philos_nb)
	{
		pthread_join(prog->philos[i].thread, NULL);
		i++;
	}
	return ;
}

void	*ft_routine(void *Philos)
{
	t_philo *philo;
	
	philo = (t_philo *)Philos;
	while(1)
	{
		pthread_mutex_lock(philo->last_meal_check);
		eating(philo);
		pthread_mutex_unlock(philo->last_meal_check);
		// pthread_mutex_lock(philo->last_meal_check);
		sleeping(philo);
		// pthread_mutex_unlock(philo->last_meal_check);
		// pthread_mutex_lock(philo->last_meal_check);
		thinking(philo);
		// pthread_mutex_unlock(philo->last_meal_check);
	}
	return NULL;
}