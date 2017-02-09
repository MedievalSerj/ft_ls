/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:24:27 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 20:24:30 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*sub_init_str(int precision)
{
	char	*tmp;
	int		i;
	char	*s_null;

	i = -1;
	s_null = "(null)";
	tmp = ft_strnew(7);
	while (s_null[++i] && precision)
	{
		tmp[i] = s_null[i];
		precision--;
	}
	return (tmp);
}

char	*init_str(char *s, int precision, int precision_flag)
{
	char	*tmp;
	int		i;
	char	*s_null;

	i = -1;
	s_null = "(null)";
	if (s == NULL && !precision_flag)
		return (s_null);
	else if (s == NULL)
		return (sub_init_str(precision));
	else if (precision_flag == 0)
		return (ft_strdup(s));
	tmp = ft_strnew(ft_strlen(s) + 1);
	while (s[++i] && precision)
	{
		tmp[i] = s[i];
		precision--;
	}
	return (tmp);
}

void	s_string(t_d_dec *val, int *n)
{
	char	*result;
	int		k;

	result = init_str((char*)val->data, val->precision, val->precision_flag);
	if ((k = (val->width - (int)ft_strlen(result))) > 0 && !val->minus &&
		val->zero)
		result = ft_strjoin(ft_char_n_str('0', (size_t)k), result);
	else if ((k = (val->width - (int)ft_strlen(result))) > 0 && !val->minus)
		result = ft_strjoin(ft_char_n_str(' ', (size_t)k), result);
	else if ((k = (val->width - (int)ft_strlen(result))) > 0)
		result = ft_strjoin(result, ft_char_n_str(' ', (size_t)k));
	(*n) += ft_strlen(result);
	ft_putstr(result);
}
