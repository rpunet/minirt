/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:39:45 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/07 13:47:34 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_elemtype	g_elemtype[] =
{
	{"R", 1, &read_resolution},
	{"A", 1, &read_ambient},
	{"c", 1, &read_camera},
	{"l", 1, &read_light}
};

void	read_resolution(char **line, t_scene *scene)
{
	if (scene->res.declared)
		exit_error_msg(RES_DECLARED);
	scene->res.declared = 1;
	*line += ELEM_LEN;
	scene->res.x = get_int(line);
	scene->res.y = get_int(line);
	return ;
}

void	read_ambient(char **line, t_scene *scene)
{
	if (scene->amb.declared)
		exit_error_msg(AMB_DECLARED);
	scene->amb.declared = 1;
	(*line) += ELEM_LEN;
	scene->amb.light = get_double(line);
	if (scene->amb.light < 0.0 || scene->amb.light > 1.0)
		exit_error_msg(SCENE_FORMAT_ERR);
	scene->amb.color = get_color_vec3(line);
	return ;
}

t_lstcam	*lstcam_new(t_cam *cam)
{
	t_lstcam	*new;

	if (!(new = malloc(sizeof(t_lstcam))))
		exit_error_msg(DEFAULT_ERR);
	new->cam = cam;
	new->next = NULL;
	return (new);
}

void	lstcam_append(t_lstcam **cams, t_lstcam *new_cam)
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

t_cam	*create_camera(char **line)
{

	t_cam	*cam;

	if (!(cam = malloc(sizeof(t_cam))))
		exit_error_msg(DEFAULT_ERR);
	cam->pos = get_vec3(line);
	cam->dir = get_vec3(line);
	if (range_vec3(cam->dir, -1, 1))
		exit_error_msg(SCENE_FORMAT_ERR);
	cam->fov = get_double(line);
	if (cam->fov < 0 || cam->fov > 180)
		exit_error_msg(SCENE_FORMAT_ERR);
	return (cam);
}

void	read_camera(char **line, t_scene *scene)
{
	t_cam		*cam;
	t_lstcam	*new_cam;

	*line += ELEM_LEN;
	cam = create_camera(line);
	new_cam = lstcam_new(cam);
	lstcam_append(&scene->cams, new_cam);
	scene->cam_count += 1;
	return ;
}

t_light	*create_light(char **line)
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		exit_error_msg(DEFAULT_ERR);
	light->pos = get_vec3(line);
	light->lum = get_double(line);
	if (light->lum < 0.0 || light->lum > 1.0)
		exit_error_msg(SCENE_FORMAT_ERR);
	light->color = get_color_vec3(line);
	return (light);
}

t_lstlight	*lstlight_new(t_light *light)
{
	t_lstlight	*new;

	if (!(new = malloc(sizeof(t_lstlight))))
		exit_error_msg(DEFAULT_ERR);
	new->light = light;
	new->next = NULL;
	return (new);
}

void	lstlight_append(t_lstlight **lights, t_lstlight *new_light)
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

void	read_light(char **line, t_scene *scene)
{
	t_light		*light;
	t_lstlight	*new_light;

	*line += ELEM_LEN;
	light = create_light(line);
	new_light = lstlight_new(light);
	lstlight_append(&scene->lights, new_light);
	return ;

}

void	read_element(char **line, t_scene *scene)
{
	int	i;

	i = 0;
	while (i < SCENE_ELEMENTS)
	{
		if (!ft_strncmp(*line, g_elemtype[i].type_id, g_elemtype[i].id_len))
		{
			g_elemtype[i].read_func(line, scene);

			return ;
		}
		if (**line == EMPTY_LINE_GNL)
			return ;
		i++;
	}
	exit_error_msg(SCENE_FORMAT_ERR);

}

void	read_scene(char *file, t_scene *scene)
{
	int		fd;
	char	*line;
	char	*temp;
	int		bytes;

	fd = open(file, O_RDONLY);
	// if (fd == -1)
	// 	exit_error_msg(DEFAULT_ERR);
	while ((bytes = get_next_line(fd, &line)) > 0)
	{
		temp = line;
		read_element(&line, scene);
		free(temp);
	}
	free(line);



}
