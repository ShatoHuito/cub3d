/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_and_draw_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:56:09 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 21:56:11 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ray_init(t_all *all, int x)
{
	all->plr->camer_x = 2 * x / (double)(all->screen_w) - 1;
	all->ray->raydir_x = all->plr->dir_x + all->plane_x * all->plr->camer_x;
	all->ray->raydir_y = all->plr->dir_y + all->plane_y * all->plr->camer_x;
	all->map->map_x = (int)(all->plr->pos_x);
	all->map->map_y = (int)(all->plr->pos_y);
	all->ray->dlta_dist_x = fabs(1 / all->ray->raydir_x);
	all->ray->dlta_dist_y = fabs(1 / all->ray->raydir_y);
	all->ray->hit = 0;
}

void	ray_dir(t_all *all)
{
	if (all->ray->raydir_x < 0)
	{
		all->plr->step_x = -1;
		all->ray->side_dist_x = (all->plr->pos_x - all->map->map_x)
				* all->ray->dlta_dist_x;
	}
	else
	{
		all->plr->step_x = 1;
		all->ray->side_dist_x = (all->map->map_x + 1.0 - all->plr->pos_x)
				* all->ray->dlta_dist_x;
	}
	if (all->ray->raydir_y < 0)
	{
		all->plr->step_y = -1;
		all->ray->side_dist_y = (all->plr->pos_y - all->map->map_y)
				* all->ray->dlta_dist_y;
	}
	else
	{
		all->plr->step_y = 1;
		all->ray->side_dist_y = (all->map->map_y + 1.0 - all->plr->pos_y)
				* all->ray->dlta_dist_y;
	}
}

void	ray_hit(t_all *all)
{
	while (all->ray->hit == 0)
	{
		if (all->ray->side_dist_x < all->ray->side_dist_y)
		{
			all->ray->side_dist_x += all->ray->dlta_dist_x;
			all->map->map_x += all->plr->step_x;
			all->ray->side = 0;
		}
		else
		{
			all->ray->side_dist_y += all->ray->dlta_dist_y;
			all->map->map_y += all->plr->step_y;
			all->ray->side = 1;
		}
		if (all->map->p_map[all->map->map_y][all->map->map_x] == '1')
			all->ray->hit = 1;
	}
	if (all->ray->side == 0)
		all->ray->perp_walldist = (all->map->map_x - all->plr->pos_x +
				(1.0 - all->plr->step_x) / 2) / all->ray->raydir_x;
	else
		all->ray->perp_walldist = (all->map->map_y - all->plr->pos_y +
				(1.0 - all->plr->step_y) / 2) / all->ray->raydir_y;
}

void	draw_to_window(t_all *all, int x)
{
	int				y;
	unsigned int	color;

	y = 0;
	while (y <= all->txt->drw_strt)
	{
		my_mlx_pixel_put(all, x, y, all->roof_color);
		y++;
	}
	while (y > all->txt->drw_strt && y < all->txt->drw_end)
	{
		color = texcolor_inic(all);
		my_mlx_pixel_put(all, x, y, color);
		y++;
	}
	while (y < all->screen_h)
	{
		my_mlx_pixel_put(all, x, y, all->floor_color);
		y++;
	}
	all->z_buff[x] = all->ray->perp_walldist;
}

void	ray_draw(t_all *all, int x)
{
	all->txt->line_h = (int)(all->screen_h / all->ray->perp_walldist);
	all->txt->drw_strt = -all->txt->line_h / 2 + all->screen_h / 2;
	if (all->txt->drw_strt < 0)
		all->txt->drw_strt = 0;
	all->txt->drw_end = all->txt->line_h / 2 + all->screen_h / 2;
	if (all->txt->drw_end >= all->screen_h)
		all->txt->drw_end = all->screen_h - 1;
	if (all->ray->side == 0)
		all->ray->wall_x = all->plr->pos_y + all->ray->perp_walldist
				* all->ray->raydir_y;
	else
		all->ray->wall_x = all->plr->pos_x + all->ray->perp_walldist
				* all->ray->raydir_x;
	all->ray->wall_x -= floor((all->ray->wall_x));
	ray_draw2(all);
	all->txt->tex_pos = (all->txt->drw_strt - all->screen_h / 2.0 +
			all->txt->line_h / 2.0) * all->txt->step;
	draw_to_window(all, x);
}
