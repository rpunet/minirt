/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:44:52 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/10 05:08:33 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	read_resolution(char **line, t_scene *scene)
{
	if (scene->res.declared)
		exit_error_msg(RES_DECLARED, scene);
	scene->res.declared = 1;
	*line += ELEM_LEN;
	scene->res.width = get_int(line, scene);
	scene->res.height = get_int(line, scene);
	skip_blanks(line);
	if (**line == EMPTY_LINE_GNL)
		return ;
	exit_error_msg(SCENE_FORMAT_ERR, scene);
}

void	read_ambient(char **line, t_scene *scene)
{
	if (scene->amb.declared)
		exit_error_msg(AMB_DECLARED, scene);
	scene->amb.declared = 1;
	(*line) += ELEM_LEN;
	scene->amb.light = get_double(line, scene);
	if (scene->amb.light < 0.0 || scene->amb.light > 1.0)
		exit_error_msg(VALUE_RANGE_ERR, scene);
	scene->amb.color = get_color_vec3(line, scene);
	skip_blanks(line);
	if (**line == EMPTY_LINE_GNL)
		return ;
	exit_error_msg(SCENE_FORMAT_ERR, scene);
}
