/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:21:14 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/04 21:38:25 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

typedef enum	e_error
{
	SCENE_FILENAME_ERR,
	OPT_ERR,
	SCENE_FORMAT_ERR,
	RES_DECLARED,
	AMB_DECLARED,
	DEFAULT_ERR
}				t_error;

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;



typedef struct	s_errmsg
{
	t_error	id;
	char	*msg;
}				t_errmsg;

typedef struct	s_res
{
	int	x;
	int	y;
	int	declared;
}				t_res;

typedef struct	s_amb
{
	double	light;
	t_color	color;
	int		declared;

}				t_amb;


typedef struct	s_scene
{
	t_res	res;
	t_amb	amb;
}				t_scene;

typedef struct	s_elemtype
{
	char	*type_id;
	int		id_len;
	void	(*read_func)(char **, t_scene *);   // aqui se podra hacer un typdef: typedef void (*read_func)(char *), para luego declarar read_func func; y llamar como g_elemtype.func
}				t_elemtype;



#endif
