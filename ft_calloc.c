/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:53:00 by dboire            #+#    #+#             */
/*   Updated: 2024/05/14 14:53:26 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;
	long int		allocated_size;

	allocated_size = size * nmemb;
	if (allocated_size < 0 || ((int) size < 0 && (int) nmemb < 0))
		return (0);
	tab = malloc(allocated_size);
	if (!tab)
		return (0);
	ft_bzero(tab, allocated_size);
	return ((void *)tab);
}
