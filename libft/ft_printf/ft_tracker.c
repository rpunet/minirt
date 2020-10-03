/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tracker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:08:43 by rpunet            #+#    #+#             */
/*   Updated: 2020/08/11 21:16:57 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tracker(t_struct *s, va_list ap, char *format)
{
	if (format[s->pos] == 'c')
		char_convert(s, ap);
	else if (format[s->pos] == 'd' || format[s->pos] == 'i')
		int_convert(s, ap);
	else if (format[s->pos] == 's')
		str_convert(s, ap);
	else if (format[s->pos] == 'p')
		ptr_convert(s, ap);
	else if (format[s->pos] == 'u')
		udec_int_convert(s, ap);
	else if (format[s->pos] == 'x' || format[s->pos] == 'X')
		hex_convert(s, ap, format);
	else if (format[s->pos] == '%')
		percent_convert(s);
	else
		s->err = 1;
}
