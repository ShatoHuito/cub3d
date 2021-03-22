/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:43:23 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 21:44:09 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*srch_wr(char *remains)
{
	int		i;
	char	*str;

	i = 0;
	while (remains != NULL && remains[i] != '\n' && remains[i])
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (remains != NULL && remains[i] != '\n' && remains[i])
	{
		str[i] = remains[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char		*cut_remains(char *remains)
{
	size_t	i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (remains[i] != '\n' && remains[i])
		i++;
	if (remains[i] == '\n')
		i++;
	if (!(str = malloc(sizeof(char) * (ft_strlen(remains) - i + 1))))
		return (NULL);
	while (remains[i] != '\0')
		str[j++] = remains[i++];
	str[j] = '\0';
	free(remains);
	return (str);
}

static int		free_if_error(char *remains, char *buf)
{
	if (remains != NULL)
		free(remains);
	if (buf != NULL)
		free(buf);
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*rmns;
	int			read_b;

	buf = malloc(sizeof(char) * (10 + 1));
	read_b = 1;
	if ((10 < 1) || !(buf) || !(line))
		return (free_if_error(rmns, buf));
	while (!(ft_strchr(rmns, '\n')) && (read_b = read(fd, buf, 10)))
	{
		if (read_b == -1)
			return (free_if_error(rmns, buf));
		buf[read_b] = '\0';
		if ((rmns = ft_strjoin_g(rmns, buf)) == NULL)
			return (free_if_error(rmns, buf));
	}
	free(buf);
	*line = srch_wr(rmns);
	if (*line == NULL || (rmns && !(rmns = cut_remains(rmns))))
		return (free_if_error(rmns, buf));
	if (read_b || ft_strlen(rmns))
		return (1);
	free(rmns);
	rmns = NULL;
	return (0);
}
