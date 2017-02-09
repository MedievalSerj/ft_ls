/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 13:25:58 by sladonia          #+#    #+#             */
/*   Updated: 2016/12/19 13:26:03 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_buf(int fd)
{
	long	len;
	char	*buf;

	buf = ft_memalloc(BUFF_SIZE + 1);
	while ((len = read(fd, buf, BUFF_SIZE)) > 0 && len < BUFF_SIZE)
	{
	}
	if (len == -1)
		return (NULL);
	return (buf);
}

int		locate_n(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*rest(char *buf, int n)
{
	char	*tmp;
	int		i;
	int		k;

	k = 0;
	i = n;
	if (n == -1)
		return (NULL);
	while (buf[i])
	{
		k++;
		i++;
	}
	tmp = ft_memalloc((size_t)(k + 1));
	i = n;
	while (buf[i])
	{
		tmp[i - n] = buf[i];
		i++;
	}
	return (tmp);
}

int		artificial_fuck(int *n, char **s, char **r, int fd)
{
	char *tmp;

	if ((s[0] = read_buf(fd)) == NULL)
		return (-1);
	else if ((s[0][0] == '\0' && s[1] == NULL)
		|| (s[0][0] == '\0' && s[1][0] == '\0'))
		return (0);
	if (s[0][0] != 0 && s[1] != NULL)
	{
		tmp = ft_strcat(ft_strcpy(ft_memalloc(ft_strlen(s[1])
		+ ft_strlen(s[0]) + 1), s[1]), s[0]);
		ft_strdel(&s[1]);
		s[1] = tmp;
	}
	else if (s[0][0] != 0 && s[1] == NULL)
		s[1] = ft_strdup(s[0]);
	*n = locate_n(s[1]);
	*r = rest(s[1], *n);
	if (*n != -1)
		ft_strclr(ft_strchr(s[1], '\n'));
	if (s[0][0] == '\0')
		return (-2);
	ft_strdel(&s[0]);
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	char		**s;
	static char	*r = NULL;
	int			n;
	int			k;

	s = (char**)malloc(sizeof(char*) * 2);
	s[1] = NULL;
	if (r != NULL)
	{
		s[1] = ft_strcpy(ft_memalloc(ft_strlen(r)), r + 1);
		ft_strdel(&r);
	}
	n = -1;
	while (n == -1)
	{
		if ((k = artificial_fuck(&n, s, &r, fd)) == -1)
			return (-1);
		else if (k == 0)
			return (0);
		else if (k == -2)
			break ;
	}
	*line = s[1];
	ft_strdel(s);
	return (1);
}
