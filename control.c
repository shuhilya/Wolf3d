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

void	redraw(t_wolf *wolf, int **im_text_data, t_mlx *mlx)
{
	int pos_x;

	pos_x = SIZE_X - MAP_SIZE;
	if (mlx->img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, MAP_SIZE, MAP_SIZE);
	mlx->img_data = (int *)mlx_get_data_addr(mlx->img_ptr,
			&mlx->bpp, &mlx->sl, &mlx->en);
	if (mlx->img_ptr2 != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr2);
	mlx->img_ptr2 = mlx_new_image(mlx->mlx_ptr,
			wolf->vect->pp_width, wolf->vect->pp_height);
	mlx->img_d2 = (int *)mlx_get_data_addr(mlx->img_ptr2,
			&mlx->bpp, &mlx->sl, &mlx->en);
	map_set_pixels(wolf);
	draw_character(wolf);
	draw_vision(wolf, im_text_data);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr2, 0, 0);
	if (wolf->vect->map_flag)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->img_ptr, pos_x, SIZE_Y - MAP_SIZE);
}

void	coll_check(t_wolf *wolf, int x, int y, t_coll_bord *coll_bord)
{
	if ((wolf->map->i_map[coll_bord->y_down / BLOCK][x / BLOCK]) ||
		(wolf->map->i_map[coll_bord->y_up / BLOCK][x / BLOCK]))
	{
		if (!(wolf->map->i_map[y / BLOCK][coll_bord->x_left / BLOCK]) &&
			!(wolf->map->i_map[y / BLOCK][coll_bord->x_right / BLOCK]))
			if (abs(wolf->vect->x - x) > BLOCK / 16)
				wolf->vect->x = x;
	}
	else if ((wolf->map->i_map[y / BLOCK][coll_bord->x_left / BLOCK]) ||
		(wolf->map->i_map[y / BLOCK][coll_bord->x_right / BLOCK]))
	{
		if (!(wolf->map->i_map[coll_bord->y_down / BLOCK][x / BLOCK]) &&
			!(wolf->map->i_map[coll_bord->y_up / BLOCK][x / BLOCK]))
			if (abs(wolf->vect->y - y) > BLOCK / 16)
				wolf->vect->y = y;
	}
	else
	{
		wolf->vect->x = x;
		wolf->vect->y = y;
	}
}

void	collision_culc(t_wolf *wolf, int x, int y)
{
	t_coll_bord	coll_bord;
	int			collision;

	collision = BLOCK / 8;
	coll_bord.y_up = y - collision;
	coll_bord.y_down = y + collision;
	coll_bord.x_left = x - collision;
	coll_bord.x_right = x + collision;
	coll_check(wolf, x, y, &coll_bord);
}

void	move_solution(t_wolf *wolf, int keycode, t_move *move)
{
	if (keycode == 0)
	{
		move->x = wolf->vect->x + move->step * cos(move->angle_side);
		move->y = wolf->vect->y - move->step * sin(move->angle_side);
	}
	if (keycode == 2)
	{
		move->x = wolf->vect->x - move->step * cos(move->angle_side);
		move->y = wolf->vect->y + move->step * sin(move->angle_side);
	}
	if (keycode == 13)
	{
		move->x = wolf->vect->x + move->step * cos(move->angle_forward);
		move->y = wolf->vect->y - move->step * sin(move->angle_forward);
	}
	if (keycode == 1)
	{
		move->x = wolf->vect->x - move->step * cos(move->angle_forward);
		move->y = wolf->vect->y + move->step * sin(move->angle_forward);
	}
}

void	move_player(t_wolf *wolf, int keycode)
{
	t_move	move;

	move.step = BLOCK / 4;
	move.angle_forward = (double)wolf->vect->pov_angle * M_PI / 180.0;
	move.angle_side = (double)(wolf->vect->pov_angle + 90) * M_PI / 180.0;
	move_solution(wolf, keycode, &move);
	collision_culc(wolf, move.x, move.y);
}
