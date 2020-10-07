/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:39:45 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/07 02:07:55 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_elemtype	g_elemtype[] =
{
	{"R", 1, &read_resolution},
	{"A", 1, &read_ambient},
	{"c", 1, &read_camera}
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

t_cam	*new_camera(char **line)
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
	cam = new_camera(line);
	new_cam = lstcam_new(cam);
	lstcam_append(&scene->cams, new_cam);
	scene->cam_count += 1;
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
