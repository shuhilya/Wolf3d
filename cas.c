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

#include "fdf.h"

void	change_pixel(t_draw *draw, t_image *image)
{
	draw->i++;
	if (draw->i % 2 == 0)
	{
		draw->tmp = ipart(draw->in + 1);
		ft_put_pixel(draw, image);
	}
	else
	{
		draw->tmp = ipart(draw->in);
		ft_put_pixel(draw, image);
	}
}

void	swap_int(int *color0, int *color1)
{
	int	c;

	c = *color0;
	*color0 = *color1;
	*color1 = c;
}

int		ipart(double x)
{
	return ((int)x);
}

int		ft_round(double x)
{
	return (ipart(x + 0.5));
}

double	fpart(double x)
{
	return (x - ipart(x));
}
