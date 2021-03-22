/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resol_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:56:15 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 21:56:16 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		resol_inic2(t_all *all, const char *str_map, int x)
{
	if (str_map[x - 1] == ' ' && str_map[x] == '0')
		error("non-valid resolution value");
	while (str_map[x] != ' ')
		all->screen_w = all->screen_w * 10 + (str_map[x++] - 48);
	return (x);
}

int		resol_inic3(t_all *all, const char *str_map, int x)
{
	if (str_map[x - 1] == ' ' && str_map[x] == '0')
		error("non-valid resolution value");
	while (str_map[x] != ' ' && str_map[x] != '\0')
		all->screen_h = all->screen_h * 10 + (str_map[x++] - 48);
	return (x);
}

void	resol_inic(t_all *all, char *str_map)
{
	int x;
	int flag;

	if (all->screen_w != 0)
		error("double resolution inic");
	x = 1;
	flag = 1;
	while (str_map[x] == ' ')
		x++;
	if (ft_isdigit(str_map[x]) && flag++)
		x = resol_inic2(all, str_map, x);
	else
		error("non-valid resolution value");
	while (str_map[x] == ' ')
		x++;
	if (ft_isdigit(str_map[x]) && flag++)
		x = resol_inic3(all, str_map, x);
	else
		error("non-valid resolution value");
	while (str_map[x] == ' ')
		x++;
	if (all->screen_w <= 0 || all->screen_h <= 0)
		error("wrong resolution value");
	if (!(str_map[x] == '\0' && flag == 3))
		error("non-valid resolution value");
}
