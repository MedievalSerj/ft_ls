/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:31:21 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 20:31:22 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*put_null(t_d_dec *val, int *l)
{
	char	*tmp;
	int		i;
	char	*s_null;

	i = -1;
	s_null = "(null)";
	tmp = ft_strnew(7);
	if (val->precision_flag == 0)
	{
		*l = 6;
		return (s_null);
	}
	while (s_null[++i] && val->precision)
	{
		tmp[i] = s_null[i];
		(val->precision)--;
	}
	*l = (int)ft_strlen(tmp);
	return (tmp);
}

char	*put_wchar(wchar_t *result, int *k, t_d_dec *val)
{
	int		i;
	char	*tmp;
	char	*to_ret;
	int		p;
	int		k1;

	i = -1;
	k1 = 0;
	p = val->precision;
	to_ret = ft_strnew(5);
	while (result[++i])
	{
		if (!val->precision_flag)
			p = k1 + 4;
		tmp = encode_c(result[i], &k1, p - k1);
		to_ret = ft_strjoin(to_ret, tmp);
		free(tmp);
	}
	(*k) += k1;
	return (to_ret);
}

void	ws_string(t_d_dec *val, int *n)
{
	wchar_t	*result;
	int		k;
	int		l;
	char	*tmp;

	l = 0;
	k = 0;
	if (val->data != NULL)
	{
		result = (wchar_t*)val->data;
		tmp = put_wchar(result, &l, val);
	}
	else
		tmp = put_null(val, &l);
	if ((k = val->width - l) > 0 && !val->minus && val->zero)
		ft_putstr(ft_char_n_str('0', (size_t)k));
	else if ((k = val->width - l) > 0 && !val->minus)
		ft_putstr(ft_char_n_str(' ', (size_t)k));
	ft_putstr(tmp);
	if ((k = val->width - l) > 0 && val->minus)
		ft_putstr(ft_char_n_str(' ', (size_t)k));
	(*n) += l + (k > 0 ? k : 0);
}
