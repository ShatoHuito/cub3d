#include "cub3d.h"


void            my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

unsigned int           my_mlx_pixel_ret(t_txt *txt, int x, int y)
{
    char    *dst;

    dst = txt->imgData + (y * txt->txt_size_line + x * (txt->txt_bit_pix / 8));
	return (*(unsigned int *)dst);
}


int key_hook(int key, t_data *img)
{
	double rotspeed = 0.07;
	if (key == 13)
	{
			img->posY += img->dirY * 0.2;
			img->posX += img->dirX * 0.2;
	}
	if (key == 1)
	{
			img->posY -= img->dirY * 0.2;
			img->posX -= img->dirX * 0.2;
	}
	if (key == 2)
	{
		double oldDirX = img->dirX;
		img->dirX = img->dirX * cos(-rotspeed) - img->dirY * sin(-rotspeed);
		img->dirY = oldDirX * sin(-rotspeed) + img->dirY * cos(-rotspeed);
		double oldPlaneX = img->planeX;
		img->planeX = img->planeX * cos (-rotspeed) - img->planeY *
																sin(-rotspeed);
		img->planeY = oldPlaneX * sin (-rotspeed) + img->planeY * cos
				(-rotspeed);
	}
	if (key == 0)
	{
		double oldDirX = img->dirX;
		img->dirX = img->dirX * cos (rotspeed) - img->dirY * sin
				(rotspeed);
		img->dirY = oldDirX * sin(rotspeed) + img->dirY * cos(rotspeed);
		double oldPlaneX = img->planeX;
		img->planeX = img->planeX * cos (rotspeed) - img->planeY *
															   sin(rotspeed);
		img->planeY = oldPlaneX * sin (rotspeed) + img->planeY * cos
				(rotspeed);
	}
    raycast(img->p_map, img);
    return (0);
}


void    window(char **map)
{
    t_data  img;
    t_txt txt;
    img.txt = &txt;
    img.p_map = map;
    img.posX = 5;
    img.posY = 5; // положение игрока
    img.planeX = 0;
    img.planeY = 0.66; //угол обзора
    img.dirX = -1;
    img.dirY = 0; // направление игрока
    img.floor_color = 0x666666;
    img.roof_color = 0x3366FF;

    img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, RES_X, RES_Y, "Hello world!");
    img.img = mlx_new_image(img.mlx, RES_X, RES_Y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	raycast(map, &img);
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