/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 21:06:05 by rpunet            #+#    #+#             */
/*   Updated: 2020/08/12 01:37:43 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_format_read(t_struct *s, va_list ap, char *format)
{
	while (format[s->pos] != '\0' && !s->err)
	{
		if (format[s->pos] != '%' && format[s->pos])
			s->ret += write(1, &format[s->pos], 1);
		else if (format[s->pos] == '%')
		{
			s->pos++;
			if (ft_strchr(ALL, format[s->pos]) != NULL)
			{
				ft_check_flags(s, ap, format);
				if (!s->err)
					ft_tracker(s, ap, format);
				ft_struct_zero(s);
			}
			else
			{
				s->err = 1;
				break ;
			}
		}
		s->pos++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	*s;
	int			printed;

	va_start(ap, format);
	if (!(s = malloc(sizeof(t_struct))))
		return (-1);
	ft_struct_init(s);
	ft_format_read(s, ap, (char*)format);
	va_end(ap);
	if (s->err)
		return (-1);
	printed = s->ret;
	free(s);
	return (printed);
}
