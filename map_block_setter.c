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

void	map_draw_block(t_wolf *wolf, t_block_calc *b_calc)
{
	int pos_x;
	int pos_y;
	int pos;
	int m;
	int n;

	pos_x = b_calc->j * MAP_BLOCK - b_calc->x_shift;
	pos_y = b_calc->i * MAP_BLOCK - b_calc->y_shift;
	m = b_calc->v_st;
	while (m < b_calc->v_end)
	{
		n = b_calc->h_st;
		while (n < b_calc->h_end)
		{
			pos = pos_x + pos_y * (MAP_SIZE) + m * (MAP_SIZE) + n;
			if (pos < MAP_SIZE * MAP_SIZE)
				wolf->mlx->img_data[pos] = 0xFFFFFF;
			n++;
		}
		m++;
	}
}

void	first_set(t_wolf *wolf, t_map_dr *map_dr, t_block_calc *b_calc)
{
	if (b_calc->i == map_dr->i_min)
	{
		b_calc->v_st = map_dr->v_min;
		b_calc->v_end = MAP_BLOCK;
		b_calc->h_st = map_dr->h_min;
		b_calc->h_end = MAP_BLOCK;
		map_draw_block(wolf, b_calc);
	}
	else if (b_calc->i == map_dr->i_max - 1)
	{
		b_calc->v_st = 0;
		b_calc->v_end = map_dr->v_max;
		b_calc->h_st = map_dr->h_min;
		b_calc->h_end = MAP_BLOCK;
		map_draw_block(wolf, b_calc);
	}
	else
	{
		b_calc->v_st = 0;
		b_calc->v_end = MAP_BLOCK;
		b_calc->h_st = map_dr->h_min;
		b_calc->h_end = MAP_BLOCK;
		map_draw_block(wolf, b_calc);
	}
}

void	second_set(t_wolf *wolf, t_map_dr *map_dr, t_block_calc *b_calc)
{
	if (b_calc->i == map_dr->i_min)
	{
		b_calc->v_st = map_dr->v_min;
		b_calc->v_end = MAP_BLOCK;
		b_calc->h_st = 0;
		b_calc->h_end = map_dr->h_max;
		map_draw_block(wolf, b_calc);
	}
	else if (b_calc->i == map_dr->i_max - 1)
	{
		b_calc->v_st = 0;
		b_calc->v_end = map_dr->v_max;
		b_calc->h_st = 0;
		b_calc->h_end = map_dr->h_max;
		map_draw_block(wolf, b_calc);
	}
	else
	{
		b_calc->v_st = 0;
		b_calc->v_end = MAP_BLOCK;
		b_calc->h_st = 0;
		b_calc->h_end = map_dr->h_max;
		map_draw_block(wolf, b_calc);
	}
}

void	third_set(t_wolf *wolf, t_map_dr *map_dr, t_block_calc *b_calc)
{
	if (b_calc->i == map_dr->i_min)
	{
		b_calc->v_st = map_dr->v_min;
		b_calc->v_end = MAP_BLOCK;
		b_calc->h_st = 0;
		b_calc->h_end = MAP_BLOCK;
		map_draw_block(wolf, b_calc);
	}
	else if (b_calc->i == map_dr->i_max - 1)
	{
		b_calc->v_st = 0;
		b_calc->v_end = map_dr->v_max;
		b_calc->h_st = 0;
		b_calc->h_end = MAP_BLOCK;
		map_draw_block(wolf, b_calc);
	}
	else
	{
		b_calc->v_st = 0;
		b_calc->v_end = MAP_BLOCK;
		b_calc->h_st = 0;
		b_calc->h_end = MAP_BLOCK;
		map_draw_block(wolf, b_calc);
	}
}

void	set_wall_blks(t_wolf *wolf, t_map_dr *map_dr, int x_shift, int y_shift)
{
	int				i;
	int				j;
	t_block_calc	b_calc;

	b_calc.x_shift = x_shift;
	b_calc.y_shift = y_shift;
	i = map_dr->i_min - 1;
	while (++i < map_dr->i_max)
	{
		b_calc.i = i;
		j = map_dr->j_min - 1;
		while (++j < map_dr->j_max)
		{
			b_calc.j = j;
			if (wolf->map->i_map[i][j])
			{
				if (j == map_dr->j_min)
					first_set(wolf, map_dr, &b_calc);
				else if (j == map_dr->j_max - 1)
					second_set(wolf, map_dr, &b_calc);
				else
					third_set(wolf, map_dr, &b_calc);
			}
		}
	}
}
