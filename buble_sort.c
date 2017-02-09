/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buble_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:20:06 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/08 15:20:08 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sub_sort(t_list *infos)
{
	t_info	*tmp;
	t_list	*current;
	int		swaped;

	swaped = 1;
	while (swaped)
	{
		swaped = 0;
		current = infos;
		while (current->next)
		{
			if (ft_strcmp(((t_info *)(current->content))->path,
			((t_info *)((current->next)->content))->path) > 0)
			{
				tmp = current->content;
				current->content = (current->next)->content;
				(current->next)->content = tmp;
				swaped = 1;
			}
			current = current->next;
		}
	}
}

void	sub_sort_r(t_list *infos)
{
	t_info	*tmp;
	t_list	*current;
	int		swaped;

	swaped = 1;
	while (swaped)
	{
		swaped = 0;
		current = infos;
		while (current->next)
		{
			if (ft_strcmp(((t_info *)(current->content))->path,
			((t_info *)((current->next)->content))->path) < 0)
			{
				tmp = current->content;
				current->content = (current->next)->content;
				(current->next)->content = tmp;
				swaped = 1;
			}
			current = current->next;
		}
	}
}

void	sub_sort_t(t_list *infos)
{
	t_info	*info;
	t_info	*n_info;
	t_list	*current;
	int		swaped;

	swaped = 1;
	while (swaped)
	{
		swaped = 0;
		current = infos;
		while (current->next)
		{
			info = (t_info*)(current->content);
			n_info = (t_info*)((current->next)->content);
			if (info->mod_time < n_info->mod_time)
			{
				current->content = (current->next)->content;
				(current->next)->content = info;
				swaped = 1;
			}
			current = current->next;
		}
	}
}

void	sub_sort_t_r(t_list *infos)
{
	t_info	*tmp;
	t_list	*current;
	int		swaped;

	swaped = 1;
	while (swaped)
	{
		swaped = 0;
		current = infos;
		while (current->next)
		{
			if (((t_info*)(current->content))->mod_time >
				((t_info*)((current->next)->content))->mod_time)
			{
				tmp = current->content;
				current->content = (current->next)->content;
				(current->next)->content = tmp;
				swaped = 1;
			}
			current = current->next;
		}
	}
}

void	buble_sort(t_list *infos, t_flags *flags)
{
	if (!ft_strstr(((t_info*)(infos->content))->path, "DiagnosticReports"))
	{
		if (!flags->t && !flags->r)
			sub_sort(infos);
		else if (!flags->t && flags->r)
			sub_sort_r(infos);
		else if (flags->t && !flags->r)
			sub_sort_t(infos);
		else if (flags->t && flags->r)
			sub_sort_t_r(infos);
	}
}
