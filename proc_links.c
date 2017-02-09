/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:05:59 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/08 19:06:01 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_info	*resolve_link(t_info *info, t_flags *flags)
{
	t_info *next_info;

	next_info = get_info(info->links_to_final, flags);
	if (next_info->type == 'l')
		next_info = resolve_link(next_info, flags);
	if (next_info->type == 'd')
		return (next_info);
	return (NULL);
}

void			iterate_links(t_list *targets, t_flags *flags)
{
	t_list	*tmp;
	t_info	*info;
	t_info	*new_info;
	char	*path;

	tmp = targets;
	while (tmp)
	{
		info = (t_info*)(tmp->content);
		if (info->type == 'l')
		{
			path = info->path;
			if ((new_info = resolve_link(info, flags)))
			{
				new_info->path = path;
				tmp->content = new_info;
			}
		}
		tmp = tmp->next;
	}
}
