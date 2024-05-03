/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:28:40 by wneel             #+#    #+#             */
/*   Updated: 2024/04/04 12:38:10 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		src_len;
	char	*new_src;
	int		i;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	new_src = malloc((src_len + 1) * sizeof(char));
	if (!new_src)
		return (0);
	i = 0;
	while (i < src_len)
	{
		new_src[i] = s[i];
		i++;
	}
	new_src[i] = '\0';
	return (new_src);
}
