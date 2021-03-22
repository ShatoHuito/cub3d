/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:41:19 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 21:41:23 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	key_hook3(int key, t_all *all)
{
	if (key == 13)
	{
		if (!(all->map->p_map[(int)(all->plr->pos_y + (all->plr->dir_y * 0.2))]
		[(int)(all->plr->pos_x + (all->plr->dir_x * 0.2))] == '1'))
		{
			all->plr->pos_y += all->plr->dir_y * 0.2;
			all->plr->pos_x += all->plr->dir_x * 0.2;
		}
	}
	if (key == 1)
	{
		if (!(all->map->p_map[(int)(all->plr->pos_y - (all->plr->dir_y * 0.2))]
		[(int)(all->plr->pos_x - (all->plr->dir_x * 0.2))] == '1'))
		{
			all->plr->pos_y -= all->plr->dir_y * 0.2;
			all->plr->pos_x -= all->plr->dir_x * 0.2;
		}
	}
}

void	key_hook2(int key, t_all *all)
{
	if (key == 0)
	{
		if (!(all->map->p_map[(int)(all->plr->pos_y - (all->plr->dir_x * 0.2))]
		[(int)(all->plr->pos_x + (all->plr->dir_y * 0.2))] == '1'))
		{
			all->plr->pos_y -= all->plr->dir_x * 0.2;
			all->plr->pos_x += all->plr->dir_y * 0.2;
		}
	}
	if (key == 2)
	{
		if (!(all->map->p_map[(int)(all->plr->pos_y + (all->plr->dir_x * 0.2))]
		[(int)(all->plr->pos_x - (all->plr->dir_y * 0.2))] == '1'))
		{
			all->plr->pos_y += all->plr->dir_x * 0.2;
			all->plr->pos_x -= all->plr->dir_y * 0.2;
		}
	}
	all->plr->old_dir_x = all->plr->dir_x;
	all->plr->old_p_x = all->plane_x;
}

void	key_hook(int key, t_all *all)
{
	double rs;

	rs = 0.07;
	key_hook2(key, all);
	key_hook3(key, all);
	if (key == 123)
	{
		all->plr->dir_x = all->plr->dir_x * cos(-rs) -
				all->plr->dir_y * sin(-rs);
		all->plr->dir_y = all->plr->old_dir_x * sin(-rs) +
				all->plr->dir_y * cos(-rs);
		all->plane_x = all->plane_x * cos(-rs) - all->plane_y * sin(-rs);
		all->plane_y = all->plr->old_p_x * sin(-rs) + all->plane_y * cos(-rs);
	}
	if (key == 124)
	{
		all->plr->dir_x = all->plr->dir_x * cos(rs) - all->plr->dir_y * sin(rs);
		all->plr->dir_y = all->plr->old_dir_x * sin(rs) +
				all->plr->dir_y * cos(rs);
		all->plane_x = all->plane_x * cos(rs) - all->plane_y * sin(rs);
		all->plane_y = all->plr->old_p_x * sin(rs) + all->plane_y * cos(rs);
	}
	if (key == 53)
		exit(0);
	raycast(all);
}
