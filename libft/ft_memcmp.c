/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:11:46 by gbrittan          #+#    #+#             */
/*   Updated: 2020/11/03 14:38:35 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char *p1;
	const unsigned char *p2;

	p1 = (unsigned char *)str1;
	p2 = (unsigned char *)str2;
	while (n != 0)
	{
		if (*p1++ != *p2++)
			return (*--p1 - *--p2);
		n--;
	}
	return (0);
}
