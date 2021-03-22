/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:59:55 by gbrittan          #+#    #+#             */
/*   Updated: 2020/11/04 17:09:25 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*str1;
	const char		*str2;

	if (!dst && !src)
		return (NULL);
	str1 = dst;
	str2 = src;
	while (n--)
	{
		*str1++ = *str2++;
		if (*(str1 - 1) == (char)c)
			return (str1);
	}
	return (NULL);
}
