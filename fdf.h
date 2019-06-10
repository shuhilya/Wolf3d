/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:38:54 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 18:38:57 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <zconf.h>
# define R 0xFF0000
# define G 0xFF00
# define B 0xFF
# define COLOR_STEP_R(a,b,c,d) ((((a & R)>>16) - ((b & R)>>16)) / (c + 1 - d))
# define COLOR_STEP_G(a,b,c,d) (((a & G)>>8) - ((b & G)>>8)) / (c + 1 - d)
# define COLOR_STEP_B(a,b,c,d) ((a & B) - (b & B)) / (c + 1 - d)
# define ONE_R(a,b,c,d) ((a & R) + ((int)(((int)b + 1 - (int)(c)) * d) << 16))
# define ONE_G(a,b,c,d) ((a & G) + ((int)(((int)b + 1 - (int)(c)) * d) << 8))
# define ONE_B(a,b,c,d) ((a & B) + (int)(((int)b + 1 - (int)(c)) * d))

typedef struct		s_image
{
	char			*data_image;
	double			x_size;
	int				bor_x_min;
	int				bor_x_max;
	int				bor_y_min;
	int				bor_y_max;
}					t_image;

typedef struct		s_draw
{
	int				i;
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	double			x;
	double			y;
	double			tmp;
	double			dx;
	double			dy;
	double			in;
	int				sign;
	double			c_s_r;
	double			c_s_g;
	double			c_s_b;
	int				o_c;
	int				o_c_r;
	int				o_c_g;
	int				o_c_b;
	int				set_color;
}					t_draw;

void				ft_put_pixel(t_draw *draw, t_image *image);
void				change_pixel(t_draw *draw, t_image *image);
void				swap_double(double *a, double *b);
void				swap_int(int *color0, int *color1);
int					ipart(double x);
int					ft_round(double x);
double				fpart(double x);
void				draw_line(t_image *img, t_draw *drw, int clr0, int clr1);

#endif
