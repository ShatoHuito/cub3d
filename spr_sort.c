/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:56:38 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 21:56:40 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sort_spr_array(int i, t_all *all)
{
	int bufy;
	int bufx;

	bufy = all->spr->sprs_aray[i][0];
	bufx = all->spr->sprs_aray[i][1];
	all->spr->sprs_aray[i][0] = all->spr->sprs_aray[i - 1][0];
	all->spr->sprs_aray[i][1] = all->spr->sprs_aray[i - 1][1];
	all->spr->sprs_aray[i - 1][0] = bufy;
	all->spr->sprs_aray[i - 1][1] = bufx;
}

void	sort_sprite(t_all *all)
{
	double	buf;
	int		i;
	int		flag;

	flag = 1;
	while (flag > 0)
	{
		flag = 0;
		i = 1;
		while (all->spr->spr_dist[i])
		{
			if (all->spr->spr_dist[i] > all->spr->spr_dist[i - 1])
			{
				sort_spr_array(i, all);
				buf = all->spr->spr_dist[i];
				all->spr->spr_dist[i] = all->spr->spr_dist[i - 1];
				all->spr->spr_dist[i - 1] = buf;
				flag++;
			}
			i++;
		}
	}
	i = 0;
}

void	spr_sort(t_all *all)
{
	int i;

	i = 0;
	all->spr->spr_dist = ft_calloc(all->spr->spr_sum + 1, sizeof(double));
	while (i < all->spr->spr_sum)
	{
		all->spr->spr_dist[i] = ((all->plr->pos_x - all->spr->sprs_aray[i][1]) *
			(all->plr->pos_x - all->spr->sprs_aray[i][1]) + (all->plr->pos_y -
			all->spr->sprs_aray[i][0]) *
			(all->plr->pos_y - all->spr->sprs_aray[i][0]));
		i++;
	}
	all->spr->spr_dist[i] = 0;
	sort_sprite(all);
}
