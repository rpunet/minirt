/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 20:40:39 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/11 20:46:00 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	save_image_bmp(t_scene *scene)
{
	int	fd;

	if (!(scene->img_address = malloc(sizeof(char)
	* 4 * scene->res.width * scene->res.height)))
		exit_error_msg(DEFAULT_ERR, scene);
	render_scene(scene);
	if ((fd = open("minirt.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0744)) == -1)
		exit_error_msg(DEFAULT_ERR, scene);
	header_data(fd, scene);
	pixel_data(fd, scene);
	close(fd);
	free(scene->img_address);
}

void	header_data(int fd, t_scene *scene)
{
	unsigned char	header[54];
	int				i;

	i = 0;
	while (i < 54)
		header[i++] = (unsigned char)0;
	header[0] = 'B';
	header[1] = 'M';
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(scene->res.width);
	header[19] = (unsigned char)(scene->res.width >> 8);
	header[20] = (unsigned char)(scene->res.width >> 16);
	header[21] = (unsigned char)(scene->res.width >> 24);
	header[22] = (unsigned char)(scene->res.height);
	header[23] = (unsigned char)(scene->res.height >> 8);
	header[24] = (unsigned char)(scene->res.height >> 16);
	header[25] = (unsigned char)(scene->res.height >> 24);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	write(fd, header, 54);
}

void	pixel_data(int fd, t_scene *scene)
{
	int	i;

	i = scene->res.height;
	while (i--)
	{
		write(fd, scene->img_address + i * scene->res.width
		* 4, scene->res.width * 4);
	}
}
