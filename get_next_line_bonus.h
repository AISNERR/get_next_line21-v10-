#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define FD_MAX 256

typedef struct		s_list
{
	char			buf[BUFFER_SIZE + 1];
	int				fd;
	struct s_list	*next;
}					t_list;

int					ft_strlen(const char *str);
int					shift_buf(char *buf, int amount, ssize_t size, int check);
int					check_line(char **line, char *buf, int size);
int					get_next_line(int fd, char **line);

#endif