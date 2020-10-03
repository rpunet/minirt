/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:22:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/07/27 22:07:16 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_line_save(char *save, char **line)
{
	size_t	i;
	char	*aux;

	i = 0;
	while (save && save[i] && save[i] != '\n')
		i++;
	if (save && (i < ft_strlen(save)))
	{
		*line = ft_substr(save, 0, i);
		aux = save;
		save = ft_substr(save, i + 1, (ft_strlen(save) - (i + 1)));
		free(aux);
	}
	else
	{
		*line = save;
		save = NULL;
	}
	return (save);
}

char	*ft_buff_save(char *save, char *buffer)
{
	char	*aux;

	if (!save)
		save = ft_strdup(buffer);
	else
	{
		aux = save;
		save = ft_strjoin(save, buffer);
		free(aux);
	}
	return (save);
}

int		get_next_line(int fd, char **line)
{
	static char	*save[FD_MAX];
	char		*buffer;
	int			byte;

	if (!(buffer = (char *)malloc(sizeof(*buffer) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((byte = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[byte] = '\0';
		save[fd] = ft_buff_save(save[fd], buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (byte <= 0 && !save[fd])
	{
		*line = ft_strdup("");
		return (byte);
	}
	save[fd] = ft_line_save(save[fd], line);
	if (byte == 0 && !save[fd])
	{
		return (0);
	}
	return (1);
}
