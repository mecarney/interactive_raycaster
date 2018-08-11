/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:16:01 by mcarney           #+#    #+#             */
/*   Updated: 2018/07/09 12:16:03 by mcarney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr;
	size_t		i;

	ptr = (char const *)s;
	i = 0;
	while (i < n)
	{
		if (*(ptr + i) == (char)c)
			return ((void *)ptr + i);
		i++;
	}
	return (NULL);
}
