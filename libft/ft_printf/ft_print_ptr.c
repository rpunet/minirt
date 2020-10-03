/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 02:44:20 by rpunet            #+#    #+#             */
/*   Updated: 2020/08/11 18:47:41 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	left_aligned_ptr(t_struct *s, char *str, int plen)
{
	int	pprecision;

	pprecision = s->precision;
	if ((*str == 48 && plen == 0 && pprecision == 0 && s->dot == 0))
		plen = 1;
	s->ret += write(1, "0x", 2);
	while (s->precision-- > plen)
		s->ret += write(1, "0", 1);
	if (!(*str == 48 && plen == 1 && pprecision == 0 && s->dot == 1))
		s->ret += write(1, str, plen);
	if (pprecision >= plen)
	{
		while (s->width-- > (plen + 2 + (pprecision - plen)))
			s->ret += write(1, " ", 1);
	}
	else if (pprecision < plen)
	{
		while (s->width-- > (plen + 2))
			s->ret += write(1, " ", 1);
	}
}

void	right_aligned_ptr(t_struct *s, char *str, int plen)
{
	int pprecision;

	pprecision = s->precision;
	if ((*str == 48 && plen == 0 && pprecision == 0 && s->dot == 0))
		plen = 1;
	if (s->precision >= plen)
	{
		while (s->width-- > (s->precision + 2))
			s->ret += write(1, " ", 1);
	}
	else if (s->zero == 1)
	{
		while (s->width-- > (plen + 2))
			s->ret += write(1, "0", 1);
	}
	else if (s->precision < plen)
	{
		while (s->width-- > (plen + 2))
			s->ret += write(1, " ", 1);
	}
	s->ret += write(1, "0x", 2);
	while (s->precision-- > plen)
		s->ret += write(1, "0", 1);
	s->ret += write(1, str, plen);
}

void	ptr_convert(t_struct *s, va_list ap)
{
	char		*ptr;
	char		*str;
	int			plen;

	ptr = va_arg(ap, char *);
	str = ft_itoa_base((unsigned long)ptr, "0123456789abcdef\0");
	if (ptr == NULL)
		plen = 0;
	else
		plen = (int)ft_strlen(str);
	if (s->precision < 0)
		s->precision = 0;
	if (s->dot == 1)
		s->zero = 0;
	if (s->neg == 1)
		left_aligned_ptr(s, str, plen);
	else
		right_aligned_ptr(s, str, plen);
	free(str);
}
