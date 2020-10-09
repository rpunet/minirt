/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 01:28:02 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/09 01:28:38 by rpunet           ###   ########.fr       */
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
	scene->objs = NULL;
}

void	scene_quit(t_scene *scene)
{
	delete_cameras(&scene->cams);
	delete_lights(&scene->lights);
	delete_objects(&scene->objs);
}
