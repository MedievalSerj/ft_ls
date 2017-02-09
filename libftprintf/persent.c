/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:23:25 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 20:23:29 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	persent(t_d_dec *val, int *n)
{
	char	*tmp;
	int		k;

	tmp = ft_strnew(2);
	tmp = ft_str_append(tmp, '%');
	if ((k = val->width - (int)ft_strlen(tmp)) > 0 && !val->minus && val->zero)
		tmp = ft_strjoin(ft_char_n_str('0', k), tmp);
	if ((k = val->width - (int)ft_strlen(tmp)) > 0 && !val->minus)
		tmp = ft_strjoin(ft_char_n_str(' ', k), tmp);
	else if ((k = val->width - (int)ft_strlen(tmp)) > 0)
		tmp = ft_strjoin(tmp, ft_char_n_str(' ', k));
	ft_putstr(tmp);
	(*n) += ft_strlen(tmp);
}
