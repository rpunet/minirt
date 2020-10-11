/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:53:10 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/11 02:33:54 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFINE_H
# define MINIRT_DEFINE_H

# define SCENE_EXT	".rt"
# define EXT_LEN	3
# define SCENE_ELEMENTS 6   // hay 9 en total
# define ELEM_LEN 2
# define ELEM_OBJ_LEN 3
# define EMPTY_LINE_GNL '\0'

//# define MINUS 45


int		main(int argc, char **argv);
void	scene_init(t_scene *scene);
void	check_scene_filename(char const *file, t_scene *scene);
void	wrong_args_msg(void);
void	check_args(int argc, char **argv, int *save_bmp, t_scene *scene);
void	exit_error_msg(t_error id, t_scene *scene);
void	read_scene(char *file, t_scene *scene);
void	read_element(char **line, t_scene *scene);
void	read_resolution(char **line, t_scene *scene);
void	read_ambient(char **line, t_scene *scene);
void	read_camera(char **line, t_scene *scene);
t_cam	*create_camera(char **line, t_scene *scene);
void	delete_cameras(t_cam **cams);
void	read_light(char **line, t_scene *scene);
t_light	*create_light(char **line, t_scene *scene);
void	delete_lights(t_light **lights);
void	read_sphere(char **line, t_scene *scene);
t_sphere	*create_sphere(char **line, t_scene *scene);
void	read_plane(char **line, t_scene *scene);
t_plane	*create_plane(char **line, t_scene *scene);
void	delete_objects(t_lstobj **objs);
void	scene_quit(t_scene *scene);

int		get_int(char **line, t_scene *scene);
double	get_double(char **line, t_scene *scene);
void	skip_char(char **str, int c);
void	skip_digits(char **str);
void	skip_blanks(char **str);

t_color	get_color_vec3(char **line, t_scene *scene);
t_vec3	get_vec3(char **line, t_scene *scene);
double	dot_vec3(t_vec3 u, t_vec3 v);
void	normalize_vec3(t_vec3 v1);
int		range_vec3(t_vec3 v1, double min, double max);
int		ft_isnull_vec3(t_vec3 v1);

void	normalize(t_vec3 *v1);
t_vec3	new_vec3(double x, double y, double z);
t_vec3	cross_vec3(t_vec3 v1, t_vec3 v2);

t_mat3x3	invert_mat3x3(t_mat3x3 m);

void	append_camera(t_cam **cams, t_cam *new_cam);
void	append_light(t_light **lights, t_light *new_light);
t_lstobj	*lstobj_new(void *obj, t_objs obj_name);
void	lstobj_append(t_lstobj **objs, t_lstobj *new_obj);


void	ft_prueba_printf(t_scene scene);

#endif
