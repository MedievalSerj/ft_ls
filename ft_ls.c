/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:11:52 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/08 16:11:55 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	process_dir(t_flags *flags, t_list *elem)
{
	t_list	*filenames;
	t_list	*tar;
	char	*path;

	if (flags->d_newline)
		ft_putendl("");
	if (flags->d_n)
		ft_printf("%s:\n", ((t_info*)elem->content)->path);
	if ((filenames = list_dir(((t_info*)elem->content)->path)) == NULL)
		return ;
	path = ((t_info*)(elem->content))->path;
	tar = get_t_list_infos(filenames, flags, path);
	if (tar)
	{
		if (flags->l && (list_size(tar) > 2 || get_field_width(tar) != 0))
			ft_printf("total %d\n", get_field_width(tar));
		ft_lstiter(tar, print_info_global_dir);
	}
	if ((elem->next && ((t_info*)(elem->next)->content)->type == 'd') || tar)
		flags->d_newline = 1;
	else
		flags->d_newline = 0;
	if (flags->rec)
		sub_process_dir(tar, flags);
}

void	sub_process_dir(t_list *targets, t_flags *flags)
{
	t_list *tmp;

	tmp = targets;
	while (tmp)
	{
		if (((t_info*)(tmp->content))->type == 'd' &&
			!ft_strequ(((t_info*)(tmp->content))->name, ".")
			&& !ft_strequ(((t_info*)(tmp->content))->name, ".."))
		{
			flags->d_n = 1;
			process_dir(flags, tmp);
		}
		tmp = tmp->next;
	}
}

void	chose_f(t_flags *flags, t_list *targets)
{
	t_list *elem;
	t_info *info;

	elem = targets;
	while (elem)
	{
		info = (t_info*)(elem->content);
		if (info->type == 'd')
			process_dir(flags, elem);
		else
		{
			print_info_global(elem);
			if (elem->next && ((t_info*)((elem->next)->content))->type == 'd')
				ft_putendl("");
		}
		elem = elem->next;
	}
	ft_lstdel(&targets, del_list_info);
}

void	dir_name_flag(t_list *targets, t_flags *flags)
{
	if (flags->d_n == 2)
	{
		flags->d_n = 1;
		return ;
	}
	else if (targets->next == NULL)
		flags->d_n = 0;
}

int		main(int ac, char **av)
{
	t_flags	*flags;
	t_list	*targets;
	t_list	*next;

	flags = init_flags();
	if (ac == 1)
	{
		next = ft_lstnew(get_info(".", flags), sizeof(t_info));
		ft_lstadd(&targets, next);
	}
	else
		targets = proc_input(ac, av, flags);
	dir_name_flag(targets, flags);
	if (flags->l)
		get_initial_width(targets);
	else
		iterate_links(targets, flags);
	targets = initial_sort(targets, flags);
	chose_f(flags, targets);
	return (0);
}
