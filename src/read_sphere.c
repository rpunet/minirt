/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:47:12 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/08 03:04:58 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		add_sphere(t_sphere **spheres, t_sphere *new_sphere)
{
	t_sphere	*last;

	if (!spheres || !new_sphere)
		return ;
	if (!*spheres)
	{
		*spheres = new_sphere;
		return ;
	}
	last = *spheres;
	while (last->next)
		last = last->next;
	last->next = new_sphere;
}

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
	sphere->next = NULL;
	return (sphere);
}

void		read_sphere(char **line, t_scene *scene)
{
	t_sphere	*new_sphere;

	*line += 3;
	new_sphere = create_sphere(line, scene);
	add_sphere(&scene->spheres, new_sphere);
	return ;
}

void		delete_spheres(t_sphere **spheres)
{
	t_sphere	*current;
	t_sphere	*node;

	if (!*spheres || !spheres)
		return ;
	current = *spheres;
	while (current)
	{
		node = current->next;
		free(current);
		current = node;
	}
	*spheres = NULL;
}
