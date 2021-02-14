#include "cub3d.h"


void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void scale_pixel(t_data img, int i, int j, int color)
{
    i = i * 30;
    j = j * 30;
    int x = 0;
    int y = 0;
    while(x < 30)
    {
        y = 0;
        while (y < 30)
        {
            my_mlx_pixel_put(&img, i, j + y, color);
            y++;
        }
        i++;
        x++;
    }
}

void draw_walk(t_data img)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(y < 30)
    {
        x = 0;
        while(x < 30)
        {
            my_mlx_pixel_put(&img, img.y + y, img.x + x, 0xFF0000);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
}

void draw(char **map, t_data *img)
{
    int i = 0;
    int j = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == '0' || map[i][j] == 'N')
                scale_pixel(*img, i, j, 0x000000);
            if(map[i][j] == '1')
                scale_pixel(*img, i, j, 0xFFFFFF);
            if(map[i][j] == 'N' && img->flag != 1)
            {
                img->x = j * 30;
                img->y = i * 30;
                img->flag = 1;
            }
            j++;
        }
        i++;
    }
    draw_walk(*img);
    mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

int key_hook(int keycode, t_data *img)
{
    if(keycode == 126)
        img->y -= 1;
    if(keycode == 125)
        img->y += 1;
    if(keycode == 123)
        img->x -= 1;
    if(keycode == 124)
        img->x += 1;

    draw(img->p_map, img);
    return (0);
}


void    window(char **map)
{
    t_data  img;
    img.flag = 0;
    img.p_map = map;

    img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(img.mlx, 1920, 1080);
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