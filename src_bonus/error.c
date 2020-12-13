/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:18:09 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/13 23:33:03 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*g_error[] =
{
	"Invalid arguments. Use format  ./miniRT <scene.rt> [--save]\n\noptions:\n \
	--save   save rendered image to bmp\n",
	"Invalid scene file. Use an appropiate '.rt' file\n",
	"Invalid option\n\noptions:\n  --save   save rendered image to bmp\n",
	"Invalid scene file format\n",
	"Invalid scene: Resolution must be declared only once\n",
	"Invalid scene: Ambient light must be declared only once\n",
	"Invalid scene: Set at least one camera to render a view\n",
	"Invalid scene: ratio value must be in range [0,1]\n",
	"Invalid scene: RGB color must be in range [0-255]\n",
	"Invalid scene: vector values must be in range [-1,1]\n",
	"Invalid scene: wrong vector\n",
	"Invalid scene: FOV value must be in range [0,180]\n",
	"Error\n"
};

void	exit_error_msg(t_error id, t_scene *scene)
{
	scene_quit(scene);
	ft_printf("Error:\n%s\n", g_error[id]);
	exit(EXIT_FAILURE);
}

int		refresh(t_scene *scene)
{
	mlx_clear_window(scene->mlx, scene->win);
	mlx_put_image_to_window(scene->mlx, scene->win, scene->img, 0, 0);
	return (0);
}
