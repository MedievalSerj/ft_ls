/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:20:04 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 20:20:07 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*format(char *tmp, t_d_dec *val)
{
	int n;

	if ((n = (val->precision - (int)ft_strlen(tmp))) > 0)
		tmp = ft_strjoin(ft_char_n_str('0', n), tmp);
	else if ((((n = val->width - (int)ft_strlen(tmp) - 2) > 0) &&
		val->zero && !val->minus && !val->precision))
		tmp = ft_strjoin(ft_char_n_str('0', n), tmp);
	if (val->minus && (n = val->width - (int)ft_strlen(tmp) -
		2 - (val->plus)) > 0)
		tmp = ft_strjoin(tmp, ft_char_n_str(' ', n));
	tmp = ft_strjoin("0x", tmp);
	if ((n = val->width - (int)ft_strlen(tmp)) > 0)
		tmp = ft_strjoin(ft_char_n_str(' ', n), tmp);
	return (tmp);
}

void		p_hex(t_d_dec *val, int *n)
{
	char *result;

	if (val->precision_flag && val->precision == 0 &&
		(unsigned long long)val->data == 0)
		result = "";
	else
		result = ft_strdup(ft_str_hex((unsigned long long)val->data, 0, 16));
	result = format(result, val);
	*n += ft_strlen(result);
	ft_putstr(result);
}
