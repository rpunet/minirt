/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:18:13 by rpunet            #+#    #+#             */
/*   Updated: 2020/07/08 17:11:39 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*orgdest;

	if (src == NULL || dst == NULL)
		return (NULL);
	orgdest = dst;
	if (src < dst && ((src + len) > dst))
		while (len-- > 0)
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	else
		while (len-- > 0)
		{
			*(unsigned char *)dst = *(unsigned char *)src;
			dst = (unsigned char *)dst + 1;
			src = (unsigned char *)src + 1;
		}
	return (orgdest);
}
