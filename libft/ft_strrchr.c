/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:55:02 by gbrittan          #+#    #+#             */
/*   Updated: 2020/11/20 15:37:17 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t a;

	a = ft_strlen(s) + 1;
	while (a--)
	{
		if (*(s + a) == (char)c)
			return ((char*)s + a);
	}
	return (NULL);
}
