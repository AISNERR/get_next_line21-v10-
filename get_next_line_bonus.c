#include "get_next_line_bonus.h"
#include <stdio.h>

t_list	*create_buf(int fd)
{
	int		i;
	t_list	*new;

	i = 0;
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	while (i < BUFFER_SIZE + 1)
		new->buf[i++] = 0;
	return (new);
}

int	del_buf(t_list **lst, int fd)
{
	t_list *prev;
	t_list *cpy;

	printf("fd deleted\n");
	prev = *lst;
	if ((*lst)->fd == fd)
	{
		(*lst) = (*lst)->next;
		free(prev);
		return (0);
	}
	cpy = *lst;
	cpy = cpy->next;
	while (cpy)
	{
		if (cpy->fd == fd)
		{
			prev->next = cpy->next;
			free(cpy);
			return (0);
		}
		prev = cpy;
		cpy = cpy->next;
	}
	return (0);
}

char	*get_buffer(t_list **lst, int fd)
{
	t_list *cpy;

	if (!(*lst))
	{
		if (!((*lst) = create_buf(fd)))
			return (NULL);
		return ((*lst)->buf);
	}
	cpy = *lst;
	while (cpy)
	{
		if (cpy->fd == fd)
			return (cpy->buf);
		else if (!cpy->next)
			break ;
		else
			cpy = cpy->next;
	}
	if (!(cpy->next = create_buf(fd)))
		return (NULL);
	return (cpy->next->buf);
}

int		scan_buf(char **line, char *buf, ssize_t size, int check)
{
	int i;

	i = 0;
	if (size == -1)
		return (-1);
	if ((i = check_line(line, buf, size)) == -1)
		return (-1);
	if (buf[i] == '\n')
		return (shift_buf(buf, i + 1, size, 0));
	if ((!size && **line))
		return (shift_buf(buf, i + 1, size, check));
	return (2);
}

int		get_next_line(int fd, char **line)
{
	static	t_list	*lst = NULL;
	char			*buf;
	ssize_t			size;
	int				ret;
	int				check;

	if (fd < 0 || !(*line = malloc(sizeof(char))) || BUFFER_SIZE <= 0)
		return (-1);
	(*line)[0] = 0;
	buf = get_buffer(&lst, fd);
	size = 1;
	while (size > 0)
	{
		check = 0;
		if ((size = ft_strlen(buf)) == 0)
		{
			size = read(fd, buf, BUFFER_SIZE);
			check = 1;
		}
		if ((ret = scan_buf(line, buf, size, check)) < 2)
			return (ret == 0 ? del_buf(&lst, fd) : ret);
	}
	return (del_buf(&lst, fd));
}