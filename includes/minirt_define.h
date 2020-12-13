/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:53:10 by rpunet            #+#    #+#             */
/*   Updated: 2020/12/13 23:26:48 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFINE_H
# define MINIRT_DEFINE_H

# define EMPTY_LINE_GNL '\0'

# if defined(__linux__) || defined(__unix__)
#  define ESC 65307
#  define SPACE 32
#  define CLOSE 33
#  define LEFT 65361
#  define RIGHT 65363
#  define DOWN 65364
#  define UP 65362
#  define C 99
#  define S 115

# elif __APPLE__
#  define ESC 54
#  define SPACE 49
#  define CLOSE 17
#  define LEFT 123
#  define RIGHT 124
#  define DOWN 125
#  define UP 126
# endif

/*
** main FUNCIONS
*/

int			main(int argc, char **argv);
void		scene_init(t_scene *scene);
void		check_args(int argc, char **argv, t_scene *scene);
void		read_scene(char *file, t_scene *scene);
void		save_image_bmp(t_scene *scene);
void		display_scene(t_scene *scene);
void		scene_quit(t_scene *scene);

/*
** read FUNCIONS
*/

void		read_element(char **line, t_scene *scene);
void		check_scene_values(t_scene *scene);
void		read_resolution(char **line, t_scene *scene);
void		read_ambient(char **line, t_scene *scene);

void		read_camera(char **line, t_scene *scene);
t_cam		*create_camera(char **line, t_scene *scene);
void		add_camera(t_cam **cams, t_cam *new_cam);
void		delete_cameras(t_cam **cams);
void		next_camera(t_scene *scene);

void		read_light(char **line, t_scene *scene);
t_light		*create_light(char **line, t_scene *scene);
void		add_light(t_light **lights, t_light *new_light);
void		delete_lights(t_light **lights);

void		read_sphere(char **line, t_scene *scene);
t_sphere	*create_sphere(char **line, t_scene *scene);
void		add_sphere(t_sphere **spheres, t_sphere *new_sphere);
void		delete_spheres(t_sphere **spheres);

void		read_plane(char **line, t_scene *scene);
t_plane		*create_plane(char **line, t_scene *scene);
void		add_plane(t_plane **planes, t_plane *new_plane);
void		delete_planes(t_plane **planes);

void		read_cyl(char **line, t_scene *scene);
t_cyl		*create_cyl(char **line, t_scene *scene);
void		add_cyl(t_cyl **cyls, t_cyl *new_cyl);
void		delete_cyls(t_cyl **cyls);

void		read_square(char **line, t_scene *scene);
t_square	*create_square(char **line, t_scene *scene);
void		add_square(t_square **squares, t_square *new_square);
void		delete_squares(t_square **squares);

void		read_triangle(char **line, t_scene *scene);
t_triangle	*create_triangle(char **line, t_scene *scene);
void		add_triangle(t_triangle **triangles, t_triangle *new_triangle);
void		delete_triangles(t_triangle **triangles);

/*
** bmp FUNCIONS
*/

void		save_image_bmp(t_scene *scene);
void		header_data(int fd, t_scene *scene);
void		pixel_data(int fd, t_scene *scene);

/*
** render FUNCIONS
*/

void		render_scene(t_scene *scene);
void		look_at(t_cam *cam);
void		set_ray(t_ray *ray, t_scene *scene, double x, double y);
void		save_pixel(char **buffer, t_color color);

void		cast_ray(t_ray *ray, t_scene *scene);
void		cast_ray_2(t_ray *ray, t_scene *scene);
void		render_sphere(t_ray *ray, t_scene *scene, t_sphere *sphere);
double		intersect_sphere(t_ray *ray, t_sphere *sphere);
void		render_plane(t_ray *ray, t_scene *scene, t_plane *plane);
double		intersect_plane(t_ray *ray, t_plane *plane);
void		render_cyl(t_ray *ray, t_scene *scene, t_cyl *cyl);
double		intersect_tube(t_ray *ray, t_cyl *cyl);
double		solve_quad(double a, double b, double discr);
void		render_cyl_cap(t_ray *ray, t_scene *scene, t_cyl *cyl, t_hit *p);
t_vec3		visible_cap(t_cyl *cyl, t_vec3 origin);
void		render_square(t_ray *ray, t_scene *scene, t_square *square);
int			in_square(t_square *square, t_vec3 point);
void		render_triangle(t_ray *ray, t_scene *scene, t_triangle *triangle);
int			in_triangle(t_triangle *triangle, t_vec3 point, t_vec3 normal);
int			edge_side(t_vec3 v1, t_vec3 v0, t_vec3 p, t_vec3 n);

t_color		get_surface_data(t_scene *scene, t_hit *p);
t_color		illuminate(t_light *light, t_hit *p, int opt_specular);
t_color		add_amb(t_scene *s, t_color point);
t_color		add_color(t_color a, t_color b);
void		check_rgb_color(t_color *color);

/*
** shade FUNCIONS
*/

int			shadows_1(t_scene *scene, t_ray *shadow_ray, t_vec3 light_pos);
int			shadows_2(t_scene *scene, t_ray *shadow_ray, t_vec3 light_pos, void *obj);
double		intersect_square(t_ray *ray, t_square *square);
double		intersect_triangle(t_ray *ray, t_triangle *triangle);
double		intersect_cyl(t_ray *ray, t_cyl *cyl);
int			block_light(t_ray *shadow_ray, t_vec3 light_pos);

/*
** auxiliar FUNCTIONS
*/

void		skip_blanks(char **str);
void		skip_digits(char **str);
void		skip_char(char **str, int c);
int			get_int(char **line, t_scene *scene);
double		get_double(char **line, t_scene *scene);

void		normalize_vec3(t_vec3 *v1);
int			range_vec3(t_vec3 v1, double min, double max);
int			ft_isnull_vec3(t_vec3 v1);
t_color		get_color_vec3(char **line, t_scene *scene);
t_vec3		get_vec3(char **line, t_scene *scene);

t_vec3		new_vec3(double x, double y, double z);
t_vec3		sub_vec3(t_vec3 u, t_vec3 v);
t_vec3		add_vec3(t_vec3 u, t_vec3 v);
t_vec3		esc_vec3(double k, t_vec3 v);
double		dot_vec3(t_vec3 u, t_vec3 v);

t_vec3		cross_vec3(t_vec3 v1, t_vec3 v2);
double		mod_vec3(t_vec3 v);
double		det_mat3x3(t_mat3x3 m);
t_mat3x3	invert_mat3x3(t_mat3x3 m);
t_vec3		mult_vec3_mat3x3(t_vec3 v, t_mat3x3 m);

/*
** others
*/

void		sepia_filter(t_color *color);
void		stereoscopy_filter(t_color *color);
int			key_hook(int keycode, t_scene *scene);
int			refresh(t_scene *scene);
int			close_program(t_scene *scene);
void		exit_error_msg(t_error id, t_scene *scene);
void		push_image(t_scene *scene);
void		move_element(int keycode, t_scene *scene);
void		move_x_pos(t_scene *scene, int key);
void		move_x_neg(t_scene *scene, int key);
void		move_y_pos(t_scene *scene, int key);
void		move_y_neg(t_scene *scene, int key);

#endif
