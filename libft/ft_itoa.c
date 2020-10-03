/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 10:18:15 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/25 21:13:59 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_digit(int num)
{
	int count;

	count = 1;
	while (num >= 10)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	unsigned int	nbr;
	int				len;
	char			*itoa;
	int				sign;

	sign = (n < 0) ? 1 : 0;
	nbr = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	len = ft_count_digit(nbr);
	len += sign;
	if (!(itoa = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	itoa[len] = '\0';
	while (len-- > sign)
	{
		itoa[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign == 1)
		itoa[0] = '-';
	return (itoa);
}

char	*ft_itoa_base(unsigned long nbr, char *base)
{
	char			*str;
	int				bslen;
	unsigned long	nbrcopy;
	int				i;

	nbrcopy = nbr;
	i = 1;
	bslen = (int)ft_strlen(base);
	while ((nbrcopy /= bslen) >= 1)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = base[nbr % bslen];
		nbr /= bslen;
	}
	return (str);
}
