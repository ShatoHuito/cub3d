/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_inic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:55:02 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 21:55:03 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	dir_inic2(t_all *all, char c, double coef)
{
	if (c == 'W')
	{
		all->plr->dir_x = -1;
		all->plr->dir_y = 0;
		all->plane_x = 0;
		all->plane_y = -0.66 * coef;
	}
	else if (c == 'N')
	{
		all->plr->dir_x = 0;
		all->plr->dir_y = -1;
		all->plane_x = 0.66 * coef;
		all->plane_y = 0;
	}
}

void	dir_inic(t_all *all, char c)
{
	double	coef;

	coef = ((double)all->screen_w / 4) / ((double)all->screen_h / 3);
	dir_inic2(all, c, coef);
	if (c == 'S')
	{
		all->plr->dir_x = 0;
		all->plr->dir_y = 1;
		all->plane_x = -0.66 * coef;
		all->plane_y = 0;
	}
	if (c == 'E')
	{
		all->plr->dir_x = 1;
		all->plr->dir_y = 0;
		all->plane_x = 0;
		all->plane_y = 0.66 * coef;
	}
}

void	sprite_search(int y, t_all *all, char **str_map)
{
	int	x;
	int	numspr;

	numspr = 0;
	all->spr->sprs_aray = (int**)malloc(all->spr->spr_sum * sizeof(int*));
	while (numspr < all->spr->spr_sum)
	{
		all->spr->sprs_aray[numspr] = (int *)malloc(2 * sizeof(int));
		numspr++;
	}
	numspr = 0;
	while (str_map[++y])
	{
		x = -1;
		while (str_map[y][++x])
			if (str_map[y][x] == '2')
			{
				all->spr->sprs_aray[numspr][0] = y;
				all->spr->sprs_aray[numspr][1] = x;
				numspr++;
			}
	}
}

void	map_inic2(t_all *all, int y, char **str)
{
	int x;
	int flag;

	flag = 1;
	while (str[y][0] == '1' || str[y][0] == ' ')
	{
		x = 0;
		while (str[y][x])
		{
			if ((str[y][x] == 'N' || str[y][x] == 'E' || str[y][x] == 'S' ||
			str[y][x] == 'W') && flag++)
			{
				all->plr->pos_x = x + 0.5;
				all->plr->pos_y = y + 0.5;
				dir_inic(all, str[y][x]);
				str[y][x] = '0';
			}
			if (str[y][x++] == '2')
				all->spr->spr_sum++;
		}
		y--;
	}
	if (flag != 2)
		error("not-valid map");
	sprite_search(y, all, str);
}

void	map_inic(t_all *all, char **str_map)
{
	int y;

	y = 0;
	all->spr->spr_sum = 0;
	while (str_map[y])
		y++;
	y--;
	map_inic2(all, y, str_map);
}
