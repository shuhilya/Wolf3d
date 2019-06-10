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

void	shift_calc(t_map_shift *map_shift, t_wolf *wolf, int x_pos, int y_pos)
{
	if (x_pos < MAP_SIZE / 2)
		map_shift->x_shift = 0;
	else if (x_pos < wolf->map->width * MAP_BLOCK - MAP_SIZE / 2)
		map_shift->x_shift = x_pos - MAP_SIZE / 2;
	else
		map_shift->x_shift = wolf->map->width * MAP_BLOCK - MAP_SIZE;
	if (y_pos < MAP_SIZE / 2)
		map_shift->y_shift = 0;
	else if (y_pos < wolf->map->height * MAP_BLOCK - MAP_SIZE / 2)
		map_shift->y_shift = y_pos - MAP_SIZE / 2;
	else
		map_shift->y_shift = wolf->map->height * MAP_BLOCK - MAP_SIZE;
}

void	swap_double(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	check_size(t_map *map)
{
	if ((map->width < MAP_SIZE / MAP_BLOCK) ||
		(map->height < MAP_SIZE / MAP_BLOCK))
		map_error_message();
}

void	draw_arrow(t_drawchar *tmp)
{
	tmp->angle = tmp->angle / 180 * M_PI;
	tmp->image.x_size = MAP_SIZE;
	tmp->image.bor_x_min = 0;
	tmp->image.bor_x_max = MAP_SIZE;
	tmp->image.bor_y_min = 0;
	tmp->image.bor_y_max = MAP_SIZE;
	tmp->draw.x0 = tmp->x_pos - tmp->x_shift;
	tmp->draw.y0 = tmp->y_pos - tmp->y_shift;
	tmp->draw.x1 = tmp->draw.x0 + 20 * cos(tmp->angle);
	tmp->draw.y1 = tmp->draw.y0 - 20 * sin(tmp->angle);
	draw_line(&tmp->image, &tmp->draw, 0xFFFF, 0xFFFF);
	tmp->angle -= 30.0 / 180.0 * M_PI;
	tmp->draw.x0 = tmp->x_pos - tmp->x_shift;
	tmp->draw.y0 = tmp->y_pos - tmp->y_shift;
	tmp->draw.x1 = tmp->draw.x0 + 10 * cos(tmp->angle);
	tmp->draw.y1 = tmp->draw.y0 - 10 * sin(tmp->angle);
	draw_line(&tmp->image, &tmp->draw, 0xFFFF, 0xFFFF);
	tmp->angle += 60.0 / 180.0 * M_PI;
	tmp->draw.x0 = tmp->x_pos - tmp->x_shift;
	tmp->draw.y0 = tmp->y_pos - tmp->y_shift;
	tmp->draw.x1 = tmp->draw.x0 + 10 * cos(tmp->angle);
	tmp->draw.y1 = tmp->draw.y0 - 10 * sin(tmp->angle);
	draw_line(&tmp->image, &tmp->draw, 0xFFFF, 0xFFFF);
}

void	draw_character(t_wolf *wolf)
{
	t_drawchar tmp;

	tmp.x_pos = wolf->vect->x / ((BLOCK + 0.5) / MAP_BLOCK);
	tmp.y_pos = wolf->vect->y / ((BLOCK + 0.5) / MAP_BLOCK);
	if (tmp.x_pos < MAP_SIZE / 2)
		tmp.x_shift = 0;
	else if (tmp.x_pos < wolf->map->width * MAP_BLOCK - MAP_SIZE / 2)
		tmp.x_shift = tmp.x_pos - MAP_SIZE / 2;
	else
		tmp.x_shift = wolf->map->width * MAP_BLOCK - MAP_SIZE;
	if (tmp.y_pos < MAP_SIZE / 2)
		tmp.y_shift = 0;
	else if (tmp.y_pos < wolf->map->height * MAP_BLOCK - MAP_SIZE / 2)
		tmp.y_shift = tmp.y_pos - MAP_SIZE / 2;
	else
		tmp.y_shift = wolf->map->height * MAP_BLOCK - MAP_SIZE;
	if (wolf->vect->pov_angle + 180 > 360)
		tmp.angle = wolf->vect->pov_angle - 180;
	else
		tmp.angle = wolf->vect->pov_angle + 180;
	tmp.image.data_image = (char *)wolf->mlx->img_data;
	draw_arrow(&tmp);
}
