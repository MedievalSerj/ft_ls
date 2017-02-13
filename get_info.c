/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:16:19 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/08 16:16:22 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_name(char *path)
{
	int n;
	int k;
	int i;

	if (ft_strequ(path, "/"))
		return (ft_strdup("/"));
	i = -1;
	n = (int)ft_strlen(path);
	k = n;
	while (--n >= 0 && path[n] != '/')
		i++;
	if (i >= 0)
		return (ft_strsub(path, (unsigned int)(k - i - 1),
		(unsigned int)(i + 1)));
	else
		return (ft_strnew(2));
}

void	sub_get_info(char *path, t_info *info, struct stat *buf)
{
	info->no_such_file = 0;
	info->path = ft_strdup(path);
	info->name = get_name(path);
	info->type = get_filetype(buf->st_mode);
	info->mode = buf->st_mode & 07777;
	info->modes = get_modes(buf->st_mode);
	info->n_links = buf->st_nlink;
	info->c_n_links = ft_itoa(info->n_links);
	info->owner = ft_strdup(getpwuid(buf->st_uid)->pw_name);
	info->group = ft_strdup(getgrgid(buf->st_gid)->gr_name);
	info->blocks = buf->st_blocks;
	info->size = buf->st_size;
	info->c_size = ft_itoa((int)(info->size));
	info->major = major(buf->st_rdev);
	info->minor = minor(buf->st_rdev);
	info->mod_time = (buf->st_mtime);
	process_time(info, buf);
	info->links_to = ft_strnew(100);
}

t_info	*get_info(char *path, t_flags *flags)
{
	t_info		*info;
	struct stat	*buf;

	info = (t_info*)malloc(sizeof(t_info));
	buf = (struct stat*)malloc(sizeof(struct stat));
	if (lstat(path, buf) == -1)
	{
		info->no_such_file = 1;
		return (NULL);
	}
	sub_get_info(path, info, buf);
	if (info->type == 'l')
		process_link(info);
	info->l = flags->l;
	info->rec = flags->rec;
	info->a = flags->a;
	info->r = flags->r;
	info->t = flags->t;
	info->w_link = ft_strlen(ft_itoa(info->n_links));
	info->w_owner = ft_strlen(info->owner) + 2;
	info->w_group = ft_strlen(info->group) + 2;
	info->w_size = ft_strlen(info->c_size);
	return (info);
}
