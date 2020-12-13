/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:04:53 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/13 01:41:38 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_args(int argc, char **argv, t_scene *scene)
{
	if (argc < 2 || argc > 3)
		exit_error_msg(ARGS_ERR, scene);
	if (ft_strlen(argv[1]) < 4)
		exit_error_msg(SCENE_FILE_ERR, scene);
	if (argc == 3)
	{
		if (!ft_strcmp(argv[2], "--save"))
			scene->save_bmp = 1;
		else if (!ft_strcmp(argv[2], "--shine"))
			scene->specular = 1;
		else if (!ft_strcmp(argv[2], "--sepia"))
			scene->sepia = 1;
		else if (!ft_strcmp(argv[2], "--stereoscopy"))
			scene->stereoscopy = 1;
		else
			exit_error_msg(OPT_ERR, scene);
	}
	if (ft_strncmp((argv[1] + ft_strlen(argv[1]) - 3), ".rt", 3))
		exit_error_msg(SCENE_FILE_ERR, scene);
}

void	sepia_filter(t_color *color)
{
	t_color	sepia;

	sepia.r = 0.393 * color->r + 0.769 * color->g + 0.189 * color->b;
	sepia.g = 0.349 * color->r + 0.686 * color->g + 0.168 * color->b;
	sepia.b = 0.272 * color->r + 0.534 * color->g + 0.131 * color->b;
	*color = sepia;
}

void	stereoscopy_filter(t_color *color)
{
	t_color	stereoscopy;

	stereoscopy.r = 0.393 * color->r + 0.769 * color->g + 0.189 * color->b;
	stereoscopy.g = 0.0;
	stereoscopy.b = 0.0;
	*color = stereoscopy;
}
