/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 01:24:26 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/13 01:39:59 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_y_pos(t_scene *scene, int key)
{
	void	*obj;

	if (key == C)
	{
		obj = scene->cyls;
		((t_cyl *)obj)->point = add_vec3(((t_cyl *)obj)->point,
		new_vec3(0, 5, 0));
		push_image(scene);
	}
	if (key == S)
	{
		obj = scene->spheres;
		((t_sphere *)obj)->centre = add_vec3(((t_sphere *)obj)->centre,
		new_vec3(0, 5, 0));
		push_image(scene);
	}
}

void	move_y_neg(t_scene *scene, int key)
{
	void	*obj;

	if (key == C)
	{
		obj = scene->cyls;
		((t_cyl *)obj)->point = add_vec3(((t_cyl *)obj)->point,
		new_vec3(0, -5, 0));
		push_image(scene);
	}
	if (key == S)
	{
		obj = scene->spheres;
		((t_sphere *)obj)->centre = add_vec3(((t_sphere *)obj)->centre,
		new_vec3(0, -5, 0));
		push_image(scene);
	}
}

void	move_x_pos(t_scene *scene, int key)
{
	void	*obj;

	if (key == C)
	{
		obj = scene->cyls;
		((t_cyl *)obj)->point = add_vec3(((t_cyl *)obj)->point,
		new_vec3(5, 0, 0));
		push_image(scene);
	}
	if (key == S)
	{
		obj = scene->spheres;
		((t_sphere *)obj)->centre = add_vec3(((t_sphere *)obj)->centre,
		new_vec3(5, 0, 0));
		push_image(scene);
	}
}

void	move_x_neg(t_scene *scene, int key)
{
	void	*obj;

	if (key == C)
	{
		obj = scene->cyls;
		((t_cyl *)obj)->point = add_vec3(((t_cyl *)obj)->point,
		new_vec3(-5, 0, 0));
		push_image(scene);
	}
	if (key == S)
	{
		obj = scene->spheres;
		((t_sphere *)obj)->centre = add_vec3(((t_sphere *)obj)->centre,
		new_vec3(-5, 0, 0));
		push_image(scene);
	}
}

void	move_element(int keycode, t_scene *scene)
{
	if (keycode == RIGHT)
		move_x_pos(scene, scene->obj_id);
	if (keycode == LEFT)
		move_x_neg(scene, scene->obj_id);
	if (keycode == UP)
		move_y_pos(scene, scene->obj_id);
	if (keycode == DOWN)
		move_y_neg(scene, scene->obj_id);
}
