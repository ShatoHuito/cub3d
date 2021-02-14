/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:55:04 by gbrittan          #+#    #+#             */
/*   Updated: 2020/11/22 16:30:50 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_count(char const *s, int c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*split_str(char const *s, int i, int s_len)
{
	char	*str;
	int		ifl;
	int		j;

	j = 0;
	ifl = i - s_len;
	str = (char *)malloc(s_len + 1);
	if (str == NULL)
		return (NULL);
	while (ifl != i)
		str[j++] = s[ifl++];
	str[j] = '\0';
	return (str);
}

static void	free_all(char ***str, int a)
{
	while (a > 0)
	{
		a--;
		free((*str)[a]);
	}
	free(*str);
	*str = NULL;
}

static int	get_i(char const *s, char c)
{
	int i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		s_len;
	int		j;

	i = get_i(s, c);
	j = 0;
	if (s == NULL || !(str = (char **)malloc(sizeof(char*)
					* (get_count(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		s_len = 0;
		while (s[i] != c && s[i] != '\0')
			++s_len && ++i;
		str[j] = split_str(s, i, s_len);
		if (str[j++] == NULL)
			free_all(&str, j - 1);
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	str[j] = NULL;
	return (str);
}
