/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 21:50:18 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/11 20:48:33 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		close_program(t_scene *scene)
{
	mlx_destroy_window(scene->mlx, scene->win);
	scene_quit(scene);
	exit(EXIT_SUCCESS);
	return (0);
}

int		key_hook(int keycode, t_scene *scene)
{
	if (keycode == ESC)
	{
		ft_printf("\n\nAborted\n");
		close_program(scene);
	}
	if (keycode == SPACE)
	{
		next_camera(scene);
		render_scene(scene);
		mlx_clear_window(scene->mlx, scene->win);
		mlx_put_image_to_window(scene->mlx, scene->win, scene->img, 0, 0);
	}
	return (0);
}

void	display_scene(t_scene *scene)
{
	t_img	img;

	scene->mlx = mlx_init();
	scene->win = mlx_new_window(scene->mlx, scene->res.width,
	scene->res.height, "miniRT");
	scene->img = mlx_new_image(scene->mlx, scene->res.width, scene->res.height);
	scene->img_address = mlx_get_data_addr(scene->img,
	&img.bbp, &img.size_line, &img.endian);
	mlx_hook(scene->win, CLOSE, 0L, close_program, scene);
	mlx_key_hook(scene->win, key_hook, scene);
	render_scene(scene);
	mlx_clear_window(scene->mlx, scene->win);
	mlx_put_image_to_window(scene->mlx, scene->win, scene->img, 0, 0);
	mlx_loop(scene->mlx);
}

int		main(int argc, char **argv)
{
	t_scene	scene;

	scene_init(&scene);
	check_args(argc, argv, &scene);
	read_scene(argv[1], &scene);
	if (scene.save_bmp)
		save_image_bmp(&scene);
	else
		display_scene(&scene);
	scene_quit(&scene);
	return (0);
}
