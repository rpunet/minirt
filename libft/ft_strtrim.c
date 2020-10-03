/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 00:25:24 by rpunet            #+#    #+#             */
/*   Updated: 2020/07/13 15:48:32 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char c, const char *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	z;
	char	*str1;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_check_set(s1[i], set))
		i++;
	z = ft_strlen(s1) - 1;
	while (z > i && ft_check_set(s1[z], set))
		z--;
	str1 = ft_substr(s1, (unsigned int)i, (z + 1 - i));
	return (str1);
}
