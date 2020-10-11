/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 21:50:18 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/11 02:46:36 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_prueba_printf(t_scene scene)
{
	t_sphere	*sphere;
	t_plane		*plane;

	printf("res x: %d\n", scene.res.width);
	printf("res y: %d\n", scene.res.height);

	printf("amb: %f\n", scene.amb.light);
	printf("color: %d, ", scene.amb.color.r);
	printf("%d, ", scene.amb.color.g);
	printf("%d\n", scene.amb.color.b);

	while (scene.cams)
	{
		printf("cam pos: %f, ", scene.cams->pos.y);
		printf("cam dir.z: %f, ", scene.cams->dir.z);
		printf("cam fov: %f\n", scene.cams->fov);
		printf("num cams: %d\n", scene.cam_count);
		scene.cams = scene.cams->next;
	}
	while (scene.lights)
	{
		printf("light pos.y: %f\n", scene.lights->pos.y);
		printf("light lum: %f\n", scene.lights->lum);
		printf("color gree: %d\n", scene.lights->color.g);
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
	//render_scene(&scene);

//_____________--------------------__________________------------__________
	ft_prueba_printf(scene);
//_____________--------------------__________________------------__________
	scene_quit(&scene);
	return (0);
}
