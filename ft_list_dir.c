/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:50:36 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/08 15:50:39 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*list_dir(char *path)
{
	DIR				*dir;
	struct dirent	*entry;
	t_list			*head;
	t_list			*tmp;

	if ((dir = opendir(path)) == NULL)
	{
		ft_printf("ft_ls: %s: Permission denied\n", get_name(path));
		return (NULL);
	}
	head = NULL;
	while ((entry = readdir(dir)) != NULL)
	{
		tmp = ft_lstnew(entry->d_name, (ft_strlen(entry->d_name) + 1));
		ft_lstadd(&head, tmp);
	}
	closedir(dir);
	return (head);
}

void	print_time_year(t_info *info)
{
	time_t	current;
	long	diff;

	current = time(NULL);
	diff = current - info->mod_time;
	if (diff > 15770000 || diff < 3)
		ft_put_str_w(info->year, 6, 0);
	else
		ft_put_str_w(info->time, 6, 0);
}
