/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 01:15:48 by rpunet            #+#    #+#             */
/*   Updated: 2020/08/11 21:14:26 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	char_convert(t_struct *s, va_list ap)
{
	unsigned char	a;

	a = (unsigned char)va_arg(ap, int);
	if (s->neg == 0)
	{
		while (s->width-- > 1)
		{
			if (s->zero == 1)
				s->ret += write(1, "0", 1);
			else if (s->zero == 0)
				s->ret += write(1, " ", 1);
		}
	}
	s->ret += write(1, &a, 1);
	if (s->neg == 1)
	{
		while (s->width-- > 1)
		{
			if (s->zero == 1)
				s->ret += write(1, "0", 1);
			else if (s->zero == 0)
				s->ret += write(1, " ", 1);
		}
	}
}

void	percent_convert(t_struct *s)
{
	if (s->neg == 0)
	{
		while (s->width-- > 1)
		{
			if (s->zero == 1)
				s->ret += write(1, "0", 1);
			else if (s->zero == 0)
				s->ret += write(1, " ", 1);
		}
	}
	s->ret += write(1, "%", 1);
	if (s->neg == 1)
	{
		while (s->width-- > 1)
		{
			if (s->zero == 1)
				s->ret += write(1, "0", 1);
			else if (s->zero == 0)
				s->ret += write(1, " ", 1);
		}
	}
}
