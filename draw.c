#include "cub3d.h"

void scale_pixel(t_data img, int i, int j, int color)
{
    i = i * SCALE;
    j = j * SCALE;
    int x = 0;
    int y = 0;
    while(x < SCALE)
    {
        y = 0;
        while (y < SCALE)
        {
            my_mlx_pixel_put(&img, i, j + y, color);
            y++;
        }
        i++;
        x++;
    }
}

void wall_build(t_data img, int start, double x, double  y)
{
	double dist;
	int res;
	double wall_h;
	double l_start;
	double l_end;

	res = 500;
	dist = sqrt((x * x) + (y * y));
	wall_h = (580 / dist) / 0.2;
	l_start = -wall_h / 2 + 580 /2;
	if (l_start < 0)
		l_start = 0;
	l_end = wall_h / 2 + 580 /2;
	if (l_end >= 580)
		l_end = 580 - 1;
	l_start += 500;
	l_end += 500;
	while(res < RES_X)
	{
		if(res >= l_start && res <= l_end)
			my_mlx_pixel_put(&img, res, start, 0x996600); // stena
		if(res < l_start)
			my_mlx_pixel_put(&img, res, start, 0x99ffff); // nebo
		if(res > l_end)
			my_mlx_pixel_put(&img, res, start, 0x99ff66); // pol
		res++;
	}

}

void draw_sun(char **map, t_data img)
{
	double start;
	double end;
	int sun_num;

	sun_num = 0;
	img.x0 = img.x;
	img.y0 = img.y;


	start = img.dir - ((M_PI / 180) * 33);
	end = img.dir + ((M_PI / 180) * 33);
	while (start < end)
	{
		img.dir = start;
		img.x = img.x0;
		img.y = img.y0;
		while (map[(int) (img.y / SCALE)][(int) (img.x / SCALE)] != '1')
		{
			img.x += cos(img.dir);
			img.y += sin(img.dir);
			my_mlx_pixel_put(&img, (int) img.y, (int) img.x, 0x00AA00);
		}
		wall_build(img, sun_num, img.x -  img.x0, img.y - img.y0);
		sun_num++;
		start += M_PI_2 / 1000;
	}
}


void all_black_pix(t_data img)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(x != RES_X)
	{
		y = 0;
		while (y != RES_Y)
		{
			my_mlx_pixel_put(&img, x, y, 0x000000);
			y++;
		}
		x++;
	}
}


void draw(char **map, t_data *img)
{
    int i = 0;
    int j = 0;
    all_black_pix(*img);
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == '1')
                scale_pixel(*img, i, j, 0xFFFFFF);
            if(map[i][j] == 'N' && img->rspwn_flag != 1)
            {
                img->x = j * SCALE;
                img->y = i * SCALE;
                img->x_sun = img->x;
                img->y_sun = img->y;
                img->rspwn_flag = 1;
                img->dir = M_PI_2;
            }
            j++;
        }
        i++;
    }
	draw_sun(map, *img);
    mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
    mlx_do_sync(img->mlx);
}