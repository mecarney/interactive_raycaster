/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:15:14 by mcarney           #+#    #+#             */
/*   Updated: 2018/07/09 12:15:20 by mcarney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*src2;
	char	*dst2;
	size_t	i;

	dst2 = dst;
	src2 = (char *)src;
	i = 0;
	while (i < n)
	{
		*(dst2 + i) = *(src2 + i);
		i++;
	}
	return (dst);
}
