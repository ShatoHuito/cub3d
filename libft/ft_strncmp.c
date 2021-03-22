/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:23:17 by gbrittan          #+#    #+#             */
/*   Updated: 2020/11/07 17:14:31 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a;

	a = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[a] == (unsigned char)s2[a]
			&& s1[a] && s2[a] && a < n - 1)
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
