/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 01:13:49 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/04 21:41:07 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	skip_blanks(char **str)
{
	while (ft_isblank(**str))
		(*str)++;
}

void	skip_digits(char **str)
{
	while (ft_isdigit(**str))
		(*str)++;
}

void	skip_char(char **str, int c)
{
	if (**str == c)
		(*str)++;
}

int		get_int(char **line)
{
	int	a;

	skip_blanks(line);
	if (**line == '-' || ft_isdigit(**line))
	{
		a = ft_atoi(*line);
		skip_char(line, '-');
		skip_digits(line);
	}
	else
		exit_error_msg(SCENE_FORMAT_ERR);
	return (a);
}

double	get_double(char **line)
{
	double	a;

	skip_blanks(line);
	if (**line == '-' || ft_isdigit(**line))
	{
		a = ft_atod(*line);
		skip_char(line, '-');
		skip_digits(line);
		skip_char(line, '.');
		skip_digits(line);
	}
	else
		exit_error_msg(SCENE_FORMAT_ERR);
	return (a);
}

t_color	get_color_vec(char **line)
{
	t_color	vec3;

	skip_blanks(line);
	vec3.r = get_int(line);
	skip_blanks(line);
	skip_char(line, ',');
	vec3.g = get_int(line);
	skip_blanks(line);
	skip_char(line, ',');
	vec3.b = get_int(line);
	if ((vec3.r < 0 || vec3.r > 255) || (vec3.g < 0 || vec3.g > 255) || (vec3.b < 0 || vec3.b > 255))
		exit_error_msg(SCENE_FORMAT_ERR);
	return (vec3);
}
