/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:43:35 by dboire            #+#    #+#             */
/*   Updated: 2024/05/14 15:23:06 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parse_av(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ft_check_atoi(av) == 1)
		return (1);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
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

int	ft_check_atoi(char **av)
{
	int	i;

	i = 0;
	if (ft_atoi(av[1]) > 200)
	{
		ft_putstr_fd("200 philosphers maximum\n", 1);
		return (1);
	}
	while (av[i + 1])
	{
		if (ft_atoi(av[i]) > 2147483647)
		{
			ft_putstr_fd("NOT IN RANGE OF INT MAX OR INT MIN\n", 1);
			return (1);
		}
		i++;
	}
	return (0);
}
