/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:56:50 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 21:56:52 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	south_inic(t_all *all, char *str_map)
{
	int		i;
	int		j;
	char	str[ft_strlen(str_map)];

	i = 2;
	j = 0;
	if (all->txt->so_width != -1)
		error("double SOUTH textures inic");
	while (str_map[i] == ' ')
		i++;
	while (str_map[i])
		str[j++] = str_map[i++];
	str[j] = '\0';
	all->txt->so_img = mlx_xpm_file_to_image(all->mlx, str,
				&all->txt->so_width, &all->txt->so_height);
	if (all->txt->so_img == NULL)
		error("wrong SOUTH texture");
	all->txt->so_imgdata = mlx_get_data_addr(all->txt->so_img,
				&all->txt->so_bp, &all->txt->so_sline, &all->txt->so_end);
}

void	east_inic(t_all *all, char *str_map)
{
	int		i;
	int		j;
	char	str[ft_strlen(str_map)];

	i = 2;
	j = 0;
	if (all->txt->ea_width != -1)
		error("double EAST textures inic");
	while (str_map[i] == ' ')
		i++;
	while (str_map[i])
		str[j++] = str_map[i++];
	str[j] = '\0';
	all->txt->ea_img = mlx_xpm_file_to_image(all->mlx, str,
		&all->txt->ea_width, &all->txt->ea_height);
	if (all->txt->ea_img == NULL)
		error("wrong EAST texture");
	all->txt->ea_imgdata = mlx_get_data_addr(all->txt->ea_img,
					&all->txt->ea_bp, &all->txt->ea_sline, &all->txt->ea_end);
}

void	west_inic(t_all *all, char *str_map)
{
	int		i;
	int		j;
	char	str[ft_strlen(str_map)];

	i = 2;
	j = 0;
	if (all->txt->we_width != -1)
		error("double WEST textures inic");
	while (str_map[i] == ' ')
		i++;
	while (str_map[i])
		str[j++] = str_map[i++];
	str[j] = '\0';
	all->txt->we_img = mlx_xpm_file_to_image(all->mlx, str,
					&all->txt->we_width, &all->txt->we_height);
	if (all->txt->we_img == NULL)
		error("wrong WEST texture");
	all->txt->we_imgdata = mlx_get_data_addr(all->txt->we_img,
					&all->txt->we_bp, &all->txt->we_sline, &all->txt->we_end);
}

void	text_inic(t_all *all, char *str_map)
{
	if (str_map[0] == 'N' && str_map[1] == 'O')
		north_inic(all, str_map);
	else if (str_map[0] == 'S' && str_map[1] == 'O')
		south_inic(all, str_map);
	else if (str_map[0] == 'E' && str_map[1] == 'A')
		east_inic(all, str_map);
	else if (str_map[0] == 'W' && str_map[1] == 'E')
		west_inic(all, str_map);
	else if (str_map[0] == 'S' && str_map[1] == ' ')
		sprtxt_inic(all, str_map);
}
