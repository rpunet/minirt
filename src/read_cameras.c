/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cameras.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:45:51 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/11 20:51:55 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		add_camera(t_cam **cams, t_cam *new_cam)
{
	t_cam	*last;

	if (!cams || !new_cam)
		return ;
	if (!*cams)
	{
		*cams = new_cam;
		return ;
	}
	last = *cams;
	while (last->next)
		last = last->next;
	last->next = new_cam;
}

t_cam		*create_camera(char **line, t_scene *scene)
{
	t_cam	*cam;

	if (!(cam = malloc(sizeof(t_cam))))
		exit_error_msg(DEFAULT_ERR, scene);
	cam->pos = get_vec3(line, scene);
	cam->dir = get_vec3(line, scene);
	if (range_vec3(cam->dir, -1.0, 1.0))
		exit_error_msg(VEC_RANGE_ERR, scene);
	normalize_vec3(&cam->dir);
	if (ft_isnull_vec3(cam->dir))
		exit_error_msg(NULL_VEC_ERR, scene);
	cam->fov = get_double(line, scene);
	if (cam->fov < 0 || cam->fov > 180)
		exit_error_msg(FOV_RANGE_ERR, scene);
	skip_blanks(line);
	if (**line != EMPTY_LINE_GNL)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	cam->next = NULL;
	return (cam);
}

void		read_camera(char **line, t_scene *scene)
{
	t_cam	*new_cam;

	*line += 2;
	new_cam = create_camera(line, scene);
	add_camera(&scene->cams, new_cam);
	scene->cam_count += 1;
	return ;
}

void		delete_cameras(t_cam **cams)
{
	t_cam	*current;
	t_cam	*node;

	if (!*cams || !cams)
		return ;
	current = *cams;
	while (current)
	{
		node = current->next;
		free(current);
		current = node;
	}
	*cams = NULL;
}

void		next_camera(t_scene *scene)
{
	t_cam	*current;

	if (scene->cams->next == NULL)
	{
		ft_printf("\r\nNo more cameras: EXIT\n");
		close_program(scene);
	}
	current = scene->cams->next;
	free(scene->cams);
	scene->cams = current;
}
