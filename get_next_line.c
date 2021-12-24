/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:55:29 by sgaladri          #+#    #+#             */
/*   Updated: 2021/12/24 11:33:58 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf[2048]; /*unchangable part*/
	char		*line;		/*two-dimenshional array*/
	size_t		initial_len;

	if (fd < 0 || fd > 2048 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	if (gnl_strchar(buf[fd], '\n') == -1)
	{
		initial_len = gnl_length(buf[fd]);
		buf[fd] = gnl_expand_buffer(buf[fd], fd);
		if (initial_len == gnl_length(buf[fd]) && buf[fd])
			line = gnl_substr(buf[fd], 0, gnl_length(buf[fd]));
	}
	if (buf[fd] == NULL)
		return (NULL);
	if ((!line && gnl_strchar(buf[fd], '\n') != -1))
		line = my_GNL(fd, line, buf);
	if (line)
	{
		buf[fd] = gnl_shrink_buffer(buf[fd], line);
		return (line);
	}
	return (get_next_line(fd));
}

char	*my_GNL(int fd, char *l, char **s)
{	
	if (!l && gnl_strchar(s[fd], '\n') != -1)
		l = gnl_substr(s[fd], 0, gnl_strchar(s[fd], '\n') + 1);
	return (l);
}

char	*gnl_shrink_buffer(char *buf, char *line)
{
	char	*newbuf;
	int		line_len;

	if (!buf || !line)
		return (buf);
	line_len = gnl_length(line);
	if ((int)gnl_length(buf) == line_len)
	{
		free(buf);
		return (NULL);
	}
	newbuf = gnl_substr(buf, line_len, gnl_length(buf) - line_len);
	free(buf);
	return (newbuf);
}

char	*gnl_expand_buffer(char *buf, int fd)
{
	char	*newbuf;
	int		newlen;
	char	*KO;

	KO = gnl_newread(fd);
	if (!KO)
		return (NULL);
	if (!KO[0])
	{
		free(KO);
		return (buf);
	}
	if (!buf)
		return (KO);
	newlen = gnl_length(buf) + gnl_length(KO);
	newbuf = malloc(newlen + 1);
	if (!newbuf)
		return (NULL);
	gnl_strlcpy(newbuf, buf, newlen + 1);
	gnl_strlcat(newbuf, KO, newlen + 1);
	free(buf);
	free(KO);
	return (newbuf);
}

char	*gnl_newread(int fd)
{
	char	*aux;
	int		nbytes;

	aux = malloc(BUFFER_SIZE + 1);
	if (!aux)
		return (NULL);
	nbytes = read(fd, aux, BUFFER_SIZE);
	if (nbytes < 0)
	{
		free(aux);
		return (NULL);
	}
	aux[nbytes] = '\0';
	return (aux);
}
