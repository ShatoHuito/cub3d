/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrittan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:31:35 by gbrittan          #+#    #+#             */
/*   Updated: 2021/03/18 22:03:08 by gbrittan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "get_next_line/get_next_line.h"
# include "minilibx_mms/mlx.h"

typedef struct		s_bmp
{
	char			file_type[2];
	unsigned int	file_size;
	unsigned int	byte_reserved;
	unsigned int	byte_offset;
	unsigned int	bits_per_pixel;
	unsigned int	color_planes;
	unsigned int	compression;
	int				image_width;
	int				image_height;
	unsigned int	image_size;
	unsigned int	important_colors;
	unsigned int	total_colors;
	unsigned int	header_size;
	unsigned int	x_pixpermeter;
	unsigned int	y_pixpermeter;
}					t_bmp;

typedef struct		s_txt {
	int				line_h;
	int				drw_strt;
	int				drw_end;
	int				tex_x;
	int				tex_y;
	int				no_width;
	int				no_height;
	char			*no_imgdata;
	int				no_bp;
	int				no_sline;
	int				no_end;
	void			*no_img;
	int				so_width;
	int				so_height;
	char			*so_imgdata;
	int				so_bp;
	int				so_sline;
	int				so_end;
	void			*so_img;
	int				ea_width;
	int				ea_height;
	char			*ea_imgdata;
	int				ea_bp;
	int				ea_sline;
	int				ea_end;
	void			*ea_img;
	int				we_width;
	int				we_height;
	char			*we_imgdata;
	int				we_bp;
	int				we_sline;
	int				we_end;
	void			*we_img;
	double			step;
	double			tex_pos;
	int				kstl_w;
	int				kstl_h;
}					t_txt;

typedef struct		s_spr {
	double			sprt_x;
	double			sprt_y;
	int				spr_w_img;
	int				spr_h_img;
	char			*img_data_spr;
	int				spr_bit_pix;
	int				spr_size_line;
	int				spr_end;
	void			*spr_img;
	int				spr_scrn_x;
	int				sprite_h;
	int				drw_start_y;
	int				drw_end_y;
	int				spr_w;
	int				drw_start_x;
	int				drw_end_x;
	int				strp_x;
	int				strp_y;
	int				spr_sum;
	int				**sprs_aray;
	double			*spr_dist;
}					t_spr;

typedef struct		s_plr {
	double			pos_x;
	double			pos_y;
	double			camer_x;
	double			dir_x;
	double			dir_y;
	int				step_x;
	int				step_y;
	double			old_dir_x;
	double			old_p_x;
}					t_plr;

typedef struct		s_ray {
	double			raydir_x;
	double			raydir_y;
	double			dlta_dist_x;
	double			dlta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	int				hit;
	int				side;
	double			perp_walldist;
	double			wall_x;
}					t_ray;

typedef struct		s_map {
	int				map_x;
	int				map_y;
	char			**p_map;
}					t_map;

typedef struct		s_all {
	t_txt			*txt;
	t_spr			*spr;
	t_plr			*plr;
	t_map			*map;
	t_ray			*ray;
	t_bmp			*bmp;
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	double			plane_x;
	double			plane_y;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				roof_color;
	int				floor_color;
	double			inv_det;
	double			*z_buff;
	int				screen_w;
	int				screen_h;
	double			transf_x;
	double			transf_y;
	int				scrn_flag;
}					t_all;

void				ray_init(t_all *all, int x);
void				raycast(t_all *all);
void				spr_draw(int i, t_all *all);
void				my_mlx_pixel_put(t_all *all, int x,
					int y, unsigned int color);
void				first_parc (t_all *all, char **str_map);
void				text_inic (t_all *all, char *str_map);
void				map_inic(t_all *all, char **str_map);
void				error (char *str);
void				spr_sort(t_all *all);
void				map_valid(char **map);
void				make_bmp(t_all *all);
void				key_hook(int key, t_all *all);
void				exit_x(void);
void				resol_inic(t_all *all, char *str_map);
void				valid_color(char *str_map);
void				floor_color(t_all *all, char *str_map);
void				ceilling_color(t_all *all, char *str_map);
void				ray_dir(t_all *all);
void				ray_hit(t_all *all);
void				draw_to_window(t_all *all, int x);
unsigned int		texcolor_inic(t_all *all);
void				ray_draw(t_all *all, int x);
void				ray_draw2(t_all *all);
void				sprtxt_inic(t_all *all, char *str_map);
void				north_inic(t_all *all, char *str_map);

#endif
