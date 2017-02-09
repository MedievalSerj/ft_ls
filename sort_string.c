/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:07:13 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/08 19:07:16 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_string(t_list *s)
{
	char	*tmp;
	t_list	*current;
	int		swaped;

	swaped = 1;
	while (swaped)
	{
		swaped = 0;
		current = s;
		while (current->next)
		{
			if (ft_strcmp((current->content), ((current->next)->content)) > 0)
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
