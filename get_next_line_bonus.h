/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:52:52 by llima-ce          #+#    #+#             */
/*   Updated: 2021/12/24 12:05:48 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef MAX_FD
#  define MAX_FD 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef enum e_bool
{
	FALSE = 0,
	TRUE = !FALSE,
}			t_bool;

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*concatenation(int end, char **buffer_lists, t_bool fl);
char	*read_text(char **buffer_lists, char *buffer, int fd);
#endif