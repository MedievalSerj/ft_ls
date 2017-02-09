/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_octal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:18:17 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 20:18:22 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned long long	cast_size(unsigned long long arg, char *size)
{
	if (ft_strcmp(size, "ll") == 0)
		arg = (unsigned long long)arg;
	else if (ft_strcmp(size, "l") == 0)
		arg = (unsigned long)arg;
	else if (ft_strcmp(size, "j") == 0)
		arg = (uintmax_t)arg;
	else if (ft_strcmp(size, "z") == 0)
		arg = (ssize_t)arg;
	else if (ft_strcmp(size, "h") == 0)
		arg = (unsigned short)arg;
	else if (ft_strcmp(size, "hh") == 0)
		arg = (unsigned char)arg;
	else if (ft_strcmp(size, "") == 0)
		arg = (unsigned int)arg;
	return (arg);
}

static char					*put_dec(t_d_dec *val, long long arg)
{
	char	*tmp;
	char	*s;
	int		n;

	n = 0;
	tmp = ft_strdup(ft_str_hex(arg, 0, 8));
	if (val->precision_flag && val->precision == 0 && arg == 0 && !val->pound)
		tmp = ft_strnew(2);
	else
		tmp = ft_strdup(tmp);
	if (val->precision_flag && val->precision == 0 && arg == 0)
		tmp = ft_strjoin(ft_char_n_str(' ', n), tmp);
	else if ((n = val->precision - (int)ft_strlen(tmp)) > 0)
		tmp = ft_strjoin(ft_char_n_str('0', n), tmp);
	else if ((((n = val->width - (int)ft_strlen(tmp) - (val->pound)) > 0) &&
		val->zero && !val->minus && !val->precision && !val->precision_flag))
		tmp = ft_strjoin(ft_char_n_str('0', n), tmp);
	if (val->pound && arg != 0 && ((size_t)val->precision < ft_strlen(s)))
		tmp = ft_strjoin("0", tmp);
	if ((n = val->width - (int)ft_strlen(tmp)) > 0 && !val->minus)
		tmp = ft_strjoin(ft_char_n_str(' ', n), tmp);
	else if ((n = val->width - (int)ft_strlen(tmp)) > 0)
		tmp = ft_strjoin(tmp, ft_char_n_str(' ', n));
	return (tmp);
}

void						o_octal(t_d_dec *val, int *n)
{
	char				*result;
	unsigned long long	arg;

	if (val->type == 'O')
		val->size = "ll";
	arg = (unsigned long long)val->data;
	arg = cast_size(arg, val->size);
	result = put_dec(val, arg);
	*n += ft_strlen(result);
	ft_putstr(result);
}
