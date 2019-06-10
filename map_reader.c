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

void	map_error_message(void)
{
	write(1, "Invalid Map\nBorders incorrect\n", 30);
	exit(EXIT_SUCCESS);
}

void	character_error_message(void)
{
	write(1, "Invalid Map\nCheck character position\n", 37);
	exit(EXIT_SUCCESS);
}

void	readfileassistent(int **i_map, t_wolf *wolf, t_culcmup *rf)
{
	if (rf->c == wolf->map->symbols[0])
		i_map[rf->i][rf->j] = 1;
	if (rf->c == wolf->map->symbols[1] || rf->c == wolf->map->symbols[2])
	{
		i_map[rf->i][rf->j] = 0;
		if (rf->c == wolf->map->symbols[2])
		{
			wolf->vect->x = rf->j * BLOCK + BLOCK / 2;
			wolf->vect->y = rf->i * BLOCK + BLOCK / 2;
		}
	}
	if ((rf->i == 0 || rf->i == (wolf->map->height - 1)) &&
		(rf->c != '\n') && (i_map[rf->i][rf->j] == 0))
		map_error_message();
	else if ((rf->j == 0 || rf->j == (wolf->map->width - 1)) &&
			(rf->c != '\n') && (i_map[rf->i][rf->j] == 0))
		map_error_message();
	rf->j++;
	if (rf->c == '\n')
	{
		rf->j = 0;
		rf->i++;
	}
}

void	read_file(int fd, int **i_map, t_wolf *wolf)
{
	t_culcmup rf;

	rf.j = 0;
	rf.i = 0;
	while (read(fd, &rf.c, 1))
	{
		readfileassistent(i_map, wolf, &rf);
	}
}

int		**read_map(int fd, t_wolf *wolf)
{
	int		i;
	int		**i_map;

	i_map = (int **)malloc(sizeof(int *) * wolf->map->height);
	i = 0;
	while (i < wolf->map->height)
	{
		i_map[i] = (int *)malloc(sizeof(int) * wolf->map->width);
		i++;
	}
	read_file(fd, i_map, wolf);
	return (i_map);
}
