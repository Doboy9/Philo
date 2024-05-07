/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:43:35 by dboire            #+#    #+#             */
/*   Updated: 2024/05/07 17:31:40 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

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