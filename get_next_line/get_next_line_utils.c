/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:43:40 by gbrittan          #+#    #+#             */
/*   Updated: 2020/12/06 16:43:42 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t a;

	if (str == NULL)
		return (0);
	a = 0;
	while (*str++)
		a++;
	return (a);
}

char		*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == c)
		return ((char*)s);
	return (NULL);
}

char		*ft_strjoin_g(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		f;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	f = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str != NULL)
	{
		if (s1 != NULL)
			while (s1[i])
				str[f++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			str[f++] = s2[i++];
		str[f] = '\0';
		free((char*)s1);
		return (str);
	}
	else
		return (NULL);
}
