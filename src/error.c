/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:18:09 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/21 11:31:16 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// podría ser un char[] con los mensajes, y llamar a cada uno con el id del error, pero asi se ve mejor a cual corresponde cada mensaje
char	*g_error[] =
{
	"Invalid arguments. Use format  ./miniRT <scene.rt> [--save]\n\noptions:\n \
	--save   save rendered image to bmp\n",
	"Invalid scene file. Use an appropiate '.rt' file\n",
	"Invalid option\n\noptions:\n  --save   save rendered image to bmp\n",
	"Invalid scene file format\n",
	"Invalid scene: Resolution must be declared only once\n",
	"Invalid scene: Ambient light must be declared only once\n",
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
	ft_printf("Error: %s\n", g_error[id]);
	exit(EXIT_FAILURE);
}
