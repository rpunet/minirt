/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:18:09 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/04 01:29:31 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// podría ser un char[] con los mensajes, y llamar a cada uno con el id del error, pero asi se ve mejor a cual corresponde cada mensaje
t_errmsg	g_error[] =
{
	{SCENE_FILENAME_ERR, "Invalid scene file. Use an appropiate '.rt' file\n"},
	{OPT_ERR, "Invalid option\n\noptions:\n  --save   save rendered image to bmp\n"},
	{SCENE_FORMAT_ERR, "Invalid scene file format\n"},
	{RES_DECLARED, "Invalid scene: Resolution must be declared only once"},
	{DEFAULT_ERR, "Error\n"}
};

void	exit_error_msg(t_error id)
{
	ft_printf("Error: %s\n", g_error[id].msg);
	exit(EXIT_FAILURE);
}

//void	error_exit();
