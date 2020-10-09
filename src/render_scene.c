/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 01:54:35 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/09 02:41:08 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	raytrace(int x, int y, t_res *res)
{
	t_vec3	ray;
	double	aspect_ratio;

	aspect_ratio = res->width / res->height;
	ray.x = (2 * ((x + 0.5) / res->width) -1) * tan(fov / 2 * M_PI / 180) * aspect_ratio;
	ray.y = (1 - 2 * (y + 0.5) / res->height) * tan(fov / 2 * M_PI / 180);
	return (ray);

}


void	render(t_scene *scene)
{
	char	*buffer;
	int		x;
	int		y;
	t_vec3	ray;

	y = 0;
	while (y < scene->res.height)
	{
		x = 0;
		while (x < scene->res.width)
		{
			ray = raytrace(x, y, &scene->res);


			x++;
		}
		y++;
	}



}
