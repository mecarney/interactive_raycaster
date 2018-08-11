/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:49:49 by mcarney           #+#    #+#             */
/*   Updated: 2018/07/20 11:54:45 by mcarney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		define_line(char **line, char **rtext, int fd)
{
	int			len;
	char		*tmp;

	len = 0;
	while (rtext[fd][len] != '\0' && rtext[fd][len] != '\n')
		len++;
	if (rtext[fd][len] == '\n')
	{
		*line = ft_strsub(rtext[fd], 0, len);
		tmp = ft_strdup((char *)rtext[fd] + len + 1);
		free(rtext[fd]);
		rtext[fd] = tmp;
		if (!rtext[fd][0])
			ft_strdel(&rtext[fd]);
	}
	else
	{
		*line = ft_strdup(rtext[fd]);
		ft_strdel(&rtext[fd]);
	}
	return (1);
}

int				ft_get_next_line(const int fd, char **line)
{
	static char	*rtext[10];
	int			rb;
	char		*tmp;
	char		buff[BUFF_SIZE + 1];

	while ((rb = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rb] = '\0';
		if (!(rtext[fd]))
			rtext[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(rtext[fd], buff);
			free(rtext[fd]);
			rtext[fd] = tmp;
		}
		if (ft_strchr(rtext[fd], '\n'))
			break ;
	}
	if (rb < 0 || fd < 0)
		return (-1);
	if (rb == 0 && !rtext[fd])
		return (0);
	return (define_line(line, rtext, fd));
}
