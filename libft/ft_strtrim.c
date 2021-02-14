/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:20:43 by gbrittan          #+#    #+#             */
/*   Updated: 2020/11/22 16:57:45 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static char	*ret_onechar(char *str)
{
	str = (char *)malloc(1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	int			end;
	int			j;
	char		*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	str = NULL;
	i = 0;
	j = 0;
	end = ft_strlen(s1) - 1;
	while (check_set(s1[i], set) == 0)
		i++;
	while (check_set(s1[end], set) == 0 && end > 0)
		end--;
	if (i >= end)
		return (ret_onechar(str));
	str = (char *)malloc(end - i + 2);
	if (str == NULL)
		return (NULL);
	while (i <= end)
		str[j++] = s1[i++];
	str[j++] = '\0';
	return (str);
}
