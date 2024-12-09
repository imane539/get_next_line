/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-fouh <iel-fouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:19:38 by iel-fouh          #+#    #+#             */
/*   Updated: 2024/12/08 19:19:48 by iel-fouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stop(char **buf)
{
	int		i;
	char	*new;
	char	*tmp;

	i = 0;
	while (((*buf)[i]))
	{
		if ((*buf)[i] == '\n')
		{
			new = ft_substr(*buf, 0, i + 1);
			tmp = ft_substr(*buf, i + 1, ft_strlen(*buf) - i);
			free(*buf);
			*buf = tmp;
			return (new);
		}
		i++;
	}
	return (NULL);
}

char	*ft_line(char **line, char *buffer)
{
	char	*tmp;
	char	*new;

	if (check_line(buffer))
	{
		new = ft_stop(&buffer);
		tmp = ft_strjoin(*line, new);
		free(*line);
		free(new);
		*line = tmp;
	}
	else
	{
		new = ft_strjoin(*line, buffer);
		free(*line);
		*line = new;
		free(buffer);
		buffer = NULL;
	}
	return (buffer);
}

char	*ft_read(int fd, char **line, char *buffer)
{
	int	r;

	r = 1;
	while (!check_line(*line) && r > 0)
	{
		if (ft_strlen(buffer) > 0)
			buffer = ft_line(line, buffer);
		if (ft_strlen(buffer) == 0)
		{
			free(buffer);
			buffer = malloc((size_t)(BUFFER_SIZE + 1));
			if (!buffer)
				return (NULL);
			r = read(fd, buffer, BUFFER_SIZE);
			if (r <= 0)
			{
				free(buffer);
				return (NULL);
			}
			buffer[r] = '\0';
		}
		if (!check_line(*line))
			buffer = ft_line(line, buffer);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buffer = ft_read(fd, &line, buffer);
	return (line);
}
