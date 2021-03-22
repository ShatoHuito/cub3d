/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilling_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:30:09 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 21:30:11 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ceilling_color_2(t_all *all, char *str_map, int x)
{
	int d;
	int i;

	i = 1;
	d = 0;
	if (all->roof_color != -1)
		error("double roof color inic");
	while (str_map[x] == ' ')
		x++;
	while (ft_isdigit(str_map[x]) && i++)
		d = d * 10 + (str_map[x++] - 48);
	if (d < 0 || d > 255 || (i - 1 > 3))
		error("wrong value 'R' in 'RGB' roof color");
	all->roof_color = 0x000000 + (d * 256 * 256);
	return (x);
}

void	ceilling_color(t_all *all, char *str_map)
{
	int x;
	int d;
	int i;

	x = 1;
	d = 0;
	valid_color(str_map);
	x = ceilling_color_2(all, str_map, x);
	while (str_map[x] == ' ' || str_map[x] == ',')
		x++;
	i = 1;
	while (ft_isdigit(str_map[x]) && i++)
		d = d * 10 + (str_map[x++] - 48);
	if (d < 0 || d > 255 || (i - 1 > 3))
		error("wrong value 'G' in 'RGB' roof color");
	all->roof_color = all->roof_color + (d * 256);
	d = 0;
	while (str_map[x] == ' ' || str_map[x] == ',')
		x++;
	i = 1;
	while (ft_isdigit(str_map[x]) && i++)
		d = d * 10 + (str_map[x++] - 48);
	if (d < 0 || d > 255 || (i - 1 > 3))
		error("wrong value 'B' in 'RGB' roof color");
	all->roof_color = all->roof_color + d;
}
