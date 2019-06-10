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

void	readculcmapfunc(int fd, t_map *map, t_culcmup *culcmup)
{
	while (read(fd, &culcmup->c, 1))
	{
		if (((culcmup->c == map->symbols[0]) || (culcmup->c == map->symbols[1])
				|| culcmup->c == map->symbols[2]))
			culcmup->i++;
		if (culcmup->c == map->symbols[2])
			culcmup->count++;
		if (culcmup->c == '\n')
		{
			if (culcmup->first_read)
			{
				map->width = culcmup->i;
				culcmup->first_read = 0;
				culcmup->i = 0;
			}
			else if (culcmup->i == map->width)
				culcmup->i = 0;
			else
				map_error_message();
			culcmup->j++;
		}
	}
}

int		add_culc_map(int fd, t_map *map)
{
	t_culcmup culcmup;

	culcmup.first_read = 1;
	culcmup.i = 0;
	culcmup.j = 0;
	culcmup.count = 0;
	readculcmapfunc(fd, map, &culcmup);
	if (culcmup.count != 1)
		character_error_message();
	return (culcmup.j);
}

t_map	*culc_mup_size(int fd, char *str)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->symbols = ft_strdup(str);
	map->height = add_culc_map(fd, map);
	check_size(map);
	return (map);
}
