#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "get_next_line/get_next_line.h"
#include "minilibx_mms/mlx.h"

#define RES_X 1024
#define RES_Y 768

typedef struct s_txt{
	void *txt;
	char *imgData;
	int txt_bit_pix;
	int txt_size_line;
	int txt_end;
} 	t_txt;

//typedef struct spr{
//	void
//};

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int roof_color;
    int floor_color;
    void    *mlx;
    void    *mlx_win;
    char    **p_map;
	double posX;
	double posY; // положение игрока
	double planeX;
	double planeY; //угол обзора
	double dirX;
	double dirY; // направление игрока
	double sideDistX;
	double sideDistY; // длинна луча от текущей позиции до след стороны
	double perpWallDist;
	int stepX;
	int stepY; // в каком направлении будет совершен шаг
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double deltaDistX;
	double deltaDistY;
	double cameraX;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	int widthImg;
	int heightImg;
	double wallX;
	double step;
	double texPos;
	int texX;
	int texY;
	t_txt *txt;
}               t_data;



void            my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);
unsigned int           my_mlx_pixel_ret(t_txt *txt, int x, int y);
void raycast(char **map, t_data *img);
void all_black_pix(t_data img);


#endif
