/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 21:50:18 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/04 01:32:21 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scene_init(t_scene *scene)
{
	scene->res.declared = 0;
}

int		main(int argc, char **argv)
{
	int		save_bmp;
	t_scene	scene;

	save_bmp = 0;
	check_args(argc, argv, &save_bmp);
	scene_init(&scene);
	read_scene(argv[1], &scene);

	printf("%d\n", scene.res.x);
	printf("%d\n", scene.res.y);


	return (0);
}
