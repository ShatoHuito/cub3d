/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:57:09 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 21:57:10 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	exit_x(void)
{
	exit(1);
}

void	error(char *str)
{
	printf("Error\n%s", str);
	exit(1);
}

void	my_mlx_pixel_put(t_all *all, int x, int y, unsigned int color)
{
	char	*dst;

	dst = all->addr + (y * all->line_length + x * (all->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
