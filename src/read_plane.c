/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:49:16 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/09 01:48:00 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*create_plane(char **line, t_scene *scene)
{
	t_plane	*plane;

	if (!(plane = malloc(sizeof(t_plane))))
		exit_error_msg(DEFAULT_ERR, scene);
	plane->point = get_vec3(line, scene);
	plane->dir = get_vec3(line, scene);
	if (range_vec3(plane->dir, -1.0, 1.0))
		exit_error_msg(VEC_RANGE_ERR, scene);
	plane->color = get_color_vec3(line, scene);
	skip_blanks(line);
	if (**line != EMPTY_LINE_GNL)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	return (plane);
}

void	read_plane(char **line, t_scene *scene)
{
	t_plane		*plane;
	t_lstobj	*new_obj;

	*line += ELEM_OBJ_LEN;
	plane = create_plane(line, scene);
	new_obj = lstobj_new(plane, PLANE);
	if (!new_obj)
		exit_error_msg(DEFAULT_ERR, scene);
	lstobj_append(&scene->objs, new_obj);
	return ;
}
