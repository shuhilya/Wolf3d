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

void	rec_x_block_min(t_wolf *wolf, int x_pos, t_map_dr *map_dr)
{
	if (x_pos < MAP_SIZE / 2)
	{
		map_dr->h_min = 0;
		map_dr->j_min = 0;
	}
	else if (wolf->map->width * MAP_BLOCK - x_pos < MAP_SIZE / 2)
	{
		map_dr->h_min = 0;
		map_dr->j_min = (wolf->map->width * MAP_BLOCK - MAP_SIZE) / MAP_BLOCK;
	}
	else
	{
		map_dr->h_min = x_pos % MAP_BLOCK;
		map_dr->j_min = (x_pos - MAP_SIZE / 2) / MAP_BLOCK;
	}
}

void	rec_x_block_max(t_wolf *wolf, int x_pos, t_map_dr *map_dr)
{
	if ((wolf->map->width + 1) * MAP_BLOCK - x_pos < MAP_SIZE / 2)
	{
		map_dr->h_max = MAP_BLOCK;
		map_dr->j_max = wolf->map->width;
	}
	else if (x_pos < MAP_SIZE / 2)
	{
		map_dr->h_max = MAP_BLOCK;
		map_dr->j_max = MAP_SIZE / MAP_BLOCK;
	}
	else
	{
		map_dr->h_max = x_pos % MAP_BLOCK;
		map_dr->j_max = (x_pos + MAP_SIZE / 2) / MAP_BLOCK + 1;
	}
}

void	rec_y_block_min(t_wolf *wolf, int y_pos, t_map_dr *map_dr)
{
	if (y_pos < MAP_SIZE / 2)
	{
		map_dr->v_min = 0;
		map_dr->i_min = 0;
	}
	else if (wolf->map->height * MAP_BLOCK - y_pos < MAP_SIZE / 2)
	{
		map_dr->v_min = 0;
		map_dr->i_min = (wolf->map->height * MAP_BLOCK - MAP_SIZE) / MAP_BLOCK;
	}
	else
	{
		map_dr->v_min = y_pos % MAP_BLOCK;
		map_dr->i_min = (y_pos - MAP_SIZE / 2) / MAP_BLOCK;
	}
}

void	rec_y_block_max(t_wolf *wolf, int y_pos, t_map_dr *map_dr)
{
	if (y_pos > (wolf->map->height - 1) * MAP_BLOCK - MAP_SIZE / 2)
	{
		map_dr->v_max = MAP_BLOCK;
		map_dr->i_max = wolf->map->height;
	}
	else if (y_pos > MAP_SIZE / 2)
	{
		map_dr->v_max = y_pos % MAP_BLOCK;
		map_dr->i_max = (y_pos + MAP_SIZE / 2) / MAP_BLOCK + 1;
	}
	else
	{
		map_dr->v_max = MAP_BLOCK;
		map_dr->i_max = MAP_SIZE / MAP_BLOCK;
	}
}

void	map_set_pixels(t_wolf *wolf)
{
	int			x_pos;
	int			y_pos;
	int			resize;
	t_map_dr	map_dr;
	t_map_shift	map_shift;

	resize = (BLOCK + 0.5) / MAP_BLOCK;
	x_pos = wolf->vect->x / resize;
	y_pos = wolf->vect->y / resize;
	rec_x_block_min(wolf, x_pos, &map_dr);
	rec_x_block_max(wolf, x_pos, &map_dr);
	rec_y_block_min(wolf, y_pos, &map_dr);
	rec_y_block_max(wolf, y_pos, &map_dr);
	shift_calc(&map_shift, wolf, x_pos, y_pos);
	set_wall_blks(wolf, &map_dr, map_shift.x_shift, map_shift.y_shift);
}
