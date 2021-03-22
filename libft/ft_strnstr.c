/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:48:21 by gbrittan          #+#    #+#             */
/*   Updated: 2020/11/03 19:03:03 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *fstr, const char *nstr, size_t len)
{
	size_t p1;
	size_t p2;

	if (*nstr == '\0')
		return ((char*)fstr);
	p1 = 0;
	while (fstr[p1] != '\0' && p1 < len)
	{
		if (fstr[p1] == nstr[0])
		{
			p2 = 1;
			while (nstr[p2] != '\0' && p1 + p2 < len
					&& fstr[p1 + p2] == nstr[p2])
				p2++;
			if (nstr[p2] == '\0')
				return ((char*)&fstr[p1]);
		}
		p1++;
	}
	return (NULL);
}
