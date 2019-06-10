/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:57:04 by htorp             #+#    #+#             */
/*   Updated: 2019/05/12 13:54:53 by bwynton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	first_inic(t_wolf *wolf, int fd, char *file_name)
{
	fd = open(file_name, O_RDONLY);
	wolf->map->i_map = read_map(fd, wolf);
	close(fd);
	wolf->mouse->down = 0;
	wolf->mouse->sense = 4;
	wolf->vect->pov_angle = 0.0;
	wolf->vect->view_angle = 60.0;
	wolf->vect->pp_width = 2550;
	wolf->vect->pp_height = 1275;
	wolf->vect->h_center = wolf->vect->pp_height / 2;
	wolf->vect->center_cor = 0;
	wolf->vect->dir_x = 1;
	wolf->vect->dir_y = 1;
	wolf->vect->map_flag = 0;
	wolf->mlx->bpp = 8;
	wolf->mlx->sl = 0;
	wolf->mlx->en = 0;
	wolf->mlx->mlx_ptr = mlx_init();
	wolf->mlx->win_ptr = mlx_new_window(wolf->mlx->mlx_ptr,
			SIZE_X, SIZE_Y, "Wolf");
}

void	hooks(t_wolf *wolf)
{
	mlx_hook(wolf->mlx->win_ptr, 2, 0, key_press, (void*)wolf);
	mlx_hook(wolf->mlx->win_ptr, 17, 0, mouse_close, (void *)wolf);
	mlx_hook(wolf->mlx->win_ptr, 5, 0, mouse_release, (void *)wolf);
	mlx_hook(wolf->mlx->win_ptr, 4, 0, mouse_press, (void *)wolf);
	mlx_hook(wolf->mlx->win_ptr, 6, 0, mouse_move, (void *)wolf);
}

void	get_textures(t_wolf *wolf)
{
	void	**im_ptr_text;
	int		x;
	int		y;
	int		i;

	im_ptr_text = (void**)malloc(sizeof(void*) * 4);
	wolf->im_text_data = (int**)malloc(sizeof(int*) * 4);
	im_ptr_text[EAST] = mlx_xpm_file_to_image(wolf->mlx->mlx_ptr,
			"E1.xpm", &x, &y);
	texture_check(x, y);
	im_ptr_text[NORTH] = mlx_xpm_file_to_image(wolf->mlx->mlx_ptr,
			"N1.xpm", &x, &y);
	texture_check(x, y);
	im_ptr_text[SOUTH] = mlx_xpm_file_to_image(wolf->mlx->mlx_ptr,
			"S1.xpm", &x, &y);
	texture_check(x, y);
	im_ptr_text[WEST] = mlx_xpm_file_to_image(wolf->mlx->mlx_ptr,
			"W1.xpm", &x, &y);
	texture_check(x, y);
	i = -1;
	while (i++ < 3)
		wolf->im_text_data[i] = (int*)mlx_get_data_addr(im_ptr_text[i],
				&wolf->mlx->bpp, &wolf->mlx->sl, &wolf->mlx->en);
	free(im_ptr_text);
}

t_wolf	*wolf_malloc(void)
{
	t_wolf		*wolf;

	wolf = (t_wolf*)malloc(sizeof(t_wolf));
	wolf->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	wolf->mlx->img_ptr = NULL;
	wolf->mlx->img_ptr2 = NULL;
	wolf->vect = (t_vector*)malloc(sizeof(t_vector));
	wolf->mouse = (t_mouse*)malloc(sizeof(t_mouse));
	wolf->proj = (t_proj*)malloc(sizeof(t_proj));
	wolf->draw = (t_draw*)malloc((sizeof(t_draw)));
	return (wolf);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_wolf		*wolf;

	if (!arg_check(argc, argv))
		return (0);
	wolf = wolf_malloc();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Unexistable map!\n", 17);
		return (0);
	}
	wolf->map = culc_mup_size(fd, argv[2]);
	close(fd);
	first_inic(wolf, fd, argv[1]);
	get_textures(wolf);
	redraw(wolf, wolf->im_text_data, wolf->mlx);
	hooks(wolf);
	mlx_loop(wolf->mlx->mlx_ptr);
	return (0);
}
