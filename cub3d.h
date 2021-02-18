#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "get_next_line/get_next_line.h"
#include "minilibx_mms/mlx.h"

#define SCALE 32
#define RES_Y 1920
#define RES_X 1080

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    double         x;
    double         y;
    double         x_sun;
    double 			y_sun;
    double         x0;
    double         y0;
    void    *mlx;
    void    *mlx_win;
    int         rspwn_flag;
    char    **p_map;
    double dir;
}               t_data;

void            scale_pixel(t_data img, int i, int j, int color);
void draw_walk(char **map, t_data img);
void            draw(char **map, t_data *img);
void            my_mlx_pixel_put(t_data *data, int x, int y, int color);


#endif
