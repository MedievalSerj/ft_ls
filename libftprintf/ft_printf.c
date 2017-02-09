/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:45:38 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 19:45:41 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	sub_printf_2(const char **format, int *n)
{
	ft_putchar(**format);
	(*n)++;
}

int		sub_printf_3(const char **format, va_list args, int *n)
{
	t_d_dec	*val;
	char	**desc;

	desc = (char**)malloc(sizeof(char*) * 2);
	val = init_t_d_dec();
	(*format)++;
	define_description(*format, desc);
	*format = define_t(*format, &(val->type));
	validate_size(desc);
	if (val->type == '0')
		sub_printf_2(&(*format), n);
	else if (val->type == 'q')
		return (0);
	else
	{
		val = fill_t_d_desc(val->type, desc, args, val);
		select_f(val, n);
	}
	ft_strdel(&desc[0]);
	ft_strdel(&desc[1]);
	free(val);
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		n;

	n = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (sub_printf_3(&format, args, &n) == 0)
				return (n);
		}
		else
			sub_printf_2(&format, &n);
		format++;
	}
	va_end(args);
	return (n);
}
