/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cameras.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:45:51 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/09 01:46:38 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_lstcam	*lstcam_new(t_cam *cam)
{
	t_lstcam	*new;

	if (!(new = malloc(sizeof(t_lstcam))))
		return (NULL);
	new->cam = cam;
	new->next = NULL;
	return (new);
}

void		lstcam_append(t_lstcam **cams, t_lstcam *new_cam)
{
	t_lstcam	*last;

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
	if (range_vec3(cam->dir, -1, 1))
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	cam->fov = get_double(line, scene);
	if (cam->fov < 0 || cam->fov > 180)
		exit_error_msg(FOV_RANGE_ERR, scene);
	skip_blanks(line);
	if (**line != EMPTY_LINE_GNL)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	return (cam);
}

void		read_camera(char **line, t_scene *scene)
{
	t_cam		*cam;
	t_lstcam	*new_cam;

	*line += ELEM_LEN;
	cam = create_camera(line, scene);
	new_cam = lstcam_new(cam);
	if (!new_cam)
		exit_error_msg(DEFAULT_ERR, scene);
	lstcam_append(&scene->cams, new_cam);
	scene->cam_count += 1;
	return ;
}

void		delete_cameras(t_lstcam **cams)
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
