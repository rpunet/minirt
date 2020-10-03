/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 20:19:05 by rpunet            #+#    #+#             */
/*   Updated: 2020/08/11 18:43:27 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_left_aligned_int(t_struct *s, char *str, int slen)
{
	int	iprecision;

	iprecision = s->precision;
	if (s->sign == 1)
		s->ret += write(1, "-", 1);
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

void	ft_aux_zeros(t_struct *s, char *str, int slen)
{
	if (*str == '0' && s->precision == 0 && s->dot == 1 && s->width != 0)
		s->ret += write(1, " ", 1);
	else if (!(*str == '0' && s->precision == 0 && s->dot == 1 &&
	s->width == 0))
	{
		ft_putstr_fd(str, 1);
		s->ret += slen;
	}
}

void	ft_right_aligned_int(t_struct *s, int slen)
{
	int	iprecision;
	int minus;
	int iwidth;

	iprecision = s->precision;
	iwidth = s->width;
	minus = s->sign;
	while (iwidth-- > ((iprecision > slen ? iprecision : slen) + s->sign))
	{
		if (s->zero == 1 && s->dot == 0)
		{
			if (minus == 1)
			{
				s->ret += write(1, "-", 1);
				minus = 0;
			}
			s->ret += write(1, "0", 1);
		}
		else
			s->ret += write(1, " ", 1);
	}
	if (minus == 1)
		s->ret += write(1, "-", 1);
	while (iprecision-- > slen)
		s->ret += write(1, "0", 1);
}

void	int_convert(t_struct *s, va_list ap)
{
	long	num;
	char	*str;
	int		slen;

	num = (long)va_arg(ap, int);
	if (num < 0)
	{
		s->sign = 1;
		num *= -1;
	}
	str = ft_itoa(num);
	slen = (int)ft_strlen(str);
	if (s->dot == 1)
		s->zero = 0;
	if (s->neg == 1)
		ft_left_aligned_int(s, str, slen);
	if (s->neg == 0)
	{
		ft_right_aligned_int(s, slen);
		ft_aux_zeros(s, str, slen);
	}
	free(str);
}
