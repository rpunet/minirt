/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 22:48:54 by rpunet            #+#    #+#             */
/*   Updated: 2020/08/11 21:13:33 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_flags(t_struct *s, char *format)
{
	while (format[s->pos] == '-' || format[s->pos] == '0')
	{
		if (format[s->pos] == '-')
			s->neg = 1;
		if (format[s->pos] == '0')
			s->zero = 1;
		s->pos++;
	}
	if (s->neg == 1)
		s->zero = 0;
}

void	ft_width(t_struct *s, char *format, va_list ap)
{
	while (format[s->pos] >= '0' && format[s->pos] <= '9')
	{
		s->width = s->width * 10 + format[s->pos] - '0';
		s->pos++;
	}
	if (format[s->pos] == '*')
	{
		if (s->width != 0)
			s->err = 1;
		s->star = 1;
		s->width = va_arg(ap, int);
		if (s->width < 0)
		{
			s->neg = 1;
			s->width *= -1;
		}
		s->pos++;
	}
}

void	ft_precision(t_struct *s, char *format, va_list ap)
{
	if (format[s->pos] == '.')
	{
		s->dot = 1;
		s->pos++;
		if (ft_strchr(CONVERSIONS, format[s->pos]))
			s->precision = 0;
		else if (format[s->pos] >= '0' && format[s->pos] <= '9')
		{
			s->starp = 1;
			while (format[s->pos] >= '0' && format[s->pos] <= '9')
			{
				s->precision = s->precision * 10 + format[s->pos] - '0';
				s->pos++;
			}
		}
		else if (format[s->pos] == '*')
		{
			if (s->starp != 0)
				s->err = 1;
			s->precision = va_arg(ap, int);
			if (s->precision < 0)
				s->dot = 0;
			s->pos++;
		}
	}
}

void	ft_check_flags(t_struct *s, va_list ap, char *format)
{
	ft_flags(s, format);
	ft_width(s, format, ap);
	ft_precision(s, format, ap);
	if (!ft_strchr(CONVERSIONS, format[s->pos]))
		s->err = 1;
}
