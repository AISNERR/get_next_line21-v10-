/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaladri <sgaladri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:55:29 by sgaladri          #+#    #+#             */
/*   Updated: 2021/11/27 19:58:42 by sgaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char    *get_next_line(int fd) // fd file descriptor 
{
    static char *buf[2048];
    char    *line;
    size_t  initial_length;

    if (fd < 0 || fd > 2048 || BUFFER_SIZE < 0)
        return (NULL);
    line = NULL;
    if (buf[fd] == NULL)
        return (NULL);
    if (gnl_strchr_i(buf[fd], '\n') == -1)
    {
        initial_len = gnl_strlen(buf[fd]);
        buf[fd] = gnl_expand_buffer(buf[fd], fd);
        if (initial_len == gnl_strlen(buf[fd]) && buf[fd])
            line =  gnl_substr(buf[fd], 0, gnl_strlen(buf[fd]));   // range of the line
    }
    else if ((!line && gnl_strchr_i(buf[fd], '\n') != -1) || line)
        if (line)
            line = my_GNL(fd, line, buf[fd]);
    return (get_next_line(fd));
}

char    *my_GNL(int fd, char *l, const char *s)
{
    if (!l && gnl_strchr_i(s[fd], '\n') != -1)
		l = gnl_substr(s[fd], 0, gnl_strchr_i(s[fd], '\n') + 1);
	if (l)
	{
		s[fd] = gnl_shrink_buffer(s[fd], l);
		return (l);
	}
}
int     gnl_strchr_i(const char *s, int c);
size_t  gnl_strlen(const char *s);
char    *gnl_substr(char const *s, unsigned int start, size_t len);