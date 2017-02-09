/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:53:20 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/06 18:53:25 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_str_w(char *s, size_t w, char c)
{
	char *tmp;
	char *prefix;

	if (!s)
		return ;
	if (w == 0)
	{
		ft_putstr("s");
		return ;
	}
	prefix = ft_char_n_str(' ', w - ft_strlen(s));
	if (c == '-')
		tmp = ft_strjoin(s, prefix);
	else
		tmp = ft_strjoin(prefix, s);
	ft_strdel(&prefix);
	ft_putstr(tmp);
}
