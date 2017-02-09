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

char	*ft_str_u_long(unsigned long long n, char *tmp)
{
	if (tmp == NULL)
		tmp = ft_strnew(22);
	if ((unsigned long long)n > 9)
	{
		tmp = ft_str_u_long((unsigned long long)n / 10, tmp);
		tmp = ft_str_u_long((unsigned long long)n % 10, tmp);
	}
	else
	{
		tmp = ft_str_append_unsafe(tmp, ('0' + n));
	}
	return (tmp);
}
