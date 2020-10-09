/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:46:47 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/09 01:48:01 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_lstlight	*lstlight_new(t_light *light)
{
	t_lstlight	*new;

	if (!(new = malloc(sizeof(t_lstlight))))
		return (NULL);
	new->light = light;
	new->next = NULL;
	return (new);
}

void		lstlight_append(t_lstlight **lights, t_lstlight *new_light)
{
	t_lstlight	*last;

	if (!lights || !new_light)
		return ;
	if (!*lights)
	{
		*lights = new_light;
		return;
	}
	last = *lights;
	while (last->next)
		last = last->next;
	last->next = new_light;
}

t_light		*create_light(char **line, t_scene *scene)
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		exit_error_msg(DEFAULT_ERR, scene);
	light->pos = get_vec3(line, scene);
	light->lum = get_double(line, scene);
	if (light->lum < 0.0 || light->lum > 1.0)
		exit_error_msg(VALUE_RANGE_ERR, scene);
	light->color = get_color_vec3(line, scene);
	skip_blanks(line);
	if (**line != EMPTY_LINE_GNL)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	return (light);
}

void		read_light(char **line, t_scene *scene)
{
	t_light		*light;
	t_lstlight	*new_light;

	*line += ELEM_LEN;
	light = create_light(line, scene);
	new_light = lstlight_new(light);
	if (!new_light)
		exit_error_msg(DEFAULT_ERR, scene);
	lstlight_append(&scene->lights, new_light);
	return ;
}

void		delete_lights(t_lstlight **lights)
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
