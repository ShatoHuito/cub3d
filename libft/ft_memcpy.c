/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:34:17 by gbrittan          #+#    #+#             */
/*   Updated: 2020/11/04 19:52:56 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	if (!dest && !src)
		return (NULL);
	str1 = (unsigned char*)dest;
	str2 = (unsigned char*)src;
	while (n--)
		*(str1++) = *(str2++);
	return (dest);
}
