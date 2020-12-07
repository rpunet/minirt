/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 01:54:35 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/08 00:55:15 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	look_at(t_cam *cam)
{
	t_vec3	c_dir;

	c_dir = cam->dir;

	cam->cam_to_world.v1.z = 0;
	if (!c_dir.x && !c_dir.y)
	{
		cam->cam_to_world.v1.y = 0;
		if (c_dir.z > 0)
			cam->cam_to_world.v1.x = -1.0;
		else if (c_dir.z < 0)
			cam->cam_to_world.v1.x = 1.0;
		//else if (!c_dir.z)
	}
	else
	{
		cam->cam_to_world.v1.x = c_dir.y;
		cam->cam_to_world.v1.y = -1.0 * c_dir.x;
	}
	cam->cam_to_world.v2 = cross_vec3(cam->cam_to_world.v1, c_dir);
	cam->cam_to_world.v3 = esc_vec3(-1, c_dir);
	normalize_vec3(&cam->cam_to_world.v1);
	normalize_vec3(&cam->cam_to_world.v2);
	normalize_vec3(&cam->cam_to_world.v3);
}

void	set_ray(t_ray *ray, t_scene *scene, double x, double y)
{
	double	aspect_ratio;

	aspect_ratio = (double)scene->res.width / (double)scene->res.height;
	ray->dir.x = (2 * ((x + 0.5) / scene->res.width) -1) * tan(scene->cams->fov / 2 * 3.1415 / 180) * aspect_ratio;
	ray->dir.y = (1 - 2 * (y + 0.5) / scene->res.height) * tan(scene->cams->fov / 2 * 3.1415 / 180);
	ray->dir.z = -1;
	ray->dir = mult_vec3_mat3x3(ray->dir, scene->cams->cam_to_world);
	normalize_vec3(&ray->dir);
	ray->t = DBL_MAX;
	ray->color = (t_color){0, 0, 0};
	ray->origin = scene->cams->pos;
	cast_ray(ray, scene);
}

void	cast_ray(t_ray *ray, t_scene *scene)
{
	void	*objs;

	objs = scene->spheres;
	while (objs)
	{
		render_sphere(ray, scene, (t_sphere *)objs);
		objs = ((t_sphere *)objs)->next;
	}
/* 	objs = scene->planes;
	while (objs)
	{
		render_plane(ray, scene, (t_plane *)objs);
		objs = ((t_plane *)objs)->next;
	} */
}

void	render_sphere(t_ray *ray, t_scene *scene, t_sphere *sphere)
{
	double	t;
	t_hit	p;

	if ((t = intersect_sphere(ray, sphere)))         //< ray->t  && t != 0)				// se puede borrar el != 0
	{
		if (t < ray->t)
		{
			ray->t = t;
			p.point = add_vec3(ray->origin, esc_vec3(ray->t, ray->dir));
			p.normal = sub_vec3(p.point, sphere->centre);
			normalize_vec3(&p.normal);
			p.color = sphere->color;
			ray->color = get_surface_data(scene, &p);
		}
	}
}

double	intersect_sphere(t_ray *ray, t_sphere *sphere)
{
	double	t;
	t_vec3	oc;
	double	tca;
	double	d2;

	oc = sub_vec3(sphere->centre, ray->origin);
	tca = dot_vec3(oc, ray->dir);
	if (tca < 0)
		return (0);
	d2 = dot_vec3(oc, oc) - tca * tca;
	if (d2 > sphere->radius * sphere->radius)
		return (0);
	t = tca - sqrt(sphere->radius * sphere->radius - d2);
	return (t);
}



void	render_scene(t_scene *scene, t_img *img)
{
	t_ray	ray;
	char	*buffer;
	int		x;
	int		y;

	look_at(scene->cams);
	buffer = img->address;
	y = 0;
	while (y < scene->res.height)
	{
		x = 0;
		while (x < scene->res.width)
		{
			set_ray(&ray, scene, (double)x, (double)y);

			//put_pixel_to_image......>>

			save_pixel(&buffer, ray.color);
			x++;
		}
		y++;
	}
}

void	save_pixel(char **buffer, t_color color)
{
	**buffer = (char)floor(color.b);
	(*buffer)++;
	**buffer = (char)floor(color.g);
	(*buffer)++;
	**buffer = (char)floor(color.r);
	(*buffer)++;
	(*buffer)++;

}
/*{
	*buffer = (char)floor(color.b);
	buffer++;
	*buffer = (char)floor(color.g);
	buffer++;
	*buffer = (char)floor(color.r);
	buffer++;
	buffer++;
} */



/*
	ray.origin = cam->pos;



	t_cam 	*current;
	t_img	*img;

	current = scene->cams;
	while (current)
	{
		img = create_image(scene);
		raytrace(current, img, scene);
		current = current->next;
	}
}

t_img	*create_image(t_scene *scene)
{
	t_img	*img;
	t_hit	obj;



	if (!(img = malloc(sizeof(t_mlx))))
		exit_error_msg(DEFAULT_ERR, scene);
	img->size_x = scene->res.width;
	img->size_y = scene->res.height;
	img->img = mlx_new_image(scene->mlx, img->size_x, img->size_y);
	img->address = mlx_get_data_addr(img->img, &img->bbp, &img->size_line, &img->endian);
	imgg->next = NULL;
	return (img);
}


 */
