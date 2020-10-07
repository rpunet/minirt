/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:21:14 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/07 01:34:35 by rpunet           ###   ########.fr       */
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

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

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

typedef struct	s_cam
{
	t_vec3	pos;
	t_vec3	dir;
	double	fov;
}				t_cam;

typedef struct s_lstcam
{
	t_cam			*cam;
	struct s_lstcam	*next;
}				t_lstcam;


typedef struct	s_scene
{
	t_res		res;
	t_amb		amb;
	t_lstcam 	*cams;
	int			cam_count;
}				t_scene;

typedef struct	s_elemtype
{
	char	*type_id;
	int		id_len;
	void	(*read_func)(char **, t_scene *);   // aqui se podra hacer un typdef: typedef void (*read_func)(char *), para luego declarar read_func func; y llamar como g_elemtype.func
}				t_elemtype;



#endif
