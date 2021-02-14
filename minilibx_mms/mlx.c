#include "mlx.h"
#include "../libft/libft.h"
#include <stdio.h>
#include "../cub3d.h"

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    window(char **map)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    int i = 0;
    int j = 0;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 640, 480, "Hello world!");
    img.img = mlx_new_image(mlx, 640, 480);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 1)
                my_mlx_pixel_put(&img, i, j, 0xFFFFFF);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}