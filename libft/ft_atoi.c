/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 14:14:56 by gbrittan          #+#    #+#             */
/*   Updated: 2020/11/20 15:47:26 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int a;
	int b;
	int c;

	a = 0;
	b = -1;
	c = 0;
	while (str[a] && (str[a] == ' ' || str[a] == '\t' || str[a] == '\n'
				|| str[a] == '\v' || str[a] == '\f' || str[a] == '\r'))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			b = b * -1;
		a++;
	}
	while (str[a] && str[a] >= '0' && str[a] <= '9')
	{
		c = (c * 10) + (str[a] - '0');
		a++;
	}
	if (b < 0)
		return (c);
	else
		return (-c);
}
