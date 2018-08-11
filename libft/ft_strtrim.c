/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:26:14 by mcarney           #+#    #+#             */
/*   Updated: 2018/07/09 12:26:56 by mcarney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] <= ' ' && s[i] != '\0')
		i++;
	start = i;
	while (s[i] != '\0')
		i++;
	while (s[i] <= ' ' && i > start)
		i--;
	end = i;
	if (!(new = ft_strsub(s, start, end - start + 1)))
		return (NULL);
	new[end - start + 1] = '\0';
	return (new);
}
