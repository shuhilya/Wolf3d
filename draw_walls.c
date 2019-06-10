/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:57:04 by htorp             #+#    #+#             */
/*   Updated: 2019/05/01 16:57:08 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	dist_cucl(t_wolf *wolf, t_distance *dist)
{
	double	x;
	double	y;

	dist->line_a = DBL_MAX;
	dist->line_b = dist->line_a;
	if (wolf->vect->pov_angle < 0)
		wolf->vect->pov_angle = 360 + wolf->vect->pov_angle;
	if (wolf->vect->pov_angle > 359)
		wolf->vect->pov_angle = wolf->vect->pov_angle - 360;
	if (wolf->vect->pov_angle != 90 && wolf->vect->pov_angle != 270)
	{
		proj_vert(wolf);
		y = wolf->proj->by - wolf->vect->y;
		x = wolf->proj->bx - wolf->vect->x;
		dist->line_b = sqrt(y * y + x * x);
	}
	if (wolf->vect->pov_angle != 180 && wolf->vect->pov_angle != 0)
	{
		proj_hor(wolf);
		y = wolf->proj->ay - wolf->vect->y;
		x = wolf->proj->ax - wolf->vect->x;
		dist->line_a = sqrt(y * y + x * x);
	}
}

void	dir_cucl(t_wolf *wolf, t_distance *dist)
{
	if (dist->line_a > dist->line_b)
	{
		wolf->draw->x1 = wolf->proj->bx;
		wolf->draw->y1 = wolf->proj->by;
		if (wolf->vect->dir_x == 1)
			dist->dir = EAST;
		else
			dist->dir = WEST;
	}
	else
	{
		wolf->draw->x1 = wolf->proj->ax;
		wolf->draw->y1 = wolf->proj->ay;
		if (wolf->vect->dir_y == 1)
			dist->dir = NORTH;
		else
			dist->dir = SOUTH;
	}
}

void	draw_vision(t_wolf *wolf, int **im_text_data)
{
	double		start_angle;
	double		start_pov;
	double		angle_step;
	int			i;
	t_distance	dist;

	i = 0;
	angle_step = wolf->vect->view_angle / wolf->vect->pp_width;
	start_angle = -wolf->vect->view_angle / 2;
	start_pov = wolf->vect->pov_angle;
	while (start_angle < wolf->vect->view_angle / 2)
	{
		wolf->vect->pov_angle += start_angle;
		dist_cucl(wolf, &dist);
		dir_cucl(wolf, &dist);
		wolf->draw->x0 = wolf->vect->x;
		wolf->draw->y0 = wolf->vect->y;
		wolf->vect->pov_angle = start_pov;
		start_angle += angle_step;
		draw_walls(wolf, i, dist.dir, im_text_data);
		i++;
	}
}
