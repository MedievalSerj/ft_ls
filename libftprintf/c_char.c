/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:10:07 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 18:10:12 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	infernal_fuck(char *s, t_d_dec *val)
{
	if ((char)(val->data) == 0)
	{
		if (val->minus)
		{
			ft_putchar(0);
			ft_putstr(s);
		}
		else
		{
			ft_putstr(s);
			ft_putchar(0);
		}
	}
	else
		ft_putstr(s);
}

void	c_char(t_d_dec *val, int *n)
{
	char	*result;
	char	c;
	int		k;

	if (val->data == NULL)
	{
		c = '\0';
		(*n)++;
	}
	else
		c = (char)val->data;
	result = ft_strnew(2);
	result[0] = c;
	if ((k = (val->width - 1)) > 0 && !val->minus && val->zero)
		result = ft_strjoin(ft_char_n_str('0', k), result);
	else if ((k = (val->width - 1)) > 0 && !val->minus)
		result = ft_strjoin(ft_char_n_str(' ', k), result);
	else if ((k = (val->width - 1)) > 0)
		result = ft_strjoin(result, ft_char_n_str(' ', k));
	(*n) += ft_strlen(result);
	infernal_fuck(result, val);
}
