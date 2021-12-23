/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 08:22:48 by aisner            #+#    #+#             */
/*   Updated: 2021/12/23 08:25:08 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static char	*ft_cpy_then_ncat(char *dst, char *src, char *cat, size_t n)
{
	char	*tmp;

	tmp = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	while (*cat && n--)
		*dst++ = *cat++;
	*dst = 0;
	return (tmp);
}

int			ft_strlen(const char *str)
{
	size_t			res;

	res = 0;
	while (*str)
	{
		if (!(*(str + 1)))
			return (res + 1);
		if (!(*(str + 2)))
			return (res + 2);
		if (!(*(str + 3)))
			return (res + 3);
		if (!(*(str + 4)))
			return (res + 4);
		if (!(*(str + 5)))
			return (res + 5);
		if (!(*(str + 6)))
			return (res + 6);
		if (!(*(str + 7)))
			return (res + 7);
		res += 8;
		str += 8;
	}
	return (res);
}

int			shift_buf(char *buf, int amount, ssize_t size, int check)
{
	int i;

	i = 0;
	buf[amount - 1] = 0;
	while (amount + i < BUFFER_SIZE + 0 && (buf[amount + i]))
	{
		buf[i] = buf[amount + i];
		buf[amount + i] = 0;
		++i;
	}
	if (check && !*buf)
		return (size == BUFFER_SIZE ? 1 : 0);
	return (1);
}

int			check_line(char **line, char *buf, int size)
{
	int		i;
	int		cont;
	char	*new;

	i = 0;
	while (i < size)
		if (buf[i] != '\n' && buf[i])
			i++;
		else
			break ;
	cont = ft_strlen(*line) + 1;
	if (!(new = malloc((cont + i) * sizeof(char))))
		return (-1);
	ft_cpy_then_ncat(new, *line, buf, i);
	free(*line);
	*line = new;
	cont = i;
	while (cont--)
		*buf++ = 0;
	return (i);
}