/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 01:43:27 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/09 04:34:25 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_triangle(t_ray *ray, t_scene *scene, t_triangle *triangle)
{
	double	t;
	t_hit	p;
	t_plane	pl_tr;
	t_vec3	v1;
	t_vec3	v2;

	pl_tr.point = triangle->a;
	v1 = sub_vec3(triangle->b, triangle->a);
	v2 = sub_vec3(triangle->c, triangle->a);
	pl_tr.n_dir = cross_vec3(v2, v1);
	normalize_vec3(&pl_tr.n_dir);

	if ((t = intersect_plane(ray, &pl_tr)))
	{
		if (t < ray->t)
		{
			p.point = add_vec3(ray->origin, esc_vec3(t, ray->dir));
			if (in_triangle(triangle, p.point, pl_tr.n_dir))
			{
				ray->t = t;
				p.normal = dot_vec3(pl_tr.n_dir, ray->dir) < 0 ? pl_tr.n_dir : esc_vec3(-1, pl_tr.n_dir);				// quiza van al reves xXXXXXXXXXXXXXXXXXXXX ojoXXXXXXXXXXXXXXXXXXXXXOOOO        OJO !!!!!
				normalize_vec3(&p.normal);
				p.color = triangle->color;
				ray->color = get_surface_data(scene, &p);
				return ;
			}
		}
	}
}

int		in_triangle(t_triangle *triangle, t_vec3 point, t_vec3 normal)
{
	if (edge_side(triangle->b, triangle->a, point, normal) &&
	edge_side(triangle->c, triangle->b, point, normal) &&
	edge_side(triangle->a, triangle->c, point, normal))
		return (1);
	return (0);
}

int		edge_side(t_vec3 v1, t_vec3 v0, t_vec3 p, t_vec3 n)
{
	double	q;

	q = dot_vec3(n, cross_vec3(sub_vec3(v1, v0), sub_vec3(p, v0)));
	if (q < 0.0)
		return (1);
	return (0);
}

