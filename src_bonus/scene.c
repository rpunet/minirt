/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 01:28:02 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/13 01:05:56 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scene_init(t_scene *scene)
{
	scene->save_bmp = 0;
	scene->specular = 0;
	scene->sepia = 0;
	scene->stereoscopy = 0;
	scene->obj_id = 0;
	scene->win = NULL;
	scene->res.declared = 0;
	scene->amb.declared = 0;
	scene->cams = NULL;
	scene->cam_count = 0;
	scene->lights = NULL;
	scene->spheres = NULL;
	scene->planes = NULL;
	scene->cyls = NULL;
	scene->squares = NULL;
	scene->triangles = NULL;
}

void	scene_quit(t_scene *scene)
{
	delete_cameras(&scene->cams);
	delete_lights(&scene->lights);
	delete_spheres(&scene->spheres);
	delete_planes(&scene->planes);
	delete_cyls(&scene->cyls);
	delete_squares(&scene->squares);
	delete_triangles(&scene->triangles);
}
