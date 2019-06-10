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

int		arg1(int *i, char **argv)
{
	while (*i < 3)
	{
		if (argv[2][*i] == 0)
		{
			write(1, "Error: Unvalid size of map legend!!!\n", 37);
			write(1, "Usage: ./wolf3d [map] ", 22);
			write(1, "[map legend: wall/space/person]\n", 31);
			return (0);
		}
		if ((argv[2][*i] < ' ') || (argv[2][*i] > '~'))
		{
			write(1, "Error: Unvalid map legend!!!\n", 29);
			write(1, "Usage: ./wolf3d [map] ", 22);
			write(1, "[map legend: wall/space/person]\n", 31);
			return (0);
		}
		*i = *i + 1;
	}
	return (1);
}

int		arg_check(int argc, char **argv)
{
	int i;

	if (argc != 3)
		write(1, "Usage: ./wolf3d [map] [map legend: wall/space/person]\n", 54);
	if (argc != 3)
		return (0);
	i = 0;
	if (!arg1(&i, argv))
		return (0);
	if (argv[2][i] != 0)
	{
		write(1, "Error: Unvalid size of map legend!!!\n", 37);
		write(1, "Usage: ./wolf3d [map] [map legend: wall/space/person]\n", 54);
		return (0);
	}
	if ((argv[2][0] == argv[2][1]) ||
		(argv[2][0] == argv[2][2]) || (argv[2][1] == argv[2][2]))
	{
		write(1, "Error: Unvalid map legend!!!\n", 29);
		write(1, "Usage: ./wolf3d [map] [map legend: wall/space/person]\n", 54);
		return (0);
	}
	return (1);
}

void	texture_check(int x, int y)
{
	if (x != BLOCK || y != BLOCK)
	{
		write(1, "Invalid Textures\n", 17);
		exit(EXIT_SUCCESS);
	}
}
