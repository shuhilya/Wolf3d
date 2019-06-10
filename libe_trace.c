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

void	set_dir(t_wolf *wolf)
{
	if (wolf->vect->pov_angle > 0 && wolf->vect->pov_angle <= 90)
	{
		wolf->vect->dir_x = 1;
		wolf->vect->dir_y = 1;
	}
	if (wolf->vect->pov_angle > 90 && wolf->vect->pov_angle <= 180)
	{
		wolf->vect->dir_x = -1;
		wolf->vect->dir_y = 1;
	}
	if (wolf->vect->pov_angle > 180 && wolf->vect->pov_angle <= 270)
	{
		wolf->vect->dir_x = -1;
		wolf->vect->dir_y = -1;
	}
	if (wolf->vect->pov_angle > 270 && wolf->vect->pov_angle <= 360)
	{
		wolf->vect->dir_x = 1;
		wolf->vect->dir_y = -1;
	}
}

void	find_hor(t_wolf *wolf, t_projectile proj)
{
	while (!proj.hit && (wolf->proj->ax) > 0 && (wolf->proj->ay) > 0 &&
	(wolf->proj->ax < (wolf->map->width * BLOCK)) &&
	(wolf->proj->ay < (wolf->map->height * BLOCK)))
	{
		proj.map_x = (wolf->proj->ax) / BLOCK;
		proj.map_y = (wolf->proj->ay) / BLOCK;
		if (wolf->vect->dir_y == 1)
			proj.map_y--;
		if (wolf->map->i_map[proj.map_y][proj.map_x] > 0)
			proj.hit = 1;
		else
		{
			wolf->proj->ax += proj.xa;
			wolf->proj->ay += -proj.ya;
		}
	}
}

void	proj_hor(t_wolf *wolf)
{
	t_projectile proj;

	proj.hit = 0;
	set_dir(wolf);
	proj.angle_ray = (double)wolf->vect->pov_angle * M_PI / 180.0;
	proj.ya = BLOCK * wolf->vect->dir_y;
	proj.xa = proj.ya / tan(proj.angle_ray);
	wolf->proj->ay = (wolf->vect->dir_y == 1) ? ((int)(wolf->vect->y /
			BLOCK) * BLOCK) : (((int)(wolf->vect->y / BLOCK) * BLOCK) + BLOCK);
	wolf->proj->ax = wolf->vect->x + (wolf->vect->y - wolf->proj->ay) /
			tan(proj.angle_ray);
	find_hor(wolf, proj);
}

void	find_vert(t_wolf *wolf, t_projectile proj)
{
	while (!proj.hit && (wolf->proj->bx) > 0 && (wolf->proj->by) > 0 &&
	(wolf->proj->by < (wolf->map->height * BLOCK)) &&
	(wolf->proj->bx < (wolf->map->width * BLOCK)))
	{
		proj.map_x = (wolf->proj->bx) / BLOCK;
		proj.map_y = (wolf->proj->by) / BLOCK;
		if (wolf->vect->dir_x == -1)
			proj.map_x--;
		if (wolf->map->i_map[proj.map_y][proj.map_x] > 0)
			proj.hit = 1;
		else
		{
			wolf->proj->bx += proj.xa;
			wolf->proj->by += -proj.ya;
		}
	}
}

void	proj_vert(t_wolf *wolf)
{
	t_projectile proj;

	proj.hit = 0;
	set_dir(wolf);
	proj.angle_ray = (double)wolf->vect->pov_angle * M_PI / 180.0;
	proj.xa = BLOCK * wolf->vect->dir_x;
	proj.ya = proj.xa * tan(proj.angle_ray);
	wolf->proj->bx = (wolf->vect->dir_x == 1) ? (((int)(wolf->vect->x /
			BLOCK) * BLOCK) + BLOCK) : ((int)(wolf->vect->x / BLOCK) * BLOCK);
	wolf->proj->by = wolf->vect->y +
			(wolf->vect->x - wolf->proj->bx) * tan(proj.angle_ray);
	find_vert(wolf, proj);
}
