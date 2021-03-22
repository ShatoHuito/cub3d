/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:55:11 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 21:55:12 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	color_inic(t_all *all, char *str_map)
{
	if (str_map[0] == 'F')
		floor_color(all, str_map);
	else
		ceilling_color(all, str_map);
}

void	map_strinic(t_all *all, char *str_map)
{
	if (str_map[0] == 'R')
		resol_inic(all, str_map);
	else if (str_map[0] == 'N' || str_map[0] == 'S'
	|| str_map[0] == 'W' || str_map[0] == 'E')
		text_inic(all, str_map);
	else if (str_map[0] == 'F' || str_map[0] == 'C')
		color_inic(all, str_map);
}

void	struct_param_inic(t_all *all)
{
	all->screen_w = 0;
	all->screen_h = 0;
	all->floor_color = -1;
	all->roof_color = -1;
	all->spr->spr_w_img = -1;
	all->txt->no_width = -1;
	all->txt->so_width = -1;
	all->txt->ea_width = -1;
	all->txt->we_width = -1;
}

void	resol_check(t_all *all)
{
	int h;
	int w;

	mlx_get_screen_size(all->mlx, &w, &h);
	if (all->screen_h > h)
		all->screen_h = h;
	if (all->screen_w > w)
		all->screen_w = w;
}

void	first_parc(t_all *all, char **str_map)
{
	int y;

	y = 0;
	struct_param_inic(all);
	while (str_map[y])
		map_strinic(all, str_map[y++]);
	resol_check(all);
	map_inic(all, str_map);
	map_valid(str_map);
}
