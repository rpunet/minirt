/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 01:54:35 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/11 03:07:33 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mat3x3	cam_to_world(t_vec3 cam_dir)
{
	t_mat3x3	world_to_cam;
	t_vec3		right;
	t_vec3		up;
	t_vec3		forward;
	t_vec3		up_vector;

	forward = cam_dir;
	up_vector = new_vec3(0.0, 1.0, 0.0);
	normalize(&up_vector);
	if (cam_dir.y == 1)
		right = new_vec3(1.0, 0.0, 0.0);
	else if (cam_dir.y == -1)
		right = new_vec3(-1.0, 0.0, 0.0);
	else
		right = cross_vec3(up_vector, cam_dir);
	up = cross_vec3(forward, right);
	world_to_cam.v1 = right;
	world_to_cam.v2 = up;
	world_to_cam.v3 = forward;
	return (invert_mat3x3(world_to_cam));
}

void	look_at(t_cam *cam)
{
	cam->cam_to_world = cam_to_world(cam->dir);
}

void	set_ray(t_ray *ray, int x, int y, t_res *res, t_cam *cam, )
{
	t_vec3	l_ray;
	double	aspect_ratio;

	aspect_ratio = res->width / res->height;
	l_ray.dir.x = (2 * ((x + 0.5) / res->width) -1) * tan(cam->fov / 2 * M_PI / 180) * aspect_ratio;
	l_ray.dir.y = (1 - 2 * (y + 0.5) / res->height) * tan(cam->fov / 2 * M_PI / 180);
	normalize(ray);

}
}




t_vec3	raytrace(t_cam *cam, t_img *img, t_scene *scene)
{
	t_ray	ray;
	int		x;
	int		y;

	look_at(cam);
	ray.origin = cam->pos;
	y = 0;
	while (y < scene->res.height)
	{
		x = 0;
		while (x < scene->res.width)
		{
			set_ray(&ray, x, y, &scene->res,&);


			put_pixel_to_image

			x++;
		}
		y++;
	}



}





t_img	*create_image(t_scene *scene)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_mlx))))
		exit_error_msg(DEFAULT_ERR, scene);
	img->size_x = scene->res.width;
	img->size_y = scene->res.height;
	img->img = mlx_new_image(scene->mlx, img->size_x, img->size_y);
	img->address = mlx_get_data_addr(img->img, &img->bbp, &img->size_line, &img->endian);
	imgg->next = NULL;
	return (img);

}

void	render(t_scene *scene)
{
	t_cam 	*current;
	t_img	*img;

	current = scene->cams;
	while (current)
	{
		img = create_image(scene);
		raytrace(current, img, scene);
		current = current->next;
	}


}





