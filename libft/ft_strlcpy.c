/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:52:07 by gbrittan          #+#    #+#             */
/*   Updated: 2020/11/07 16:31:43 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t f;

	if (dest == 0 || src == 0)
		return (0);
	f = 0;
	if (len == 0)
		return (ft_strlen(src));
	while (src[f] && f + 1 < len)
	{
		dest[f] = src[f];
		f++;
	}
	dest[f] = '\0';
	return (ft_strlen(src));
}
