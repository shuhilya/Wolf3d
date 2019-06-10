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

void	horiz_look(int keycode, t_wolf *wolf)
{
	float speed;

	speed = 5.0;
	if (keycode == 123)
	{
		wolf->vect->pov_angle += speed;
		if (wolf->vect->pov_angle >= 360.0)
			wolf->vect->pov_angle -= 360.0;
	}
	if (keycode == 124)
	{
		wolf->vect->pov_angle -= speed;
		if (wolf->vect->pov_angle < 0.0)
			wolf->vect->pov_angle += 360.0;
	}
}

void	vert_look(int keycode, t_wolf *wolf)
{
	int	vert_step;

	vert_step = 40;
	if (keycode == 126)
		if (wolf->vect->h_center + vert_step < wolf->vect->pp_height)
		{
			wolf->vect->h_center += vert_step;
			wolf->vect->center_cor += vert_step;
		}
	if (keycode == 125)
		if (wolf->vect->h_center - vert_step > 0)
		{
			wolf->vect->h_center -= vert_step;
			wolf->vect->center_cor -= vert_step;
		}
}

int		key_press(int keycode, void *param)
{
	t_wolf	*wolf;

	wolf = (t_wolf*)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		move_player(wolf, keycode);
	if (keycode == 123 || keycode == 124)
		horiz_look(keycode, wolf);
	if (keycode == 126 || keycode == 125)
		vert_look(keycode, wolf);
	if (keycode == 46)
	{
		if (!wolf->vect->map_flag)
			wolf->vect->map_flag = 1;
		else
			wolf->vect->map_flag = 0;
	}
	redraw(wolf, wolf->im_text_data, wolf->mlx);
	return (keycode);
}
