/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_and_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:56:03 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 22:01:05 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

unsigned int	texcolor_inic_2(t_all *all)
{
	unsigned int color;

	if (all->ray->side == 0 && all->ray->raydir_x < 0)
	{
		all->txt->tex_y = (int)(all->txt->tex_pos);
		all->txt->tex_pos += all->txt->step;
		color = *(int *)(all->txt->we_imgdata + (all->txt->tex_y *
		all->txt->we_sline + all->txt->tex_x * (all->txt->we_bp / 8)));
	}
	if (all->ray->side == 0 && all->ray->raydir_x > 0)
	{
		all->txt->tex_y = (int)(all->txt->tex_pos);
		all->txt->tex_pos += all->txt->step;
		color = *(int *)(all->txt->ea_imgdata + (all->txt->tex_y *
				all->txt->ea_sline + all->txt->tex_x * (all->txt->ea_bp / 8)));
	}
	return (color);
}

unsigned int	texcolor_inic(t_all *all)
{
	unsigned int color;

	color = texcolor_inic_2(all);
	if (all->ray->side == 1 && all->ray->raydir_y > 0)
	{
		all->txt->tex_y = (int)(all->txt->tex_pos);
		all->txt->tex_pos += all->txt->step;
		color = *(int *)(all->txt->so_imgdata + (all->txt->tex_y *
		all->txt->so_sline + all->txt->tex_x * (all->txt->so_bp / 8)));
	}
	if (all->ray->side == 1 && all->ray->raydir_y < 0)
	{
		all->txt->tex_y = (int)(all->txt->tex_pos);
		all->txt->tex_pos += all->txt->step;
		color = *(int *)(all->txt->no_imgdata + (all->txt->tex_y *
		all->txt->no_sline + all->txt->tex_x * (all->txt->no_bp / 8)));
	}
	return (color);
}

void			ray_draw3(t_all *all)
{
	all->txt->tex_x = -(int)(all->ray->wall_x * (double)(all->txt->kstl_w));
	if (all->ray->side == 0 && all->ray->raydir_x > 0)
		all->txt->tex_x = -all->txt->kstl_w - all->txt->tex_x + 1;
	if (all->ray->side == 1 && all->ray->raydir_y < 0)
		all->txt->tex_x = -all->txt->kstl_w - all->txt->tex_x + 1;
	all->txt->step = 1.0 * all->txt->kstl_h / all->txt->line_h;
	all->txt->tex_x += all->txt->kstl_w - 1;
}

void			ray_draw2(t_all *all)
{
	if (all->ray->side == 0 && all->ray->raydir_x < 0)
	{
		all->txt->kstl_w = all->txt->we_width;
		all->txt->kstl_h = all->txt->we_height;
	}
	else if (all->ray->side == 0 && all->ray->raydir_x > 0)
	{
		all->txt->kstl_w = all->txt->ea_width;
		all->txt->kstl_h = all->txt->ea_height;
	}
	else if (all->ray->side == 1 && all->ray->raydir_y > 0)
	{
		all->txt->kstl_w = all->txt->so_width;
		all->txt->kstl_h = all->txt->so_height;
	}
	else
	{
		all->txt->kstl_w = all->txt->no_width;
		all->txt->kstl_h = all->txt->no_height;
	}
	ray_draw3(all);
}

void			raycast(t_all *all)
{
	int		x;
	double	buff[all->screen_w];

	x = 0;
	all->z_buff = buff;
	while (x < all->screen_w)
	{
		ray_init(all, x);
		ray_dir(all);
		ray_hit(all);
		ray_draw(all, x);
		x++;
	}
	spr_sort(all);
	x = 0;
	while (x < all->spr->spr_sum)
		spr_draw(x++, all);
	free(all->spr->spr_dist);
	if (all->scrn_flag == 0)
		mlx_put_image_to_window(all->mlx, all->mlx_win, all->img, 0, 0);
	mlx_do_sync(all->mlx);
}
