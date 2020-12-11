/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:04:53 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/11 16:57:29 by rpunet           ###   ########.fr       */
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
		if (ft_strcmp(argv[2], "--save"))
			exit_error_msg(OPT_ERR, scene);
		scene->save_bmp = 1;
	}
	if (ft_strncmp((argv[1] + ft_strlen(argv[1]) - 3), ".rt", 3))
		exit_error_msg(SCENE_FILE_ERR, scene);
}
