#include "cub3d.h"


void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


int key_hook(int keycode, t_data *img)
{
	if (keycode == 126)
	{
		img->y += sin(img->dir) * 1;
		img->x += cos(img->dir) * 1;
	}
	if (keycode == 125)
	{
		img->y -= sin(img->dir) * 1;
		img->x -= cos(img->dir) * 1;
	}
    if(keycode == 123)
        img->dir -= 0.05;
    if(keycode == 124)
        img->dir += 0.05;

    draw(img->p_map, img);
    return (0);
}


void    window(char **map)
{
    t_data  img;
    img.rspwn_flag = 0;
    img.p_map = map;

    img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, RES_Y, RES_X, "Hello world!");
    img.img = mlx_new_image(img.mlx, RES_Y, RES_X);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    draw(map, &img);
    mlx_hook(img.mlx_win, 2, 1L<<0, key_hook, &img);
    mlx_loop(img.mlx);
}


void make_map(t_list **head, int size)
{
    char **map = ft_calloc(size + 1, sizeof(char *));
    int i = -1;
    t_list *tmp = *head;

    while(tmp)
    {
        map[++i] = tmp->content;
        tmp = tmp->next;
    }
    int x = 0;
    while(map[x])
    {
        ft_putstr_fd(map[x], 1);
        ft_putchar_fd('\n', 1);
        x++;
    }
    window(map);
}


int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    char *line = NULL;
    t_list *head = NULL;
    while (get_next_line(fd, &line))
        ft_lstadd_back(&head, ft_lstnew(line));
    ft_lstadd_back(&head, ft_lstnew(line));
    make_map(&head, ft_lstsize(head));
    return (0);
}