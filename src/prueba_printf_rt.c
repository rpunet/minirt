/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_printf_rt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:39:17 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/10 00:39:37 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_prueba_printf(t_scene scene)
{
//	t_sphere	*sphere;
//	t_plane		*plane;

	printf("res x: %d\n", scene.res.width);
	printf("res y: %d\n", scene.res.height);

	printf("amb: %f\n", scene.amb.bright);
	printf("color: %f, ", scene.amb.color.r);
	printf("%f, ", scene.amb.color.g);
	printf("%f\n", scene.amb.color.b);

	while (scene.cams)
	{
		printf("cam pos: %f, ", scene.cams->pos.y);
		printf("cam dir.z: %f, ", scene.cams->dir.z);
		printf("cam fov: %f\n", scene.cams->fov);
		printf("num cams: %d\n", scene.cam_count);
		scene.cams = scene.cams->next;
	}
	while (scene.lights)
	{
		printf("light pos.y: %f\n", scene.lights->pos.y);
		printf("light lum: %f\n", scene.lights->lum);
		printf("color green: %f\n", scene.lights->color.g);
		scene.lights = scene.lights->next;
	}
	printf("\n\n\n");
/* 	while (scene.objs)
	{
		if (scene.objs->obj_name == SPHERE)
		{
			sphere = scene.objs->obj;
			printf("%f,%f,%f    %f      %d,%d,%d\n", sphere->centre.x, sphere->centre.y, sphere->centre.z, sphere->radius, sphere->color.r, sphere->color.g, sphere->color.b);
		}
		if (scene.objs->obj_name == PLANE)
		{
			plane = scene.objs->obj;
			printf("%f,%f,%f    %f,%f,%f      %d,%d,%d\n", plane->point.x, plane->point.y, plane->point.z, plane->dir.x, plane->dir.y, plane->dir.z, plane->color.r, plane->color.g, plane->color.b);
		}
		scene.objs = scene.objs->next;
	} */
	return ;
}
