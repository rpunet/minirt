/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:39:45 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/08 14:18:54 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_elemtype	g_elemtype[] =
{
	{"R", 1, &read_resolution},
	{"A", 1, &read_ambient},
	{"c", 1, &read_camera},
	{"l", 1, &read_light},
	{"sp", 2, &read_sphere},
	{"pl", 2, &read_plane}
};

void	read_resolution(char **line, t_scene *scene)
{
	if (scene->res.declared)
		exit_error_msg(RES_DECLARED, scene);
	scene->res.declared = 1;
	*line += ELEM_LEN;
	scene->res.x = get_int(line, scene);
	scene->res.y = get_int(line, scene);
	return ;
}

void	read_ambient(char **line, t_scene *scene)
{
	if (scene->amb.declared)
		exit_error_msg(AMB_DECLARED, scene);
	scene->amb.declared = 1;
	(*line) += ELEM_LEN;
	scene->amb.light = get_double(line, scene);
	if (scene->amb.light < 0.0 || scene->amb.light > 1.0)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	scene->amb.color = get_color_vec3(line, scene);
	return ;
}

t_lstcam	*lstcam_new(t_cam *cam)
{
	t_lstcam	*new;

	if (!(new = malloc(sizeof(t_lstcam))))
		return (NULL);
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

t_cam	*create_camera(char **line, t_scene *scene)
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
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	return (cam);
}

void	read_camera(char **line, t_scene *scene)
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

t_light	*create_light(char **line, t_scene *scene)
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		exit_error_msg(DEFAULT_ERR, scene);
	light->pos = get_vec3(line, scene);
	light->lum = get_double(line, scene);
	if (light->lum < 0.0 || light->lum > 1.0)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	light->color = get_color_vec3(line, scene);
	return (light);
}

t_lstlight	*lstlight_new(t_light *light)
{
	t_lstlight	*new;

	if (!(new = malloc(sizeof(t_lstlight))))
		return (NULL);
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
	light = create_light(line, scene);
	new_light = lstlight_new(light);
	if (!new_light)
		exit_error_msg(DEFAULT_ERR, scene);
	lstlight_append(&scene->lights, new_light);
	return ;
}

t_sphere	*create_sphere(char **line, t_scene *scene)
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		exit_error_msg(DEFAULT_ERR, scene);
	sphere->centre = get_vec3(line, scene);
	sphere->radius = get_double(line, scene) / 2;
	sphere->color = get_color_vec3(line, scene);
	return (sphere);
}

t_lstobj	*lstobj_new(void *obj, t_objs obj_name)
{
	t_lstobj	*new;

	if(!(new = malloc(sizeof(t_lstobj))))
		return (NULL);
	new->obj_name = obj_name;
	new->obj = obj;
	new->next = NULL;
	return (new);
}

void	lstobj_append(t_lstobj **objs, t_lstobj *new_obj)
{
	t_lstobj	*last;

	if (!objs || !new_obj)
		return ;
	if (!*objs)
	{
		*objs = new_obj;
		return;
	}
	last = *objs;
	while (last->next)
		last = last->next;
	last->next = new_obj;
}

void	read_sphere(char **line, t_scene *scene)
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

t_plane	*create_plane(char **line, t_scene *scene)
{
	t_plane	*plane;

	if (!(plane = malloc(sizeof(t_plane))))
		exit_error_msg(DEFAULT_ERR, scene);
	plane->point = get_vec3(line, scene);
	plane->dir = get_vec3(line, scene);
	if (range_vec3(plane->dir, -1, 1))
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	plane->color = get_color_vec3(line, scene);
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
	exit_error_msg(SCENE_FORMAT_ERR, scene);
}

void	read_scene(char *file, t_scene *scene)
{
	int		fd;
	char	*line;
	char	*temp;
	int		bytes;

	fd = open(file, O_RDONLY);
	// if (fd == -1)
	// 	exit_error_msg(DEFAULT_ERROR, scene);
	while ((bytes = get_next_line(fd, &line)) > 0)
	{
		temp = line;
		read_element(&line, scene);
		free(temp);
	}
	free(line);



}
