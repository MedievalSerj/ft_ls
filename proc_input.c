/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:28:07 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/08 17:28:10 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*get_t_list_infos(t_list *f_n, t_flags *flags, char *path)
{
	t_list	*targets;
	t_list	*next;
	t_info	*info;
	char	*ext_path;

	if (ft_strequ(path, "/"))
		ext_path = path;
	else
		ext_path = ft_strjoin(path, "/");
	targets = NULL;
	while (f_n)
	{
		info = get_info(ft_strjoin(ext_path, (char*)(f_n->content)), flags);
		if (info == NULL)
			ft_printf("ft_ls: %s: Permission denied\n", (char*)(f_n->content));
		else
		{
			next = ft_lstnew(info, sizeof(t_info));
			ft_lstadd(&targets, next);
		}
		f_n = f_n->next;
	}
	if (targets)
		buble_sort(targets, flags);
	return (targets);
}

t_list	*get_bad_file(char *s)
{
	t_list *tmp;

	tmp = ft_lstnew(s, ft_strlen(s) + 1);
	return (tmp);
}

t_list	*sub_input(t_list *targets, t_list *bad_files, t_flags *flags)
{
	t_list *next;

	if (targets == NULL && !bad_files)
	{
		next = ft_lstnew(get_info(".", flags), sizeof(t_info));
		ft_lstadd(&targets, next);
	}
	if (bad_files)
	{
		flags->d_n = 2;
		sort_string(bad_files);
		ft_lstiter(bad_files, print_no_such_file);
	}
	return (targets);
}

t_list	*get_next(t_info *info)
{
	t_list *next;

	next = ft_lstnew(info, sizeof(t_info));
	return (next);
}

t_list	*proc_input(int ac, char **av, t_flags *flags)
{
	t_list	*targets;
	int		i[2];
	t_info	*info;
	t_list	*bad_files;

	i[0] = 0;
	i[1] = 0;
	targets = NULL;
	bad_files = NULL;
	while (++i[0] < ac)
	{
		if (av[i[0]][0] == '-' && av[i[0]][1] && i[1] == 0)
			def_lags(flags, av[i[0]]);
		else
		{
			if ((info = get_info(av[i[0]], flags)) == NULL)
				ft_lstadd(&bad_files, get_bad_file(av[i[0]]));
			else
				ft_lstadd(&targets, get_next(info));
			i[1] = 1;
		}
	}
	return (sub_input(targets, bad_files, flags));
}
