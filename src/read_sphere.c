/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:47:12 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/09 01:47:59 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*create_sphere(char **line, t_scene *scene)
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		exit_error_msg(DEFAULT_ERR, scene);
	sphere->centre = get_vec3(line, scene);
	sphere->radius = get_double(line, scene) / 2;
	sphere->color = get_color_vec3(line, scene);
	skip_blanks(line);
	if (**line != EMPTY_LINE_GNL)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	return (sphere);
}

void		read_sphere(char **line, t_scene *scene)
{
	t_sphere	*sphere;
	t_lstobj	*new_obj;

	*line += ELEM_OBJ_LEN;
	sphere = create_sphere(line, scene);
	new_obj = lstobj_new(sphere, SPHERE);
	if(!new_obj)
		exit_error_msg(DEFAULT_ERR, scene);
	lstobj_append(&scene->objs, new_obj);
	return ;
}
