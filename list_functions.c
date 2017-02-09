/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:13:03 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/08 17:13:06 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	del_list_info(void *data, size_t size)
{
	t_info *info;

	(void)size;
	info = (t_info*)data;
	ft_strdel(&info->name);
	ft_strdel(&info->path);
	ft_strdel(&info->modes);
	ft_strdel(&info->owner);
	ft_strdel(&info->group);
	ft_strdel(&info->mod_date);
	ft_strdel(&info->links_to);
	ft_strdel(&info->year);
	ft_strdel(&info->month);
	ft_strdel(&info->day);
	ft_strdel(&info->time);
}

size_t	list_size(t_list *head)
{
	size_t	n;
	t_list	*tmp;

	n = 0;
	tmp = head;
	while (tmp)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}

void	print_no_such_file(t_list *elem)
{
	ft_printf("ft_ls: %s: No such file or directory\n", elem->content);
}
