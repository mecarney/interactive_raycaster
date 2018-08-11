/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:19:51 by mcarney           #+#    #+#             */
/*   Updated: 2018/07/09 12:19:52 by mcarney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	h;
	size_t	s2_len;

	if (s2[0] == '\0')
		return ((char *)s1);
	h = 0;
	s2_len = ft_strlen(s2);
	while (s1[h])
	{
		if (ft_strncmp((char *)s1 + h, s2, s2_len) == 0)
			return ((char *)s1 + h);
		h++;
	}
	return (NULL);
}
