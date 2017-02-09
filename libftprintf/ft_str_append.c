/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:10:47 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 20:10:51 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_str_append(char *s, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(ft_strlen(s) + 3);
	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = c;
	ft_strdel(&s);
	return (tmp);
}
