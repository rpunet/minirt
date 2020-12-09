/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:23:12 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/09 02:50:44 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	block_light(t_ray *shadow_ray, t_vec3 light_pos)
{
	t_vec3	sh_point;
	double	point_dist;
	double	light_dist;

	sh_point = add_vec3(shadow_ray->origin, esc_vec3(shadow_ray->t, shadow_ray->dir));
	point_dist = mod_vec3(sub_vec3(sh_point, shadow_ray->origin));
	light_dist = mod_vec3(sub_vec3(light_pos, shadow_ray->origin));
	if (point_dist > 0.0001 && point_dist < light_dist)
		return (1);
	return (0);
}

int	shadows(t_scene *scene, t_ray *shadow_ray, t_vec3 light_pos)
{
	void	*obj;

	obj = scene->spheres;
	while (obj)
	{
		if ((shadow_ray->t = intersect_sphere(shadow_ray,(t_sphere *)obj)))
			if (block_light(shadow_ray, light_pos))
				return (1);
		obj = ((t_sphere*)obj)->next;
	}
	obj = scene->planes;
	while (obj)
	{
		if ((shadow_ray->t = intersect_plane(shadow_ray,(t_plane *)obj)))
			if (block_light(shadow_ray, light_pos))
				return (1);
		obj = ((t_plane*)obj)->next;
	}
	obj = scene->cyls;
	while (obj)
	{
		if ((shadow_ray->t = intersect_cyl(shadow_ray,(t_cyl *)obj)))
			if (block_light(shadow_ray, light_pos))
				return (1);
		obj = ((t_cyl *)obj)->next;
	}
	obj = scene->squares;
	while (obj)
	{
		if ((shadow_ray->t = intersect_square(shadow_ray,(t_square *)obj)))
			if (block_light(shadow_ray, light_pos))
				return (1);
		obj = ((t_square *)obj)->next;
	}
	return (0);
}

double	intersect_square(t_ray *ray, t_square *square)
{
	double	t;
	t_hit	p;
	t_plane	pl_sq;

	pl_sq.point = square->center;
	pl_sq.n_dir = square->n_dir;
	if ((t = intersect_plane(ray, &pl_sq)))
	{
		p.point = add_vec3(ray->origin, esc_vec3(t, ray->dir));
		if (in_square(square, p.point))
			return (t);
	}
	return (0);
}

double	intersect_cyl(t_ray *ray, t_cyl *cyl)
{
	double	t;
	t_hit	p;										   // quitar cap y reducir  ----------
	t_plane	cap;

	if ((t = intersect_tube(ray, cyl)))
	{

			p.point = add_vec3(ray->origin, esc_vec3(t, ray->dir));
			p.cyl_m = dot_vec3(cyl->n_vec, sub_vec3(p.point, cyl->point));
			if (p.cyl_m > 0 && p.cyl_m < cyl->h)
				return (t);

	}
	cap.point = visible_cap(cyl, ray->origin);
	cap.n_dir = cyl->n_vec;
	if ((t = intersect_plane(ray, &cap)))
	{

			p.point = add_vec3(ray->origin, esc_vec3(t, ray->dir));
			if (mod_vec3(sub_vec3(p.point, cap.point)) < cyl->radius)
				return (t);

	}
	return (0);
}
