/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:54:52 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/22 15:19:04 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		first_start(char **str_map, t_all *all, char **arg)
{
	t_ray ray;
	t_spr spr;

	all->spr = &spr;
	all->ray = &ray;
	all->map->p_map = str_map;
	all->mlx = mlx_init();
	first_parc(all, str_map);
	all->scrn_flag = 0;
	if (arg[2])
		all->scrn_flag = 1;
	if (!(arg[2]))
		all->mlx_win = mlx_new_window(all->mlx, all->screen_w, all->screen_h,
								"cub3D");
	all->img = mlx_new_image(all->mlx, all->screen_w, all->screen_h);
	all->addr = mlx_get_data_addr(all->img, &all->bits_per_pixel,
	&all->line_length, &all->endian);
	raycast(all);
	if (arg[2])
		make_bmp(all);
	mlx_hook(all->mlx_win, 2, 1L << 0, (void*)key_hook, all);
	mlx_hook(all->mlx_win, 17, 1, (void*)exit_x, all);
	mlx_loop(all->mlx);
}

void		first_inic(char **str_map, char **arg)
{
	t_all all;
	t_map map;
	t_plr plr;
	t_txt txt;
	t_bmp bmp;

	all.bmp = &bmp;
	all.map = &map;
	all.plr = &plr;
	all.txt = &txt;
	first_start(str_map, &all, arg);
}

void		make_map(t_list **head, int size, char **arg)
{
	char	**str_map;
	int		i;
	t_list	*tmp;

	tmp = *head;
	str_map = ft_calloc(size + 1, sizeof(char *));
	if (str_map == NULL)
		error("memory allocation error");
	i = -1;
	while (tmp)
	{
		str_map[++i] = tmp->content;
		tmp = tmp->next;
	}
	first_inic(str_map, arg);
}

void		check_argv(char **arg)
{
	int i;

	i = 0;
	while (arg[1][i] != '\0')
		i++;
	if (!(arg[1][i - 3] == 'c' && arg[1][i - 2] == 'u' && arg[1][i - 1] == 'b'
	&& arg[1][i - 4] == '.'))
		error("wrong map name");
	if (arg[2])
		if (!((ft_strncmp(arg[2], "--save", 6) == 0) && arg[2][6] == '\0'))
			error("wrong screen arg");
}

int			main(int argc, char **argv)
{
	char	*line;
	t_list	*head;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	line = NULL;
	head = NULL;
	if (argc == 1 || argc > 3)
		error("wrong number of arguments");
	check_argv(argv);
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head), argv);
	return (0);
}
