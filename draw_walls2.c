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

void	draw_up_wall(t_wolf *wolf, int **im_txt_dt, t_wall_dr *wall_dr, int i)
{
	int	j;
	int	pos;
	int tx_pos;

	j = wolf->vect->h_center;
	while ((j > wall_dr->d_col + wolf->vect->center_cor) && (j > 0))
	{
		wall_dr->text_pos_y = j - (wall_dr->d_col + wolf->vect->center_cor);
		wall_dr->text_pos_y = wall_dr->text_pos_y *
				fabs(wall_dr->p) / (2 * wolf->vect->pp_height);
		if ((wall_dr->dir == NORTH) || (wall_dr->dir == SOUTH))
			wall_dr->text_pos_x = (int)(wolf->draw->x1) % BLOCK;
		else
			wall_dr->text_pos_x = (int)(wolf->draw->y1) % BLOCK;
		pos = (wolf->vect->pp_width - i) + j * wolf->vect->pp_width;
		tx_pos = wall_dr->text_pos_y * BLOCK + wall_dr->text_pos_x;
		wolf->mlx->img_d2[pos] = im_txt_dt[wall_dr->dir][tx_pos];
		j--;
	}
	while (j > 0)
	{
		wolf->mlx->img_d2[(wolf->vect->pp_width - i) + j *
			wolf->vect->pp_width] = 0x87CEFA;
		j--;
	}
}

void	draw_down_wall(t_wolf *wolf, int **im_txt_dt, t_wall_dr *wall_dr, int i)
{
	int	j;
	int	pos;
	int tx_pos;
	int ch_pos;

	ch_pos = wolf->vect->pp_height - wall_dr->d_col + wolf->vect->center_cor;
	j = wolf->vect->h_center - 1;
	while ((++j < ch_pos) &&
		(j < wolf->vect->pp_height))
	{
		wall_dr->text_pos_y = j - (wall_dr->d_col + wolf->vect->center_cor);
		wall_dr->text_pos_y = wall_dr->text_pos_y *
				fabs(wall_dr->p) / (2 * wolf->vect->pp_height);
		if ((wall_dr->dir == NORTH) || (wall_dr->dir == SOUTH))
			wall_dr->text_pos_x = (int)(wolf->draw->x1) % BLOCK;
		else
			wall_dr->text_pos_x = (int)(wolf->draw->y1) % BLOCK;
		pos = (wolf->vect->pp_width - i) + j * wolf->vect->pp_width;
		tx_pos = wall_dr->text_pos_y * BLOCK + wall_dr->text_pos_x;
		wolf->mlx->img_d2[pos] = im_txt_dt[wall_dr->dir][tx_pos];
	}
	j--;
	while (++j < wolf->vect->pp_height)
		wolf->mlx->img_d2[(wolf->vect->pp_width - i) + j *
			wolf->vect->pp_width] = 0xA9A9A9;
}

void	draw_walls(t_wolf *wolf, int i, enum e_direction dir, int **im_text_dt)
{
	int			column;
	double		dx;
	double		dy;
	double		betta;
	t_wall_dr	wall_dr;

	wall_dr.dir = dir;
	dx = wolf->draw->x1 - wolf->draw->x0;
	dy = wolf->draw->y1 - wolf->draw->y0;
	betta = wolf->vect->pov_angle / 180.0 * M_PI;
	wall_dr.p = fabs(dx * cos(betta)) + fabs(dy * sin(betta));
	column = wolf->vect->pp_height * BLOCK * 2 / fabs(wall_dr.p);
	wall_dr.d_col = (wolf->vect->pp_height - column) / 2;
	draw_up_wall(wolf, im_text_dt, &wall_dr, i);
	draw_down_wall(wolf, im_text_dt, &wall_dr, i);
}
