/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 04:31:36 by rpunet            #+#    #+#             */
/*   Updated: 2020/08/11 21:04:17 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_right_aligned_s(t_struct *s, int slen)
{
	char	c;

	if (s->zero == 0)
		c = ' ';
	else
		c = '0';
	{
		if (s->dot == 1 && s->precision < slen)
		{
			while (s->width-- > s->precision)
				s->ret += write(1, &c, 1);
		}
		else
		{
			while (s->width-- > slen)
				s->ret += write(1, &c, 1);
		}
	}
}

void	ft_left_aligned_s(t_struct *s, int slen)
{
	char	c;

	if (s->zero == 0)
		c = ' ';
	else
		c = '0';
	{
		if (s->dot == 1 && s->precision < slen)
		{
			while (s->width-- > s->precision)
				s->ret += write(1, &c, 1);
		}
		else
		{
			while (s->width-- > slen)
				s->ret += write(1, &c, 1);
		}
	}
}

void	str_convert(t_struct *s, va_list ap)
{
	char	*str;
	int		slen;

	str = (char *)va_arg(ap, char*);
	if (str == NULL || str == 0)
		str = "(null)";
	slen = (int)ft_strlen(str);
	if (s->neg == 0)
		ft_right_aligned_s(s, slen);
	if (s->dot == 1 && s->precision < slen)
		s->ret += write(1, str, s->precision);
	else
		s->ret += write(1, str, slen);
	if (s->neg == 1)
		ft_left_aligned_s(s, slen);
}
