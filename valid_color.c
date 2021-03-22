/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:57:14 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 21:57:15 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	valid_color_2(int flagspace, char *str_map, int x, int flagdig)
{
	if (flagspace > 0)
		error("valid color error");
	if (str_map[x] == '0' && flagdig == 0 && ft_isdigit(str_map[x + 1]))
		error("valid color error");
}

int		valid_color_3(int flagdig, int flagspace)
{
	if (flagdig > 0)
		flagspace++;
	return (flagspace);
}

int		valid_color_4(int flagdig)
{
	if (flagdig == 0)
		error("valid color error");
	return (0);
}

void	valid_color(char *str_map)
{
	int x;
	int flag;
	int flagdig;
	int flagspace;

	x = 1;
	flag = 1;
	flagdig = 0;
	flagspace = 0;
	while (str_map[x])
	{
		if (str_map[x] == ' ' && x++)
			flagspace = valid_color_3(flagdig, flagspace);
		else if (ft_isdigit(str_map[x]))
			valid_color_2(flagspace, str_map, x++, flagdig++);
		else if (str_map[x++] == ',' && flag++)
		{
			flagdig = valid_color_4(flagdig);
			flagspace = 0;
		}
		else
			error("valid color error");
	}
	if (flag != 3 || flagdig == 0)
		error("valid color error");
}
