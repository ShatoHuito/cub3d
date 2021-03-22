/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:56:33 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 21:58:08 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	spr_draw_2(t_all *all)
{
	all->spr->spr_w = abs((int)(all->screen_h / (all->transf_y)));
	all->spr->drw_start_x = -all->spr->spr_w / 2 + all->spr->spr_scrn_x;
	if (all->spr->drw_start_x < 0)
		all->spr->drw_start_x = 0;
	all->spr->drw_end_x = all->spr->spr_w / 2 + all->spr->spr_scrn_x;
	if (all->spr->drw_end_x >= all->screen_w)
		all->spr->drw_end_x = all->screen_w;
	all->spr->strp_x = all->spr->drw_start_x;
	all->spr->strp_y = all->spr->drw_start_y;
}

void	spr_draw1(int i, t_all *all)
{
	all->spr->sprt_x = all->spr->sprs_aray[i][1] + 0.5 - all->plr->pos_x;
	all->spr->sprt_y = all->spr->sprs_aray[i][0] + 0.5 - all->plr->pos_y;
	all->inv_det = 1.0 / (all->plane_x * all->plr->dir_y - all->plr->dir_x *
			all->plane_y);
	all->transf_x = all->inv_det * (all->plr->dir_y * all->spr->sprt_x -
			all->plr->dir_x * all->spr->sprt_y);
	all->transf_y = all->inv_det * (-all->plane_y * all->spr->sprt_x +
									all->plane_x * all->spr->sprt_y);
	all->spr->spr_scrn_x = (int)((all->screen_w / 2.0) *
			(1 + all->transf_x / all->transf_y));
	all->spr->sprite_h = abs((int)(all->screen_h / (all->transf_y)));
	all->spr->drw_start_y = -all->spr->sprite_h / 2 + all->screen_h / 2;
	if (all->spr->drw_start_y < 0)
		all->spr->drw_start_y = 0;
	all->spr->drw_end_y = all->spr->sprite_h / 2 + all->screen_h / 2;
	if (all->spr->drw_end_y >= all->screen_h)
		all->spr->drw_end_y = all->screen_h - 1;
	spr_draw_2(all);
}

int		spr_draw_3(t_all *all, int tex_x)
{
	tex_x = (int)(256 * (all->spr->strp_x - (-all->spr->spr_w / 2 +
	all->spr->spr_scrn_x)) * all->spr->spr_w_img / all->spr->spr_w) / 256;
	all->spr->strp_y = all->spr->drw_start_y;
	return (tex_x);
}

void	spr_draw_4(t_all *all, int tex_x)
{
	unsigned int	color;
	int				tex_y;
	int				d;

	d = (all->spr->strp_y) * 256 - all->screen_h * 128 +
		all->spr->sprite_h * 128;
	tex_y = ((d * all->spr->spr_h_img) / all->spr->sprite_h) / 256;
	color = *(int *)(all->spr->img_data_spr + (tex_y *
	all->spr->spr_size_line + tex_x * (all->spr->spr_bit_pix / 8)));
	if (color != 0x000000)
		my_mlx_pixel_put(all, all->spr->strp_x, all->spr->strp_y, color);
	all->spr->strp_y++;
}

void	spr_draw(int i, t_all *all)
{
	int				tex_x;

	spr_draw1(i, all);
	while (all->spr->strp_x < all->spr->drw_end_x)
	{
		if (all->transf_y > 0 && all->spr->strp_x > 0 && all->spr->strp_x
		< all->screen_w && all->transf_y < all->z_buff[all->spr->strp_x])
		{
			tex_x = spr_draw_3(all, tex_x);
			while (all->spr->strp_y < all->spr->drw_end_y)
				spr_draw_4(all, tex_x);
		}
		all->spr->strp_x++;
	}
}
