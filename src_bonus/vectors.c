/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 02:44:20 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/11 17:02:47 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	new_vec3(double x, double y, double z)
{
	t_vec3	v1;

	v1.x = x;
	v1.y = y;
	v1.z = z;
	return (v1);
}

t_vec3	sub_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	w;

	w.x = u.x - v.x;
	w.y = u.y - v.y;
	w.z = u.z - v.z;
	return (w);
}

t_vec3	add_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	w.z = u.z + v.z;
	return (w);
}

t_vec3	esc_vec3(double k, t_vec3 v)
{
	t_vec3 t;

	t.x = k * v.x;
	t.y = k * v.y;
	t.z = k * v.z;
	return (t);
}

double	dot_vec3(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}
