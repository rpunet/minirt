/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:39:45 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/10 05:08:27 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_elemtype	g_elemtype[] =
{
	{"R ", 2, &read_resolution},
	{"A ", 2, &read_ambient},
	{"c ", 2, &read_camera},
	{"l ", 2, &read_light},
	{"sp ", 3, &read_sphere},
	{"pl ", 3, &read_plane}
};

void	read_element(char **line, t_scene *scene)
{
	int	i;

	i = 0;
	while (i < SCENE_ELEMENTS)
	{
		if (!ft_strncmp(*line, g_elemtype[i].type_id, g_elemtype[i].id_len))
		{
			g_elemtype[i].read_func(line, scene);

			return ;
		}
		if (**line == EMPTY_LINE_GNL)
			return ;
		i++;
	}
	exit_error_msg(SCENE_FORMAT_ERR, scene);
}

void	read_scene(char *file, t_scene *scene)
{
	int		fd;
	char	*line;
	char	*temp;
	int		bytes;

	fd = open(file, O_RDONLY);
	// if (fd == -1)
	// 	exit_error_msg(DEFAULT_ERROR, scene);
	while ((bytes = get_next_line(fd, &line)) > 0)
	{
		temp = line;
		read_element(&line, scene);
		free(temp);
	}
	free(line);
}
