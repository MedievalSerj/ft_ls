/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:25:46 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 20:25:48 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	select_f(t_d_dec *val, int *n)
{
	if (val->type == '%')
		persent(val, n);
	else if (val->type == 'i' || val->type == 'd' || val->type == 'D')
		d_signed_decimal(val, n);
	else if (val->type == 'u' || val->type == 'U')
		u_unsigned_decimal(val, n);
	else if (val->type == 'c' && ft_strcmp(val->size, "l") != 0)
		c_char(val, n);
	else if (val->type == 'C' || (val->type == 'c' &&
		ft_strcmp(val->size, "l") == 0))
		wc_char(val, n);
	else if (val->type == 'x' || val->type == 'X')
		x_hex(val, n);
	else if (val->type == 'o' || val->type == 'O')
		o_octal(val, n);
	else if (val->type == 's' && ft_strcmp(val->size, "l") != 0)
		s_string(val, n);
	else if (val->type == 'S' || (val->type == 's' &&
		ft_strcmp(val->size, "l") == 0))
		ws_string(val, n);
	else if (val->type == 'p')
		p_hex(val, n);
}
