/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:30:37 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/08 15:30:47 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		get_filetype(mode_t mode)
{
	char type;

	if ((mode & 0160000) == 0160000)
		type = 'w';
	else if ((mode & 0140000) == 0140000)
		type = 's';
	else if ((mode & 0120000) == 0120000)
		type = 'l';
	else if ((mode & 0100000) == 0100000)
		type = '-';
	else if ((mode & 0060000) == 0060000)
		type = 'b';
	else if ((mode & 0040000) == 0040000)
		type = 'd';
	else if ((mode & 0020000) == 0020000)
		type = 'c';
	else if ((mode & 0010000) == 0010000)
		type = 'p';
	else
		type = 'x';
	return (type);
}

char		*get_modes(mode_t mode)
{
	char	*modes;
	int		n;

	n = mode & 0777;
	modes = ft_strnew(11);
	modes[0] = get_filetype(mode);
	modes[1] = (n & 0400) == 0400 ? (char)'r' : (char)'-';
	modes[2] = (n & 0200) == 0200 ? (char)'w' : (char)'-';
	modes[3] = (n & 0100) == 0100 ? (char)'x' : (char)'-';
	modes[4] = (n & 040) == 040 ? (char)'r' : (char)'-';
	modes[5] = (n & 020) == 020 ? (char)'w' : (char)'-';
	modes[6] = (n & 010) == 010 ? (char)'x' : (char)'-';
	modes[7] = (n & 04) == 04 ? (char)'r' : (char)'-';
	modes[8] = (n & 02) == 02 ? (char)'w' : (char)'-';
	modes[9] = (n & 01) == 01 ? (char)'x' : (char)'-';
	return (modes);
}

static char	*link_path(t_info *info)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	tmp = ft_strdup(info->path);
	i = ft_strlen(info->path);
	j = ft_strlen(info->name);
	while (info->path[--i] == info->name[--j])
		tmp[i] = '\0';
	return (tmp);
}

void		process_link(t_info *info)
{
	ssize_t len;

	if ((len = readlink(info->path, info->links_to, 1024)) != -1)
		(info->links_to)[len] = '\0';
	info->links_to_final = ft_strjoin(link_path(info), info->links_to);
}

void		process_time(t_info *info, struct stat *buf)
{
	info->mod_date = ft_strdup(ctime(&buf->st_mtime));
	info->year = ft_strsub(info->mod_date, 20, 4);
	info->month = ft_strsub(info->mod_date, 4, 3);
	info->day = ft_strsub(info->mod_date, 8, 2);
	info->time = ft_strsub(info->mod_date, 11, 5);
}
