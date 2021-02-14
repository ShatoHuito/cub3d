/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:51:51 by gbrittan          #+#    #+#             */
/*   Updated: 2020/11/05 14:21:30 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *p;

	p = (char *)malloc(ft_strlen(s1) + 1);
	if (p != NULL)
	{
		ft_strcpy(p, s1);
		return (p);
	}
	else
		return (NULL);
}
