/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:53:10 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/04 21:40:34 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFINE_H
# define MINIRT_DEFINE_H

# define SCENE_EXT	".rt"
# define EXT_LEN	3
# define SCENE_ELEMENTS 2   // hay 9 en total
# define ELEM_LEN 1
# define ELEM_OBJ_LEN 2

//# define MINUS 45



void	check_scene_filename(char const *file);
void	wrong_args_msg(void);
void	check_args(int argc, char **argv, int *save_bmp);
void	exit_error_msg(t_error id);
void	read_scene(char *file, t_scene *scene);
void	read_element(char **line, t_scene *scene);
void	read_ambient(char **line, t_scene *scene);
void	read_resolution(char **line, t_scene *scene);
int		get_int(char **line);
double	get_double(char **line);
void	skip_char(char **str, int c);
void	skip_digits(char **str);
void	skip_blanks(char **str);

t_color	get_color_vec(char **line);

#endif
