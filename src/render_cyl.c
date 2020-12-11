/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cyl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 03:10:55 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/11 19:07:19 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	solve_quad(double a, double b, double discr)
{
	double	t;

	if (discr < 0)
		return (0);
	t = (-b - sqrt(discr)) / (2 * a);
	if (t < 0)
		t = 0;
	return (t);
}

double	intersect_tube(t_ray *ray, t_cyl *cyl)
{
	double	aux;
	double	a;
	double	b;
	double	c;
	t_vec3	oc;

	oc = sub_vec3(ray->origin, cyl->point);
	aux = dot_vec3(ray->dir, cyl->n_vec);
	a = 1 - aux * aux;
	aux = dot_vec3(oc, cyl->n_vec);
	b = 2 * (dot_vec3(ray->dir, oc) - dot_vec3(ray->dir, cyl->n_vec)
	* dot_vec3(oc, cyl->n_vec));
	c = dot_vec3(oc, oc) - aux * aux - cyl->radius * cyl->radius;
	return (solve_quad(a, b, b * b - 4 * a * c));
}

void	render_cyl(t_ray *ray, t_scene *scene, t_cyl *cyl)
{
	double	t;
	t_hit	p;

	if ((t = intersect_tube(ray, cyl)))
	{
		if (t < ray->t)
		{
			p.point = add_vec3(ray->origin, esc_vec3(t, ray->dir));
			p.cyl_m = dot_vec3(cyl->n_vec, sub_vec3(p.point, cyl->point));
			p.cyl_center = add_vec3(cyl->point, esc_vec3(p.cyl_m, cyl->n_vec));
			p.normal = sub_vec3(p.point, p.cyl_center);
			normalize_vec3(&p.normal);
			p.color = cyl->color;
			if (p.cyl_m > 0 && p.cyl_m < cyl->h)
			{
				ray->t = t;
				ray->color = get_surface_data(scene, &p);
				return ;
			}
		}
	}
	render_cyl_cap(ray, scene, cyl, &p);
}

void	render_cyl_cap(t_ray *ray, t_scene *scene, t_cyl *cyl, t_hit *p)
{
	double	t;
	t_plane	cap;

	cap.point = visible_cap(cyl, ray->origin);
	cap.n_dir = cyl->n_vec;
	if ((t = intersect_plane(ray, &cap)))
	{
		if (t < ray->t)
		{
			p->point = add_vec3(ray->origin, esc_vec3(t, ray->dir));
			if (mod_vec3(sub_vec3(p->point, cap.point)) < cyl->radius)
			{
				ray->t = t;
				p->normal = dot_vec3(cap.n_dir, ray->dir) < 0 ?
				cap.n_dir : esc_vec3(-1, cap.n_dir);
				normalize_vec3(&p->normal);
				p->color = cyl->color;
				ray->color = get_surface_data(scene, p);
				return ;
			}
		}
	}
}

t_vec3	visible_cap(t_cyl *cyl, t_vec3 origin)
{
	t_vec3	upper_point;
	double	dist1;
	double	dist2;

	upper_point = add_vec3(cyl->point, esc_vec3(cyl->h, cyl->n_vec));
	dist1 = mod_vec3(sub_vec3(origin, cyl->point));
	dist2 = mod_vec3(sub_vec3(origin, upper_point));
	if (dist1 > dist2)
		return (upper_point);
	return (cyl->point);
}
