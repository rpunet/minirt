/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 21:50:18 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/04 21:38:35 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scene_init(t_scene *scene)
{
	scene->res.declared = 0;
	scene->amb.declared = 0;
}

int		main(int argc, char **argv)
{
	int		save_bmp;
	t_scene	scene;

	save_bmp = 0;
	check_args(argc, argv, &save_bmp);
	scene_init(&scene);
	read_scene(argv[1], &scene);

//_____________--------------------__________________------------__________

	printf("%d\n", scene.res.x);
	printf("%d\n", scene.res.y);

	printf("%f\n", scene.amb.light);
	printf("%d\n", scene.amb.color.r);
	printf("%d\n", scene.amb.color.g);
	printf("%d\n", scene.amb.color.b);






	return (0);
}
