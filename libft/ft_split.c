/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 17:08:44 by rpunet            #+#    #+#             */
/*   Updated: 2020/07/10 10:49:06 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcounter(char const *s, char c)
{
	int	count;
	int i;
	int key;

	i = 0;
	count = 0;
	key = 0;
	while (s[i])
	{
		if (s[i] == c)
			key = 0;
		if (s[i] != c && key == 0)
		{
			count++;
			key = 1;
		}
		i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int	len;
	int i;

	len = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ft_free_split(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		wordnum;
	int		word;

	if (s == NULL)
		return (NULL);
	wordnum = ft_strcounter(s, c);
	if (!(tab = (char **)malloc(sizeof(char*) * (wordnum + 1))))
		return (NULL);
	word = 0;
	while (wordnum > 0)
	{
		while (s && *s == c)
			s++;
		tab[word] = ft_substr(s, 0, ft_wordlen(s, c));
		if (!tab[word])
			return (ft_free_split(tab));
		s = s + ft_wordlen(s, c);
		word++;
		wordnum--;
	}
	tab[word] = NULL;
	return (tab);
}
