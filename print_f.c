/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:18:23 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/08 17:18:25 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_dev(t_info *info)
{
	if (info->type == 'c' || info->type == 'b')
	{
		ft_put_str_w(ft_itoa(info->major), 4, 0);
		ft_putchar(',');
	}
	else
		ft_putstr("     ");
	ft_put_str_w(ft_itoa(info->minor), 4, 0);
}

static void	print_link_long(t_info *info)
{
	char *tmp;

	if (!ft_strequ(info->name, &(info->path[2])))
		tmp = ft_strjoin(info->path, " -> ");
	else
		tmp = ft_strjoin(info->name, " -> ");
	tmp = ft_strjoin(tmp, info->links_to);
	ft_put_str_w(tmp, ft_strlen(tmp) + 1, 0);
}

static void	print_info_long(t_info *info)
{
	if (info->a == 0 && info->name[0] == '.')
		return ;
	ft_put_str_w(info->modes, 12, '-');
	ft_put_str_w(info->c_n_links, info->w_link, 0);
	ft_putchar(' ');
	ft_put_str_w(info->owner, info->w_owner, '-');
	ft_put_str_w(info->group, info->w_group, '-');
	if ((ft_strncmp(info->path, "/dev", 4) == 0 && info->type != 'd') ||
		ft_strequ(info->path, "/dev/fd"))
		print_dev(info);
	else
		ft_put_str_w(info->c_size, info->w_size, 0);
	ft_put_str_w(info->month, 4, 0);
	ft_put_str_w(info->day, 3, 0);
	print_time_year(info);
	if (info->type != 'l')
	{
		if (!ft_strequ(info->name, &(info->path[2])))
			ft_put_str_w(info->path, ft_strlen(info->path) + 1, 0);
		else
			ft_put_str_w(info->name, ft_strlen(info->name) + 1, 0);
	}
	else
		print_link_long(info);
	ft_putendl("");
}

static void	print_info_short(t_info *info)
{
	char *name;

	name = info->name;
	if (info->a == 0 && name[0] != '.')
	{
		if (!ft_strequ(name, &(info->path[2])))
			ft_printf("%s\n", info->path);
		else
			ft_printf("%s\n", name);
	}
	else if (info->a == 1)
		ft_printf("%s\n", name);
}

void		print_info_global(t_list *elem)
{
	t_info *info;

	info = (t_info*)(elem->content);
	if (info->l)
		print_info_long(info);
	else
		print_info_short(info);
}
