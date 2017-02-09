/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:42:08 by sladonia          #+#    #+#             */
/*   Updated: 2016/11/29 16:42:12 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_str_long(long long n, char *tmp)
{
	if (n / 10 == -922337203685477580 && (n % 10 == -8))
		return ("9223372036854775808");
	if (tmp == NULL)
		tmp = ft_strnew(22);
	if ((long long)n < 0)
		tmp = ft_str_long((long long)(-n), tmp);
	else if ((long long)n > 9)
	{
		tmp = ft_str_long((long long)n / 10, tmp);
		tmp = ft_str_long((long long)n % 10, tmp);
	}
	else
	{
		tmp = ft_str_append_unsafe(tmp, ('0' + n));
	}
	return (tmp);
}
