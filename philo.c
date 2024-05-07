/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:19:33 by dboire            #+#    #+#             */
/*   Updated: 2024/05/07 15:19:29 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	main(int ac, char **av) // Pas le droit a la libft
{
	int	i;
	t_prog	*prog;

	i = 0;
	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd("Arguments must be between 4 and 5\n", 1);
		return (1);
	}
	if(ft_parse_av(av) == 1)
		return (1);
	prog = ft_calloc(1, sizeof(t_prog *));
	pthread_mutex_init(&prog->write, NULL);
	pthread_mutex_init(&prog->dead, NULL);
	ft_init_struct(prog, av);
	ft_philo(prog);
	return (0);
}

void	ft_philo(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		pthread_create(&prog->philos[i]->thread, NULL, ft_eating, (void *)&prog->philos[i]);
		i++;
	}
	return ;
}

void	*ft_eating(void *Philos)
{
	int	i;

	i = 0;
	t_philo philos = (t_philo)Philos;
	
	printf("Philo %d is eating\n", philos->id);
	usleep(philos->time_to_eat);
	printf("Philo %d is done eating\n", philos->id);
	printf("Philo %d is thinking\n", philos->id);
	usleep (500);
	return(0);
}