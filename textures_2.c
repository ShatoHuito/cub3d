/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:57:00 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 21:57:02 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	str_check(const char *str, int j)
{
	if (!(str[j - 1] == 'M' || str[j - 1] == 'm'))
		error("wrong textures or sprite format");
	if (!(str[j - 2] == 'P' || str[j - 2] == 'p'))
		error("wrong textures or sprite format");
	if (!(str[j - 3] == 'X' || str[j - 3] == 'x'))
		error("wrong textures or sprite format");
	if (!(str[j - 4] == '.'))
		error("wrong textures or sprite format");
}

void	sprtxt_inic(t_all *all, char *str_map)
{
	int		i;
	int		j;
	char	str[ft_strlen(str_map)];

	i = 2;
	j = 0;
	if (all->spr->spr_w_img != -1)
		error("double sprite textures inic");
	while (str_map[i] == ' ')
		i++;
	while (str_map[i])
		str[j++] = str_map[i++];
	str[j] = '\0';
	str_check(str, j);
	all->spr->spr_img = mlx_xpm_file_to_image(all->mlx, str,
					&all->spr->spr_w_img, &all->spr->spr_h_img);
	if (all->spr->spr_img == NULL)
		error("wrong sprite texture");
	all->spr->img_data_spr = mlx_get_data_addr(all->spr->spr_img,
	&all->spr->spr_bit_pix, &all->spr->spr_size_line, &all->spr->spr_end);
}

void	north_inic(t_all *all, char *str_map)
{
	int		i;
	int		j;
	char	str[ft_strlen(str_map)];

	i = 2;
	j = 0;
	if (all->txt->no_width != -1)
		error("double NORTH textures inic");
	while (str_map[i] == ' ')
		i++;
	while (str_map[i])
		str[j++] = str_map[i++];
	str[j] = '\0';
	all->txt->no_img = mlx_xpm_file_to_image(all->mlx, str,
	&all->txt->no_width, &all->txt->no_height);
	if (all->txt->no_img == NULL)
		error("wrong NORTH texture");
	all->txt->no_imgdata = mlx_get_data_addr(all->txt->no_img,
	&all->txt->no_bp, &all->txt->no_sline, &all->txt->no_end);
}
