/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 01:43:27 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/11 19:08:45 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_square(t_ray *ray, t_scene *scene, t_square *square)
{
	double	t;
	t_hit	p;
	t_plane	pl_sq;

	pl_sq.point = square->center;
	pl_sq.n_dir = square->n_dir;
	if ((t = intersect_plane(ray, &pl_sq)))
	{
		if (t < ray->t)
		{
			p.point = add_vec3(ray->origin, esc_vec3(t, ray->dir));
			if (in_square(square, p.point))
			{
				ray->t = t;
				p.normal = dot_vec3(pl_sq.n_dir, ray->dir) < 0 ?
				pl_sq.n_dir : esc_vec3(-1, pl_sq.n_dir);
				normalize_vec3(&p.normal);
				p.color = square->color;
				ray->color = get_surface_data(scene, &p);
				return ;
			}
		}
	}
}

int		in_square(t_square *square, t_vec3 point)
{
	t_vec3	x;
	t_vec3	y;

	x = (t_vec3){1, 0, 0};
	y = cross_vec3(square->n_dir, x);
	if (mod_vec3(y) == 0)
	{
		x = new_vec3(0, 1, 0);
		y = cross_vec3(square->n_dir, x);
	}
	normalize_vec3(&x);
	normalize_vec3(&y);
	if (ft_abs(dot_vec3(x, sub_vec3(point, square->center))) <= square->side
	&& ft_abs(dot_vec3(y, sub_vec3(point, square->center))) <= square->side)
		return (1);
	return (0);
}
