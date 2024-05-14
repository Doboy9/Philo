/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:53:08 by dboire            #+#    #+#             */
/*   Updated: 2024/05/14 15:23:16 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_static_is_char_whitespace(char c)
{
	return ((c > 7 && c < 14) || (c == 32));
}

long int	ft_atoi(const char *nptr)
{
	int			sign;
	long int	number;
	int			i;

	i = 0;
	number = 0;
	sign = 1;
	while (nptr[i] != '\0')
	{
		while (ft_static_is_char_whitespace(nptr[i]))
			i++;
		if ((nptr[i] == 43) || (nptr[i] == 45))
		{
			if (nptr[i] == 45)
				sign *= -1;
			i++;
		}
		while (nptr[i] > 47 && nptr[i] < 58)
		{
			number = number * 10 + (nptr[i] - '0');
			i++;
		}
		return (number * sign);
	}
	return (0);
}
