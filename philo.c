/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:19:33 by dboire            #+#    #+#             */
/*   Updated: 2024/05/07 18:16:29 by dboire           ###   ########.fr       */
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
	philos = ft_calloc(3, sizeof(t_philo));
	init_prog(&prog, philos);
	ft_init_struct(&prog, philos, av);
	ft_philo(&prog);
	return (0);
}

void	ft_philo(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		pthread_create(&prog->philos[i].thread, NULL, ft_routine, (void *)&prog->philos[i]);
		i++;
	}
	i = 0;
		while (i < 3)
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
	while(is_he_dead != 1)
	{
		eating(philo);
		sleep();
		think();
	}
}