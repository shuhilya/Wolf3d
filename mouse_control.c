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

int		mouse_move(int x, int y, void *p)
{
	int		dx;
	int		dy;

	if (x >= 0 && x <= SIZE_X && y >= 0 && y <=
	SIZE_Y && ((t_wolf*)p)->mouse->down == 1)
	{
		dx = ((t_wolf*)p)->mouse->start_x - x;
		dy = ((t_wolf*)p)->mouse->start_y - y;
		((t_wolf*)p)->mouse->start_x = x;
		((t_wolf*)p)->mouse->start_y = y;
		if (((t_wolf*)p)->vect->h_center + dy < ((t_wolf*)p)->vect->pp_height
		&& ((t_wolf*)p)->vect->h_center + dy > 0)
		{
			((t_wolf*)p)->vect->h_center += dy;
			((t_wolf*)p)->vect->center_cor += dy;
		}
		if (((t_wolf*)p)->vect->pov_angle >= 360)
			((t_wolf*)p)->vect->pov_angle -= 360;
		else if (((t_wolf*)p)->vect->pov_angle < 0)
			((t_wolf*)p)->vect->pov_angle += 360;
		((t_wolf*)p)->vect->pov_angle += dx / ((t_wolf*)p)->mouse->sense;
		redraw(((t_wolf*)p), ((t_wolf*)p)->im_text_data, ((t_wolf*)p)->mlx);
	}
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_wolf *wolf;

	if (x >= 0 && x <= SIZE_X && y >= 0 && y <= SIZE_Y)
	{
		wolf = (t_wolf *)param;
		wolf->mouse->down = 1;
		wolf->mouse->start_x = x;
		wolf->mouse->start_y = y;
	}
	button++;
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_wolf *wolf;

	wolf = (t_wolf*)param;
	wolf->mouse->down = 0;
	button++;
	x++;
	y++;
	return (0);
}

int		mouse_close(void *param)
{
	param++;
	exit(EXIT_SUCCESS);
	return (0);
}
