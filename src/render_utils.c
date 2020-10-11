/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 02:44:20 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/11 01:13:05 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	normalize(t_vec3 *v1)
{
	double	mod;

	mod = sqrt(v1->x * v1->x + v1->y * v1->y + v1->z * v1->z);
	v1->x /= mod;
	v1->y /= mod;
	v1->z /= mod;
}

t_vec3	new_vec3(double x, double y, double z)
{
	t_vec3	v1;

	v1.x = x;
	v1.y = y;
	v1.z = z;
	return (v1);
}

t_vec3	cross_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	t;

	t.x = u.y * v.z - u.z * v.y;
	t.y = u.z * v.x - u.x * v.z ;
	t.z = u.x * v.y - u.y * v.x;
	return (t);
}

double	det_mat3x3(t_mat3x3 m)
{
	double det;

	det = m.v1.x * m.v2.y * v3.z + v2.x * v3.y * v1.z + v1.y * v2.z * v3.x - v1.z * v2.y * v3.x - v1.y * v2.x * v3.z - v2.z * v3.y * v1.x;
	return (det);
}

t_mat3x3	invert_mat3x3(t_mat3x3 m)
{
	t_mat3x3 inv;
	double	 det;

	det = det_mat3x3(m);
	det = ft_det(m);
	inv.v1.x = (m.v2.y * m.v3.z - m.v2.z * m.v3.y) / det;
	inv.v1.y = -1 * (m.v1.y * m.v3.z - m.v1.z * m.v3.y) / det;
	inv.v1.z = (m.v1.y * m.v2.z - m.v1.z * m.v2.y) / det;
	inv.v2.x = -1 * (m.v2.x * m.v3.z - m.v2.z * m.v3.x) / det;
	inv.v2.y = (m.v1.x * m.v3.z - m.v1.z * m.v3.x) / det;
	inv.v2.z = -1 * (m.v1.x * m.v2.z - m.v1.z * m.v2.x) / det;
	inv.v3.x = (m.v2.x * m.v3.y - m.v2.y * m.v3.x) / det;
	inv.v3.y = -1 * (m.v1.x * m.v3.y - m.v1.y * m.v3.x) / det;
	inv.v3.z = (m.v1.x * m.v2.y - m.v1.y * m.v2.x) / det;
	return (inv);
}

