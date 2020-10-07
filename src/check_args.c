/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:04:53 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/07 21:10:28 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_scene_filename(char const *file, t_scene *scene)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < EXT_LEN + 1)
		exit_error_msg(SCENE_FILENAME_ERR, scene);
	file += len - EXT_LEN;
	if (ft_strncmp(file, SCENE_EXT, EXT_LEN))
		exit_error_msg(SCENE_FILENAME_ERR, scene);
}

void	wrong_args_msg(void)
{
	ft_printf("error: wrong arguments\n");
	ft_printf("arguments usage: ./miniRT <scene.rt> [--save]\n\n");
	ft_printf("options:\n  --save   save rendered image to bmp\n");
	exit(EXIT_FAILURE);
}

void	check_args(int argc, char **argv, int *save_bmp, t_scene *scene)
{
	if (argc < 2 || argc > 3)
		wrong_args_msg();
	check_scene_filename(argv[1], scene);
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save"))
			exit_error_msg(OPT_ERR, scene);
		*save_bmp = 1;
	}
}
