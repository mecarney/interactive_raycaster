/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:27:17 by mcarney           #+#    #+#             */
/*   Updated: 2018/07/09 12:27:18 by mcarney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa(int n)
{
	size_t			len;
	unsigned int	nbr;
	char			*arr;
	size_t			sign;

	len = 1;
	nbr = n;
	if (n < 0)
	{
		len++;
		nbr = n * -1;
		sign = 1;
	}
	while (n /= 10)
		len++;
	if (!(arr = ft_strnew(len)))
		return (NULL);
	if (sign == 1)
		arr[0] = '-';
	arr[--len] = nbr % 10 + '0';
	while (nbr /= 10)
		arr[--len] = nbr % 10 + '0';
	return (arr);
}
