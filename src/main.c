/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 21:50:18 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/09 01:28:41 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_prueba_printf(t_scene scene)
{
	t_sphere	*sphere;
	t_plane		*plane;

	printf("%d\n", scene.res.x);
	printf("%d\n", scene.res.y);

	printf("%f\n", scene.amb.light);
	printf("%d\n", scene.amb.color.r);
	printf("%d\n", scene.amb.color.g);
	printf("%d\n", scene.amb.color.b);

	while (scene.cams)
	{
		printf("%f\n", scene.cams->cam->pos.y);
		printf("%f\n", scene.cams->cam->dir.z);
		printf("%f\n", scene.cams->cam->fov);
		printf("%d\n", scene.cam_count);
		scene.cams = scene.cams->next;
	}
	while (scene.lights)
	{
		printf("%f\n", scene.lights->light->pos.y);
		printf("%f\n", scene.lights->light->lum);
		printf("%d\n", scene.lights->light->color.g);
		scene.lights = scene.lights->next;
	}
	printf("\n\n\n");
	while (scene.objs)
	{
		if (scene.objs->obj_name == SPHERE)
		{
			sphere = scene.objs->obj;
			printf("%f,%f,%f    %f      %d,%d,%d\n", sphere->centre.x, sphere->centre.y, sphere->centre.z, sphere->radius, sphere->color.r, sphere->color.g, sphere->color.b);
		}
		if (scene.objs->obj_name == PLANE)
		{
			plane = scene.objs->obj;
			printf("%f,%f,%f    %f,%f,%f      %d,%d,%d\n", plane->point.x, plane->point.y, plane->point.z, plane->dir.x, plane->dir.y, plane->dir.z, plane->color.r, plane->color.g, plane->color.b);
		}
		scene.objs = scene.objs->next;
	}
	return ;
}

int		main(int argc, char **argv)
{
	int		save_bmp;
	t_scene	scene;

	save_bmp = 0;
	check_args(argc, argv, &save_bmp, &scene);
	scene_init(&scene);
	read_scene(argv[1], &scene);

	ft_prueba_printf(scene);
//_____________--------------------__________________------------__________
	scene_quit(&scene);
//	scene_lst_quit(&scene);
//_____-----------------------_________________--------------------____________

	return (0);
}
