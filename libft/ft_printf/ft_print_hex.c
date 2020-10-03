/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 20:23:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/08/11 20:53:03 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_right_aligned_hex(t_struct *s, char *str, int slen)
{
	int	iprecision;
	int iwidth;

	iprecision = s->precision;
	iwidth = s->width;
	while (iwidth-- > ((iprecision > slen ? iprecision : slen)))
	{
		if (s->zero == 1 && s->dot == 0)
			s->ret += write(1, "0", 1);
		else
			s->ret += write(1, " ", 1);
	}
	while (iprecision-- > slen)
		s->ret += write(1, "0", 1);
	if (*str == '0' && s->precision == 0 && s->dot == 1 && s->width != 0)
		s->ret += write(1, " ", 1);
	else if (!(*str == '0' && s->precision == 0 && s->dot == 1 &&
	s->width == 0))
	{
		ft_putstr_fd(str, 1);
		s->ret += slen;
	}
}

void	ft_left_aligned_hex(t_struct *s, char *str, int slen)
{
	int	iprecision;

	iprecision = s->precision;
	while (iprecision > slen)
	{
		s->ret += write(1, "0", 1);
		iprecision--;
	}
	if (*str == '0' && s->precision == 0 && s->dot == 1)
		s->ret += write(1, " ", 1);
	else
	{
		ft_putstr_fd(str, 1);
		s->ret += slen;
	}
	while (s->width > ((s->precision > slen ? s->precision : slen) + s->sign))
	{
		s->ret += write(1, " ", 1);
		s->width--;
	}
}

void	hex_convert(t_struct *s, va_list ap, char *format)
{
	unsigned	num;
	char		*str;
	int			slen;

	num = va_arg(ap, unsigned);
	if (format[s->pos] == 'x')
		str = ft_itoa_base(num, "0123456789abcdef");
	else
		str = ft_itoa_base(num, "0123456789ABCDEF");
	slen = (int)ft_strlen(str);
	if (s->dot == 1 || s->neg == 1)
		s->zero = 0;
	if (s->neg == 1)
		ft_left_aligned_hex(s, str, slen);
	if (s->neg == 0)
		ft_right_aligned_hex(s, str, slen);
	free(str);
}
