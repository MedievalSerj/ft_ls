/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:27:57 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/15 15:28:01 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_d_dec	*init_t_d_dec(void)
{
	t_d_dec *val;

	val = (t_d_dec*)malloc(sizeof(t_d_dec));
	val->size = ft_strnew(3);
	val->width = 0;
	val->precision = 0;
	val->precision_flag = 0;
	val->plus = 0;
	val->minus = 0;
	val->zero = 0;
	val->space = 0;
	val->sign = 1;
	val->data = NULL;
	val->pound = 0;
	val->type = '0';
	return (val);
}

void	sub_define_flags1(char *d, t_d_dec *val, int *i)
{
	char *tmp;

	tmp = ft_strnew(3);
	while (d[*i] >= 48 && d[*i] <= 57)
	{
		tmp = ft_str_append(tmp, d[*i]);
		(*i)++;
	}
	if (ft_atoi(tmp) > 0)
		val->width = ft_atoi(tmp);
	ft_strclr(tmp);
	(*i)--;
}

void	sub_define_flags2(char *d, t_d_dec *val, int *i)
{
	char *tmp;

	if (d[(*i) + 1] == '.')
	{
		(*i)++;
		sub_define_flags2(d, val, i);
	}
	else if (d[(*i) + 1] <= 48 && d[(*i) + 1] >= 57 && d[(*i) + 1])
		return ;
	tmp = ft_strnew(3);
	val->precision_flag = 1;
	while (d[++(*i)] >= 48 && d[*i] <= 57)
		tmp = ft_str_append(tmp, d[*i]);
	val->precision = ft_atoi(tmp);
	ft_strclr(tmp);
}

void	define_flags(char *d, t_d_dec *val)
{
	int		i;

	i = -1;
	while (d[++i])
	{
		if (d[i] == '.')
			sub_define_flags2(d, val, &i);
		else if (d[i] == '0')
			val->zero = 1;
		else if (d[i] >= 48 && d[i] <= 57)
			sub_define_flags1(d, val, &i);
		else if (d[i] == '-')
			val->minus = 1;
		else if (d[i] == '+')
			val->plus = 1;
		else if (d[i] == ' ')
			val->space = 1;
		else if (d[i] == '#')
			val->pound = 1;
	}
}

t_d_dec	*fill_t_d_desc(char type, char **desc, va_list args, t_d_dec *val)
{
	define_flags(desc[0], val);
	val->type = type;
	if (val->type != '%' && val->type != '0')
		val->data = va_arg(args, void*);
	val->size = desc[1];
	return (val);
}
