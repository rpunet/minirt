/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:39:45 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/03 21:46:45 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	read_element(char **line, t_scene *scene)
{
	if (!ft_strncmp(*line, "R ", 2))
		read_resolution(line, scene);
	else if (!ft_strncmp(*line, "A ", 2))
		read_ambient(line, scene);
	else if (!ft_strncmp(*line, "c ", 2))
		read_camera(line, scene);
	else if (!ft_strncmp(*line, "l ", 2))
		read_light(line, scene);
	else if (!ft_strncmp(*line, "sp ", 3))
		read_sphere(line, scene);
	else if (!ft_strncmp(*line, "pl ", 3))
		read_plane(line, scene);
	else if (**line != EMPTY_LINE_GNL)  // para que de error en líneas vacias con alguna letra
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	return ;
}

void	read_scene(char *file, t_scene *scene)
{
	int		fd;
	char	*line;
	char	*temp;
	int		bytes;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error_msg(SCENE_FILE_ERR, scene);
	while ((bytes = get_next_line(fd, &line)) > 0)
	{
		temp = line;
		read_element(&line, scene);
		free(temp);
	}
	free(line);
	close(fd);
}
