/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 21:50:18 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/07 21:03:04 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	scene_init(t_scene *scene)
{

	scene->res.declared = 0;
	scene->amb.declared = 0;
	scene->cams = NULL;
	scene->cam_count = 0;
	scene->lights = NULL;
}

void	ft_prueba_printf(t_scene scene)
{
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
}

void	delete_cameras(t_lstcam **cams)
{
	t_lstcam	*current;
	t_lstcam	*node;

	if (!*cams || !cams)
		return ;
	current = *cams;
	while (current)
	{
		free(current->cam);
		node = current;
		current = current->next;
		free(node);
	}
	*cams = NULL;
}

void	delete_lights(t_lstlight **lights)
{
	t_lstlight	*current;
	t_lstlight	*node;

	if (!lights || !*lights)
		return ;
	current = *lights;
	while (current)
	{
		free(current->light);
		node = current;
		current = current->next;
		free(node);
	}
	*lights = NULL;
}

void	scene_quit(t_scene *scene)
{
	delete_cameras(&scene->cams);
	delete_lights(&scene->lights);
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
