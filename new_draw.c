#include "cub3d.h"

void all_black_pix(t_data img)
{
	int x;
	int y;

	y = 0;
	while(y != RES_Y)
	{
		x = 0;
		while (x != RES_X)
		{
			my_mlx_pixel_put(&img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void ray_init(t_data *img, int x)
{
	img->cameraX = 2 * x / (double)(RES_X) - 1;
	img->rayDirX = img->dirX + img->planeX * img->cameraX;
	img->rayDirY = img->dirY + img->planeY * img->cameraX;

	img->mapX = (int)(img->posX);
	img->mapY = (int)(img->posY); // квадрат в котором мы находимся

	img->deltaDistX = fabs(1 / img->rayDirX);
	img->deltaDistY = fabs(1 / img->rayDirY); //длинна от стор-ы до стор-ы
}

void ray_dir(t_data *img)
{
	if (img->rayDirX < 0)
	{
		img->stepX = -1;
		img->sideDistX = (img->posX - img->mapX) * img->deltaDistX;
	}
	else
	{
		img->stepX = 1;
		img->sideDistX = (img->mapX + 1.0 - img->posX) * img->deltaDistX;
	}
	if (img->rayDirY < 0)
	{
		img->stepY = -1;
		img->sideDistY = (img->posY - img->mapY) * img->deltaDistY;
	}
	else
	{
		img->stepY = 1;
		img->sideDistY = (img->mapY + 1.0 - img->posY) * img->deltaDistY;
	}
}

void ray_hit (t_data *img, char **map)
{
	img->hit = 0;
	while (img->hit == 0)
	{
		if (img->sideDistX < img->sideDistY) // перех на квадрат по Х или У
		{
			img->sideDistX += img->deltaDistX;
			img->mapX += img->stepX;
			img->side = 0;
		}
		else
		{
			img->sideDistY += img->deltaDistY;
			img->mapY += img->stepY;
			img->side = 1;
		}
		if (map[img->mapX][img->mapY] > '0')// проверка стены
			img->hit = 1;
	}
	if (img->side == 0) // расчет расстояния с учетом угла
		img->perpWallDist = (img->mapX - img->posX + (1.0 - img->stepX) / 2) /
				img->rayDirX;
	else
		img->perpWallDist = (img->mapY - img->posY + (1.0 - img->stepY) / 2) /
				img->rayDirY;
}

void draw_to_window (t_data *img, int x)
{
	int y;
	unsigned int color;

	y = 0;
	while (y != img->drawStart)
	{
		my_mlx_pixel_put(img, x, y, img->roof_color);
		y++;
	}
	while(y < img->drawEnd)
	{
		img->texY = (int) img->texPos & (img->heightImg - 1);
		img->texPos += img->step;
		color = my_mlx_pixel_ret(img->txt, img->texX, img->texY);
		if (img->side == 1) // затемнение сторон
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(img, x, y, color);
		y++;
	}
	while (y < RES_Y)
	{
		my_mlx_pixel_put(img, x, y, img->floor_color);
		y++;
	}
}

void ray_draw (t_data *img, int x, char **map)
{
	img->lineHeight = (int)(RES_Y / img->perpWallDist); //высота стены
	img->drawStart = -img->lineHeight / 2 + RES_Y / 2; // высота неба и пола
	if(img->drawStart < 0)
		img->drawStart = 0;
	img->drawEnd = img->lineHeight / 2 + RES_Y / 2;
	if(img->drawEnd >= RES_Y)
		img->drawEnd = RES_Y - 1;

	if (img->side == 0)
		img->wallX = img->posY + img->perpWallDist * img->rayDirY;
	else
		img->wallX = img->posX + img->perpWallDist * img->rayDirX;
	img->wallX -= floor((img->wallX));

	img->texX = (int)(img->wallX * (double)(img->widthImg)); // кордината Х
	// текст
	if(img->side == 0 && img->rayDirX > 0)
		img->texX = img->widthImg - img->texX - 1;
	if(img->side == 1 && img->rayDirY < 0)
		img->texX = img->widthImg - img->texX - 1;

	img->step = 1.0 * img->widthImg / img->lineHeight; // скок пикселей шаг
	img->texPos = (img->drawStart - RES_Y / 2.0 + img->lineHeight / 2.0) *
			img->step; // начальная координата тестуры
	draw_to_window(img, x);
}

void raycast(char **map, t_data *img)
{
	all_black_pix(*img);
	int x = 0;

	img->txt = mlx_xpm_file_to_image(img->mlx,"./redbrick.xpm",
				   &img->widthImg, &img->heightImg);
	img->txt->imgData = mlx_get_data_addr(img->txt, &img->txt->txt_bit_pix,
								  &img->txt->txt_size_line, &img->txt->txt_end);
	while (x < RES_X)
	{
		ray_init(img, x);
		ray_dir(img);
		ray_hit(img, map);
		ray_draw(img, x, map);
		x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_do_sync(img->mlx);
}