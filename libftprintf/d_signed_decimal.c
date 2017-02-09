/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_signed_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:12:57 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 18:13:01 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long long	cast_size(long long arg_long, char *size)
{
	if (ft_strcmp(size, "ll") == 0)
		arg_long = (long long)arg_long;
	else if (ft_strcmp(size, "l") == 0)
		arg_long = (long)arg_long;
	else if (ft_strcmp(size, "j") == 0)
		arg_long = (intmax_t)arg_long;
	else if (ft_strcmp(size, "z") == 0)
		arg_long = (ssize_t)arg_long;
	else if (ft_strcmp(size, "h") == 0)
		arg_long = (short)arg_long;
	else if (ft_strcmp(size, "hh") == 0)
		arg_long = (char)arg_long;
	else if (ft_strcmp(size, "") == 0)
		arg_long = (int)arg_long;
	return (arg_long);
}

char				*put_dec(t_d_dec *val, long long arg_long)
{
	char	*tmp;
	int		n;

	if (val->precision_flag && !val->precision && arg_long == 0)
		tmp = ft_strnew(3);
	else
		tmp = ft_strdup(ft_str_long(arg_long, NULL));
	if ((n = val->precision - (int)ft_strlen(tmp)) > 0)
		tmp = ft_strjoin(ft_char_n_str('0', n), tmp);
	else if ((((n = val->width - (int)ft_strlen(tmp) - (val->plus | val->space))
		> 0) && val->zero && !val->minus && !val->precision_flag))
		tmp = ft_strjoin(ft_char_n_str('0', n), tmp);
	if (val->plus && val->sign == -1)
		tmp = ft_strjoin("-", tmp);
	else if (val->plus && val->sign == 1)
		tmp = ft_strjoin("+", tmp);
	if (val->space && !val->plus)
		tmp = ft_strjoin(" ", tmp);
	if ((n = val->width - (int)ft_strlen(tmp)) > 0 && !val->minus)
		tmp = ft_strjoin(ft_char_n_str(' ', n), tmp);
	else if ((n = val->width - (int)ft_strlen(tmp)) > 0)
		tmp = ft_strjoin(tmp, ft_char_n_str(' ', n));
	return (tmp);
}

void				d_signed_decimal(t_d_dec *val, int *n)
{
	char		*result;
	long long	arg_long;

	if (val->type == 'D')
		val->size = "ll";
	arg_long = (long long)val->data;
	arg_long = cast_size(arg_long, val->size);
	if (arg_long < 0)
	{
		val->sign = -1;
		val->plus = 1;
	}
	result = put_dec(val, arg_long);
	*n += ft_strlen(result);
	ft_putstr(result);
}
