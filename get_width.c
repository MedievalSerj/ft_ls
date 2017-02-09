/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:33:12 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/08 15:33:15 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_width		*init_width(void)
{
	t_width *w;

	w = (t_width*)malloc(sizeof(t_width));
	w->w_group = 0;
	w->w_link = 0;
	w->w_size = 0;
	w->w_owner = 0;
	return (w);
}

static int	sub_get_field_width(t_info *info, t_list *tmp, t_width *w)
{
	int b;

	b = 0;
	while (tmp)
	{
		info = (t_info*)(tmp->content);
		if (info->name[0] != '.' || (info->name[0] == '.' && info->a == 1))
			b += info->blocks;
		if (!info->a && info->name[0] == '.')
		{
			tmp = tmp->next;
			continue ;
		}
		w->w_owner = MAX(info->w_owner, w->w_owner);
		w->w_group = MAX(info->w_group, w->w_group);
		w->w_link = MAX(info->w_link, w->w_link);
		w->w_size = MAX(info->w_size, w->w_size);
		tmp = tmp->next;
	}
	return (b);
}

int			get_field_width(t_list *head)
{
	t_info	*info;
	t_list	*tmp;
	t_width	*w;
	int		b;

	w = init_width();
	tmp = head;
	info = (t_info*)(tmp->content);
	b = sub_get_field_width(info, tmp, w);
	tmp = head;
	while (tmp)
	{
		info = (t_info*)(tmp->content);
		info->w_link = w->w_link;
		info->w_owner = w->w_owner;
		info->w_group = w->w_group;
		info->w_size = w->w_size;
		tmp = tmp->next;
	}
	return (b);
}

static void	sub_get_initial_width(t_list *tmp, t_info *info, t_width *w)
{
	while (tmp)
	{
		info = (t_info*)(tmp->content);
		if (info->type != 'd')
		{
			w->w_owner = MAX(info->w_owner, w->w_owner);
			w->w_group = MAX(info->w_group, w->w_group);
			w->w_link = MAX(info->w_link, w->w_link);
			w->w_size = MAX(info->w_size, w->w_size);
		}
		tmp = tmp->next;
	}
}

void		get_initial_width(t_list *head)
{
	t_list	*tmp;
	t_info	*info;
	t_width	*w;

	tmp = head;
	w = init_width();
	info = (t_info*)(tmp->content);
	sub_get_initial_width(tmp, info, w);
	tmp = head;
	while (tmp)
	{
		info = (t_info *)(tmp->content);
		if (info->type != 'd')
		{
			info->w_link = w->w_link;
			info->w_owner = w->w_owner;
			info->w_group = w->w_group;
			info->w_size = w->w_size;
		}
		tmp = tmp->next;
	}
}
