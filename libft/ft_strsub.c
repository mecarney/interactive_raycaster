/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:25:59 by mcarney           #+#    #+#             */
/*   Updated: 2018/07/09 12:26:00 by mcarney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s && (sub = ft_strnew(len)))
	{
		i = 0;
		while (i < len)
		{
			sub[i] = s[start];
			i++;
			start++;
		}
		return (sub);
	}
	return (NULL);
}
