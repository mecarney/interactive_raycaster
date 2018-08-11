/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:15:45 by mcarney           #+#    #+#             */
/*   Updated: 2018/07/09 12:15:46 by mcarney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src2;
	char	*dst2;
	size_t	i;

	src2 = (char *)src;
	dst2 = (char *)dst;
	i = 0;
	if (src2 < dst2)
		while ((int)(--len) >= 0)
			dst2[len] = src2[len];
	else
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	return (dst);
}
