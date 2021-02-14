#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line/get_next_line.h"
#include "minilibx_mms/mlx.h"

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int         x;
    int         y;
    int         x0;
    int         y0;
    void    *mlx;
    void    *mlx_win;
    int         flag;
    char    **p_map;
}               t_data;

#endif
