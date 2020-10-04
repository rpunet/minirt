/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:23:54 by rpunet            #+#    #+#             */
/*   Updated: 2020/10/04 21:34:14 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	decimal_part(const char *str)
{
	double	dec;
	double	div;

	dec = 0.0;
	div = 0.1;
	while (ft_isdigit(*str))
	{
		dec += div * (*str - '0');
		div /= 10;
		str++;
	}
	return (dec);
}

double	ft_atod(const char *str)
{
	int		sign;
	double	num;

	num = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
	*str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		num = 10 * num + *str - '0';
		str++;
	}
	if (*str == '.')
	{
		num += decimal_part(++str);
	}
	return ((double)(sign * num));
}
