/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:30:25 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 20:30:29 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	wc_char(t_d_dec *val, int *n)
{
	char	*c;
	int		k;
	int		p;

	k = 0;
	p = 0;
	c = ft_strnew(5);
	c = encode_c((wchar_t)val->data, &p, 4);
	if ((k = val->width - p) > 0 && !val->minus)
		ft_putstr(ft_char_n_str(' ', (size_t)k));
	if (val->data)
		ft_putstr(c);
	else
		ft_putchar(0);
	if ((k = val->width - p) > 0 && val->minus)
		ft_putstr(ft_char_n_str(' ', (size_t)k));
	(*n) += p + (k > 0 ? k : 0);
}
