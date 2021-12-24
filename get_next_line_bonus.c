/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:16:44 by llima-ce          #+#    #+#             */
/*   Updated: 2021/12/24 12:18:34 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	free_ptr(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*read_text(char **buffer_lists, char *buffer, int fd)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*res;

	res = ft_strchr(*buffer_lists, '\n');
	if (res != NULL)
		return (concatenation(res - *buffer_lists + 1, buffer_lists, TRUE));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (concatenation(bytes_read, buffer_lists, FALSE));
	buffer[bytes_read] = 0;
	tmp = ft_strjoin(*buffer_lists, buffer);
	free_ptr(buffer_lists);
	*buffer_lists = tmp;
	return (read_text(buffer_lists, buffer, fd));
}

char	*concatenation(int end, char **buffer_lists, t_bool fl)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (end <= 0 && fl == FALSE)
	{
		if (**buffer_lists == '\0')
		{
			free_ptr(buffer_lists);
			return (NULL);
		}
		res = *buffer_lists;
		*buffer_lists = NULL;
		return (res);
	}
	tmp = ft_substr(*buffer_lists, end, BUFFER_SIZE);
	res = *buffer_lists;
	res[end] = 0;
	*buffer_lists = tmp;
	return (res);
}

char	*get_next_line(int fd)
{
	static char		*buffer_lists[MAX_FD + 1];
	char			*line;
	char			*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	if (!buffer_lists[fd])
		buffer_lists[fd] = ft_strdup("");
	res = read_text(&buffer_lists[fd], line, fd);
	free_ptr(&line);
	return (res);
}