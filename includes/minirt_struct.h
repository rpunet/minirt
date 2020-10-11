/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:21:14 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/11 03:06:59 by rpunet           ###   ########.fr       */
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
	VALUE_RANGE_ERR,
	RGB_RANGE_ERR,
	VEC_RANGE_ERR,
	NULL_VEC_ERR,
	FOV_RANGE_ERR,
	DEFAULT_ERR
}				t_error;

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;
/*
[v1.x  v1.y  v1.z]
[v2.x  v2.y  v1.2]
[v3.x  v3.y  v1.3]
*/
typedef struct 	s_mat3x3
{
	t_vec3	v1;
	t_vec3	v2;
	t_vec3	v3;
}				t_mat3x3;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct	s_ray
{
	t_vec3	origin;
	t_vec3	dir;
	double	t;
	t_color	color;
	t_vec3	hit_p;
	t_vec3	normal;
}				t_ray;

typedef struct	s_errmsg
{
	t_error	id;
	char	*msg;
}				t_errmsg;

typedef struct	s_res
{
	int	width;
	int	height;
	int	declared;
}				t_res;

typedef struct	s_amb
{
	double	light;
	t_color	color;
	int		declared;

}				t_amb;

typedef struct		s_cam
{
	t_vec3			pos;
	t_vec3			dir;
	double			fov;
	t_mat3x3		cam_to_world;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_light
{
	t_vec3			pos;
	double			lum;
	t_color			color;
	struct s_light	*next;
}					t_light;

typedef enum	e_objs
{
	SPHERE,
	PLANE
}				t_objs;

typedef struct	s_sphere
{
	t_vec3	centre;
	double	radius;
	t_color	color;
}				t_sphere;

typedef struct	s_plane
{
	t_vec3	point;
	t_vec3	dir;
	t_color	color;
}				t_plane;

typedef struct	s_lstobj
{
	t_objs			obj_name;
	void			*obj;
	struct s_lstobj	*next;
}				t_lstobj;


typedef struct	s_scene
{
	void		*mlx;
	void		*win;
	t_res		res;
	t_amb		amb;
	t_cam 		*cams;
	int			cam_count;
	t_light		*lights;
	t_lstobj	*objs;
}				t_scene;

typedef struct 		s_img
{
	void			*img;
	int				size_x;
	int				size_y;
	char			*address;
	int				bbp;
	int				endian;
	int				size_line;
	struct s_img	*next;
}					t_img;

typedef struct	s_elemtype
{
	char	*type_id;
	int		id_len;
	void	(*read_func)(char **, t_scene *);   // aqui se podra hacer un typdef: typedef void (*read_func)(char *), para luego declarar read_func func; y llamar como g_elemtype.func
}				t_elemtype;



#endif
