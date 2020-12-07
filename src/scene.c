/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 01:28:02 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/07 13:38:37 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scene_init(t_scene *scene)
{
	scene->mlx = mlx_init();
	scene->save_bmp = 0;
	scene->win = NULL;
	scene->res.declared = 0;
	scene->amb.declared = 0;
	scene->cams = NULL;
	scene->cam_count = 0;
	scene->lights = NULL;
	scene->spheres = NULL;
	scene->planes = NULL;


	//scene->objs = NULL;
}

void	scene_quit(t_scene *scene)
{
	delete_cameras(&scene->cams);
	delete_lights(&scene->lights);
	delete_spheres(&scene->spheres);

	//delete_lstobjects(&scene->objs);
}
