/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:21:09 by aisner            #+#    #+#             */
/*   Updated: 2021/12/24 11:33:51 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

char	*get_next_line(int fd);
size_t	gnl_length(const char *s);
int     gnl_strchar(const char *s, int c);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
size_t	gnl_strlcat(char *dst, const char *src, size_t size);
char	*gnl_shrink_buffer(char *buf, char *line);
char	*gnl_expand_buffer(char *buf, int fd);
char	*gnl_newread(int fd);
char	*my_GNL(int fd, char *l, char **s);
#endif