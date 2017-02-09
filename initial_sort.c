/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:23:33 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/08 16:23:36 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*lst_join(t_list *head, t_list *tail)
{
	t_list *tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	ft_lstadd(&tail, tmp);
	return (head);
}

void	del_content(void *data, size_t size)
{
	(void)data;
	(void)size;
}

t_list	*sub_initial_sort(t_list *t, t_list *dirs, t_list *ot, t_flags *flags)
{
	if (dirs)
		buble_sort(dirs, flags);
	if (ot)
		buble_sort(ot, flags);
	if (dirs && ot)
	{
		ft_lstdel(&t, del_content);
		ot = lst_join(ot, dirs);
		return (ot);
	}
	else
	{
		ft_lstdel(&dirs, del_content);
		ft_lstdel(&ot, del_content);
		buble_sort(t, flags);
		return (t);
	}
}

t_list	*initial_sort(t_list *targets, t_flags *flags)
{
	t_list *dirs;
	t_list *nxt_dir;
	t_list *other;
	t_list *nxt_other;
	t_list *tmp;

	dirs = NULL;
	other = NULL;
	tmp = targets;
	while (tmp)
	{
		if (((t_info*)(tmp->content))->type == 'd')
		{
			nxt_dir = ft_lstnew(tmp->content, sizeof(t_info));
			ft_lstadd(&dirs, nxt_dir);
		}
		else
		{
			nxt_other = ft_lstnew(tmp->content, sizeof(t_info));
			ft_lstadd(&other, nxt_other);
		}
		tmp = tmp->next;
	}
	return (sub_initial_sort(targets, dirs, other, flags));
}
