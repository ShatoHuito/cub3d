/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:42:35 by gbrittan          #+#    #+#             */
/*   Updated: 2020/11/20 15:34:05 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		f;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	f = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str != NULL)
	{
        if(s1 != NULL)
            while (s1[i] != '\0')
                str[f++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			str[f++] = s2[i++];
		str[f++] = '\0';
		return (str);
	}
	else
		return (NULL);
}
