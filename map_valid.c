/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:55:55 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 21:55:57 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	first_str_map_valid(char *map)
{
	int x;
	int flag;

	x = 0;
	flag = 0;
	while (map[x])
	{
		if (map[x] == '1')
			flag++;
		x++;
	}
	if (flag == 0)
		error("wrong first string in game map or non-empty line");
}

void	check_arround(char **map, int y, int x)
{
	int i;
	int j;

	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			if (!(map[y - i][x - j] == '1' || map[y - i][x - j] == '0' ||
			map[y - i][x - j] == '2'))
			{
				error("non-valid map (map not closed)");
			}
			j++;
		}
		i++;
	}
}

void	game_map_valid(char **map, int y)
{
	int x;

	first_str_map_valid(map[y]);
	while (map[y])
	{
		if (map[y][0] == '\0')
			error("empty line in game map");
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == '2')
				check_arround(map, y, x);
			x++;
		}
		y++;
	}
}

void	map_valid(char **map)
{
	int		y;
	char	*flags;

	flags = "NSWERFC";
	y = 0;
	while (map[y])
	{
		if (!(ft_strchr(flags, map[y][0])))
		{
			if (!(map[y][0] == ' ' || map[y][0] == '1'))
				error("non-valid identifier");
		}
		if (map[y][0] == ' ' || map[y][0] == '1')
			game_map_valid(map, y);
		y++;
	}
}
