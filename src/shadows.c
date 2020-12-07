/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:23:12 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/07 13:25:53 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	shadow_sphere(t_ray *shadow_ray, t_sphere *sphere, t_vec3 light_pos)
{
	t_vec3	sh_point;
	double	point_dist;
	double	light_dist;

	if ((shadow_ray->t = intersect_sphere(shadow_ray, sphere)))
	{
		sh_point = add_vec3(shadow_ray->origin, esc_vec3(shadow_ray->t, shadow_ray->dir));
		point_dist = mod_vec3(sub_vec3(sh_point, shadow_ray->origin));
		light_dist = mod_vec3(sub_vec3(light_pos, shadow_ray->origin));
		if (point_dist > 0.0001 && point_dist < light_dist)
			return (1);
	}
	return (0);
}

int	shadows(t_scene *scene, t_ray *shadow_ray, t_vec3 light_pos)
{
	void	*obj;

	obj = scene->spheres;
	while (obj)
	{
		if (shadow_sphere(shadow_ray, (t_sphere *)obj, light_pos))
			return (1);
		obj = ((t_sphere*)obj)->next;
	}
	obj = scene->planes;
	while (obj)
	{
		obj = ((t_plane*)obj)->next;
	}
	return (0);
}
