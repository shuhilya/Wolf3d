/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:57:04 by htorp             #+#    #+#             */
/*   Updated: 2019/05/12 13:54:32 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF3D_H
# define WOLF3D_WOLF3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <float.h>
# include <mlx.h>
# include "fdf.h"
# include "libft.h"
# define BLOCK  512
# define MAP_BLOCK 16
# define MAP_SIZE 384
# define SIZE_X 2550
# define SIZE_Y 1275

enum	e_direction {
	EAST,
	NORTH,
	WEST,
	SOUTH
};

typedef struct			s_map_dr
{
	int					h_min;
	int					h_max;
	int					v_min;
	int					v_max;
	int					j_min;
	int					j_max;
	int					i_min;
	int					i_max;
}						t_map_dr;

typedef	struct			s_wall_dr
{
	int					d_col;
	int					text_pos_y;
	int					text_pos_x;
	enum e_direction	dir;
	double				p;
}						t_wall_dr;

typedef struct			s_block_calc
{
	int					x_shift;
	int					y_shift;
	int					i;
	int					j;
	int					v_st;
	int					v_end;
	int					h_st;
	int					h_end;
}						t_block_calc;

typedef	struct			s_map_shift
{
	int					x_shift;
	int					y_shift;
}						t_map_shift;

typedef struct			s_mouse
{
	int					start_x;
	int					start_y;
	int					down;
	int					sense;
}						t_mouse;

typedef struct			s_drawchar
{
	int					x_shift;
	int					y_shift;
	int					x_pos;
	int					y_pos;
	double				angle;
	t_image				image;
	t_draw				draw;
}						t_drawchar;

typedef struct			s_projectile
{
	double				angle_ray;
	int					map_x;
	int					map_y;
	float				xa;
	float				ya;
	int					hit;
}						t_projectile;

typedef struct			s_distance
{
	double				line_a;
	double				line_b;
	enum e_direction	dir;
}						t_distance;

typedef struct			s_mlx
{
	void				*win_ptr;
	void				*mlx_ptr;
	void				*img_ptr;
	void				*img_ptr2;
	int					bpp;
	int					sl;
	int					en;
	int					*img_data;
	int					*img_d2;
}						t_mlx;

typedef struct			s_coll_bord
{
	int					y_up;
	int					y_down;
	int					x_left;
	int					x_right;
}						t_coll_bord;

typedef struct			s_move
{
	double				angle_forward;
	double				angle_side;
	int					x;
	int					y;
	int					step;
}						t_move;

typedef struct			s_map
{
	int					width;
	int					height;
	int					**i_map;
	char				*symbols;
}						t_map;

typedef struct			s_vector
{
	int					x;
	int					y;
	double				pov_angle;
	double				view_angle;
	int					dir_x;
	int					dir_y;
	int					pp_width;
	int					pp_height;
	int					h_center;
	int					center_cor;
	char				map_flag;
}						t_vector;

typedef struct			s_proj
{
	float				ax;
	float				ay;
	float				bx;
	float				by;
}						t_proj;

typedef struct			s_culcmup
{
	int					i;
	int					j;
	int					count;
	char				c;
	int					first_read;
}						t_culcmup;

typedef struct			s_wolf
{
	t_proj				*proj;
	t_vector			*vect;
	t_map				*map;
	t_mlx				*mlx;
	t_draw				*draw;
	t_mouse				*mouse;
	int					**im_text_data;
}						t_wolf;

t_map					*culc_mup_size(int fd, char *str);
int						**read_map(int fd, t_wolf *wolf);
void					map_set_pixels(t_wolf *wolf);
void					proj_vert(t_wolf *wolf);
void					proj_hor(t_wolf *wolf);
void					draw_character(t_wolf *wolf);
void					redraw(t_wolf *wolf, int **im_text_data, t_mlx *mlx);
int						key_press(int keycode, void *param);
int						mouse_close(void *param);
void					draw_vision(t_wolf *wolf, int **im_text_data);
void					move_player(t_wolf *wolf, int keycode);
int						mouse_move(int x, int y, void *param);
int						mouse_press(int button, int x, int y, void *param);
int						mouse_release(int button, int x, int y, void *param);
void					map_error_message(void);
void					set_wall_blks(t_wolf *wolf, t_map_dr *map_dr,
		int x_shift, int y_shift);
void					shift_calc(t_map_shift *map_shift, t_wolf *wolf,
		int x_pos, int y_pos);
void					draw_walls(t_wolf *wolf, int i, enum e_direction dir,
		int **im_text_data);
void					check_size(t_map *map);
int						arg_check(int argc, char **argv);
void					character_error_message(void);
void					texture_check(int x, int y);

#endif
