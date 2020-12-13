/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 01:02:32 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/13 01:53:50 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_plane(t_ray *ray, t_scene *scene, t_plane *plane)
{
	double	t;
	t_hit	p;

	if ((t = intersect_plane(ray, plane)))
	{
		if (t < ray->t)
		{
			ray->t = t;
			p.point = add_vec3(ray->origin, esc_vec3(ray->t, ray->dir));
			p.normal = plane->n_dir;
			normalize_vec3(&p.normal);
			p.color = plane->color;
			ray->color = get_surface_data(scene, &p);
		}
	}
}

double	intersect_plane(t_ray *ray, t_plane *plane)
{
	double	t;
	double	denom;

	denom = dot_vec3(ray->dir, plane->n_dir);
	if (fabs(denom) > 0.00001)
		t = dot_vec3(sub_vec3(plane->point,
		ray->origin), plane->n_dir) / denom;
	if (t >= 0)
		return (t);
	else
		return (0);
}
