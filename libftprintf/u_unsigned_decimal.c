/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_unsigned_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:27:42 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 20:27:45 by sladonia         ###   ########.fr       */
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
		arg = (size_t)arg;
	else if (ft_strcmp(size, "h") == 0)
		arg = (unsigned short)arg;
	else if (ft_strcmp(size, "hh") == 0)
		arg = (unsigned char)arg;
	else if (ft_strcmp(size, "") == 0)
		arg = (unsigned int)arg;
	return (arg);
}

char						*put_u_dec(t_d_dec *val, long long arg)
{
	char	*tmp;
	int		n;

	if (val->precision_flag && val->precision == 0 &&
		(unsigned long long)val->data == 0)
		tmp = "";
	else
		tmp = ft_strdup(ft_str_u_long(arg, NULL));
	if ((n = val->precision - (int)ft_strlen(tmp)) > 0)
		tmp = ft_strjoin(ft_char_n_str('0', n), tmp);
	else if (val->precision_flag && val->precision == 0 &&
		arg == 0 && val->zero)
		tmp = ft_strjoin(ft_char_n_str(' ', n), tmp);
	else if ((((n = val->width - (int)ft_strlen(tmp)) > 0) && val->zero &&
		!val->minus && !val->precision_flag))
		tmp = ft_strjoin(ft_char_n_str('0', n), tmp);
	if ((n = val->width - (int)ft_strlen(tmp)) > 0 && !val->minus)
		tmp = ft_strjoin(ft_char_n_str(' ', n), tmp);
	else if ((n = val->width - (int)ft_strlen(tmp)) > 0)
		tmp = ft_strjoin(tmp, ft_char_n_str(' ', n));
	return (tmp);
}

void						u_unsigned_decimal(t_d_dec *val, int *n)
{
	char				*result;
	unsigned long long	arg;

	if (val->type == 'U')
		val->size = "ll";
	arg = (unsigned long long)val->data;
	arg = cast_size(arg, val->size);
	result = put_u_dec(val, arg);
	*n += ft_strlen(result);
	ft_putstr(result);
}
