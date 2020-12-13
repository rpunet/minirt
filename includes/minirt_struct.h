/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:21:14 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/13 01:06:03 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

typedef enum	e_error{
	ARGS_ERR,
	SCENE_FILE_ERR,
	OPT_ERR,
	SCENE_FORMAT_ERR,
	RES_DECLARED,
	AMB_DECLARED,
	NO_CAM_ERR,
	VALUE_RANGE_ERR,
	RGB_RANGE_ERR,
	VEC_RANGE_ERR,
	NULL_VEC_ERR,
	FOV_RANGE_ERR,
	DEFAULT_ERR
}				t_error;

typedef struct	s_vec3{
	double	x;
	double	y;
	double	z;
}				t_vec3;

/*
**	[v1.x  v1.y  v1.z]
**	[v2.x  v2.y  v1.2]
**	[v3.x  v3.y  v1.3]
*/
typedef struct	s_mat3x3{
	t_vec3	v1;
	t_vec3	v2;
	t_vec3	v3;
}				t_mat3x3;

typedef struct	s_color{
	double	r;
	double	g;
	double	b;
}				t_color;

typedef struct	s_ray{
	t_vec3	origin;
	t_vec3	dir;
	double	t;
	t_color	color;
}				t_ray;

typedef struct	s_res{
	int		width;
	int		height;
	double	ratio;
	int		declared;
}				t_res;

typedef struct	s_amb{
	double	bright;
	t_color	color;
	int		declared;

}				t_amb;

typedef struct	s_cam{
	t_vec3			pos;
	t_vec3			dir;
	double			fov;
	t_mat3x3		cam_to_world;
	struct s_cam	*next;
}				t_cam;

typedef struct	s_light{
	t_vec3			pos;
	double			lum;
	t_color			color;
	struct s_light	*next;
}				t_light;

typedef struct	s_sphere{
	t_vec3			centre;
	double			radius;
	t_color			color;
	struct s_sphere	*next;
}				t_sphere;

typedef struct	s_plane{
	t_vec3			point;
	t_vec3			n_dir;
	t_color			color;
	struct s_plane	*next;
}				t_plane;

typedef struct	s_square{
	t_vec3			center;
	t_vec3			n_dir;
	double			side;
	t_color			color;
	struct s_square	*next;
}				t_square;

typedef struct	s_triangle{
	t_vec3				a;
	t_vec3				b;
	t_vec3				c;
	t_color				color;
	struct s_triangle	*next;
}				t_triangle;

typedef struct	s_cyl{
	t_vec3			point;
	t_vec3			n_vec;
	double			radius;
	double			h;
	t_color			color;
	struct s_cyl	*next;
}				t_cyl;

typedef struct	s_hit{
	t_vec3		point;
	t_vec3		normal;
	t_vec3		light;
	t_ray		shadow_ray;
	t_color		color;
	double		cyl_m;
	t_vec3		cyl_center;
}				t_hit;

typedef struct	s_scene{
	int			save_bmp;
	int			specular;
	int			sepia;
	int			stereoscopy;
	int			obj_id;
	void		*mlx;
	void		*win;
	char		*img_address;
	void		*img;
	t_res		res;
	t_amb		amb;
	t_cam		*cams;
	int			cam_count;
	t_light		*lights;
	t_sphere	*spheres;
	t_plane		*planes;
	t_cyl		*cyls;
	t_square	*squares;
	t_triangle	*triangles;
}				t_scene;

typedef struct	s_img{
	void			*img;
	int				size_x;
	int				size_y;
	char			*address;
	int				bbp;
	int				size_line;
	int				endian;
	struct s_img	*next;
}				t_img;

#endif
