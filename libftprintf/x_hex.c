/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:36:12 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 20:36:13 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned long long	c_s(unsigned long long arg, char *size)
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

void				sub(t_d_dec *val, long long arg, char **tmp, int *n)
{
	if (val->precision_flag && val->precision == 0 && arg == 0)
		*tmp = ft_strnew(2);
	else
		*tmp = ft_strdup(ft_str_hex(arg, n[1], 16));
}

void				sub_2(int *n, char **tmp, t_d_dec *val)
{
	n[1] = 0;
	*tmp = NULL;
	if (val->type == 'X')
		n[1] = 1;
}

static char			*put_dec(t_d_dec *val, long long arg)
{
	char	*tmp;
	int		n[2];

	sub_2(n, &tmp, val);
	sub(val, arg, &tmp, n);
	if ((n[0] = val->precision - (int)ft_strlen(tmp)) > 0)
		tmp = ft_strjoin(ft_char_n_str('0', n[0]), tmp);
	else if ((((n[0] = val->width - (int)ft_strlen(tmp)) > 0) && val->zero
		&& !val->minus && !val->precision && arg == 0 && !val->precision_flag))
		tmp = ft_strjoin(ft_char_n_str('0', n[0]), tmp);
	else if ((((n[0] = val->width - (int)ft_strlen(tmp) - (val->pound * 2)) > 0)
		&& val->zero && !val->minus && !val->precision && arg != 0 &&
		!val->precision_flag))
		tmp = ft_strjoin(ft_char_n_str('0', n[0]), tmp);
	if (val->pound && arg != 0 && (val->type == 'x'))
		tmp = ft_strjoin("0x", tmp);
	else if (val->pound && arg != 0 && (val->type == 'X'))
		tmp = ft_strjoin("0X", tmp);
	else if (val->pound && arg != 0 && (val->type == 'o' || val->type == 'O'))
		tmp = ft_strjoin("0", tmp);
	if ((n[0] = val->width - (int)ft_strlen(tmp)) > 0 && !val->minus)
		tmp = ft_strjoin(ft_char_n_str(' ', n[0]), tmp);
	else if ((n[0] = val->width - (int)ft_strlen(tmp)) > 0)
		tmp = ft_strjoin(tmp, ft_char_n_str(' ', n[0]));
	return (tmp);
}

void				x_hex(t_d_dec *val, int *n)
{
	char				*result;
	unsigned long long	arg;

	arg = (unsigned long long)val->data;
	arg = c_s(arg, val->size);
	result = put_dec(val, arg);
	*n += ft_strlen(result);
	ft_putstr(result);
}
