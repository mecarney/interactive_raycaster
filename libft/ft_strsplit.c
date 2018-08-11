/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:27:06 by mcarney           #+#    #+#             */
/*   Updated: 2018/07/09 12:27:08 by mcarney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_words(char const *s, char c)
{
	int			n;
	int			i;

	n = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c) && (i == 0 || s[i - 1] == c))
			n++;
		i++;
	}
	return (n);
}

static char		**actual_split(char **arr, int n, char const *s, char c)
{
	int			i;
	int			j;
	int			beg;
	char		*curr_word;

	i = 0;
	j = 0;
	beg = 0;
	while (j < n)
	{
		if ((s[i] != c) && (i == 0 || s[i - 1] == c))
			beg = i;
		if ((s[i] == c || !s[i]) && (i > 0 && s[i - 1] != c))
		{
			curr_word = ft_strsub(s, beg, i - beg);
			if (!curr_word)
				return (NULL);
			arr[j] = curr_word;
			j++;
		}
		i++;
	}
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	int			words;
	char		**arr_words;

	if (!s)
		return (NULL);
	words = num_words(s, c);
	arr_words = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr_words)
		return (NULL);
	arr_words[words] = 0;
	return (actual_split(arr_words, words, s, c));
}
