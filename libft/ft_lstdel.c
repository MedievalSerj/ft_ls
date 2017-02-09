/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:26:40 by sladonia          #+#    #+#             */
/*   Updated: 2016/11/29 19:26:42 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *tmp;

	tmp = (*alst);
	while (tmp)
	{
		*alst = (*alst)->next;
		ft_lstdelone(&tmp, del);
		tmp = (*alst);
	}
	(*alst) = NULL;
}
