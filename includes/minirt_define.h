/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:53:10 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/07 02:09:03 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFINE_H
# define MINIRT_DEFINE_H

# define SCENE_EXT	".rt"
# define EXT_LEN	3
# define SCENE_ELEMENTS 3   // hay 9 en total
# define ELEM_LEN 1
# define ELEM_OBJ_LEN 2
# define EMPTY_LINE_GNL '\0'

//# define MINUS 45



void	check_scene_filename(char const *file);
void	wrong_args_msg(void);
void	check_args(int argc, char **argv, int *save_bmp);
void	exit_error_msg(t_error id);
void	read_scene(char *file, t_scene *scene);
void	read_element(char **line, t_scene *scene);
void	read_camera(char **line, t_scene *scene);
t_cam	*new_camera(char **line);
void	read_ambient(char **line, t_scene *scene);
void	read_resolution(char **line, t_scene *scene);
int		get_int(char **line);
double	get_double(char **line);
void	skip_char(char **str, int c);
void	skip_digits(char **str);
void	skip_blanks(char **str);

t_color	get_color_vec3(char **line);
t_vec3	get_vec3(char **line);
double	dot_product_vec3(t_vec3 v1, t_vec3 v2);
void	normalize_vec3(t_vec3 v1);
int		range_vec3(t_vec3 v1, double min, double max);
void	lstcam_append(t_lstcam **cams, t_lstcam *new_cam);
t_lstcam	*lstcam_new(t_cam *cam);


#endif
