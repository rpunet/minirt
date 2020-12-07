/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:54:15 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/07 13:23:01 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	add_amb(t_scene *s, t_color point)
{
	t_color	color;

	color.r = s->amb.bright * s->amb.color.r * point.r / 255;
	color.g = s->amb.bright * s->amb.color.g * point.g / 255;
	color.b = s->amb.bright * s->amb.color.b * point.b / 255;
	return (color);
}

t_color	get_surface_data(t_scene *scene, t_hit *p)
{
	t_color	color;
	//t_ray	shadow;
	t_light	*light;
	//t_vec3	light_dir;

	light = scene->lights;

	color = add_amb(scene, p->color);
	while (light)
	{
		p->light = sub_vec3(light->pos, p->point);
		normalize_vec3(&p->light);

		p->shadow_ray.dir = p->light;
		p->shadow_ray.origin = p->point;


		if (!shadows(scene, &p->shadow_ray, light->pos))
			color = add_color(color, illuminate(light, p));


		light = light->next;
	}
	check_rgb_color(&color);
	return (color);
}
t_color	illuminate(t_light *light, t_hit *p)
{
	t_color	color;
	double	diffuse;
	//double	specular;
	double	kd;

	diffuse = dot_vec3(p->light, p->normal);
	if (diffuse < 0)
		kd = 0;
	else
		kd = light->lum;
								// aqui añadir speecular
	color.r = kd * light->color.r * (p->color.r * diffuse / 255);
	color.g = kd * light->color.g * (p->color.g * diffuse / 255);
	color.b = kd * light->color.b * (p->color.b * diffuse / 255);
	return (color);
}

t_color	add_color(t_color a, t_color b)
{
	t_color	color;

	color.r = a.r + b.r;
	color.g = a.g + b.g;
	color.b = a.b + b.b;
	return (color);
}

void	check_rgb_color(t_color *color)
{
	if (color->r > 255)
		color->r = 255;
	if (color->g > 255)
		color->g = 255;
	if (color->b > 255)
		color->b = 255;
}
