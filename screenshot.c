/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:56:25 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 21:56:26 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	bmp_inic(t_all *all)
{
	all->bmp->file_type[0] = 'B';
	all->bmp->file_type[1] = 'M';
	all->bmp->file_size = 54 + 4 * all->screen_h * all->screen_w;
	all->bmp->byte_reserved = 0x00000000;
	all->bmp->byte_offset = 0x36;
	all->bmp->header_size = 0x28;
	all->bmp->image_height = -all->screen_h;
	all->bmp->image_width = all->screen_w;
	all->bmp->color_planes = 0x01;
	all->bmp->bits_per_pixel = 32;
	all->bmp->compression = 0x00000000;
	all->bmp->image_size = 4 * all->screen_h * all->screen_w;
	all->bmp->x_pixpermeter = 0x00000000;
	all->bmp->y_pixpermeter = 0x00000000;
	all->bmp->total_colors = 0x00000000;
	all->bmp->important_colors = 0x00000000;
}

void	first_write(t_all *all, int fd)
{
	write(fd, all->bmp->file_type, 2);
	write(fd, &all->bmp->file_size, 4);
	write(fd, &all->bmp->byte_reserved, 4);
	write(fd, &all->bmp->byte_offset, 4);
	write(fd, &all->bmp->header_size, 4);
	write(fd, &all->bmp->image_width, 4);
	write(fd, &all->bmp->image_height, 4);
	write(fd, &all->bmp->color_planes, 2);
	write(fd, &all->bmp->bits_per_pixel, 2);
	write(fd, &all->bmp->compression, 4);
	write(fd, &all->bmp->image_size, 4);
	write(fd, &all->bmp->x_pixpermeter, 4);
	write(fd, &all->bmp->y_pixpermeter, 4);
	write(fd, &all->bmp->total_colors, 4);
	write(fd, &all->bmp->important_colors, 4);
}

void	make_bmp(t_all *all)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	bmp_inic(all);
	first_write(all, fd);
	while (i < all->screen_h)
	{
		write(fd, all->addr + i * all->line_length, all->screen_w * 4);
		i++;
	}
	printf("Screenshot will be created successfully");
	exit(1);
}
