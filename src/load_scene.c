/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:39:45 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/04 01:32:38 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_elemtype	g_elemtype[] =
{
	{"R", 1, &read_resolution},
	{"A", 1, &read_ambient}
};

void	read_resolution(char **line, t_scene *scene)
{
	if (scene->res.declared)
		exit_error_msg(RES_DECLARED);
	scene->res.declared = 1;
	*line += ELEM_LEN;
	scene->res.x = get_int(line);
	scene->res.y = get_int(line);
	return ;
}

void	read_ambient(char **line, t_scene *scene)
{
	scene->res.y = 0;						// pruebaaaaa
	if (*line[0] == 'A')
	//	ft_printf("AAAAAAAAAA");
	return ;
}

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
		i++;
	}
	exit_error_msg(SCENE_FORMAT_ERR);

}

void	read_scene(char *file, t_scene *scene)
{
	int		fd;
	char	*line;
	char	*temp;
	int		bytes;

	fd = open(file, O_RDONLY);
	// if (fd == -1)
	// 	exit_error_msg(DEFAULT_ERR);
	while ((bytes = get_next_line(fd, &line)) > 0)
	{
		temp = line;
		read_element(&line, scene);
		free(temp);
	}
	free(line);



}
