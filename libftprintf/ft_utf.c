/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:05:14 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/21 17:05:17 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	sub_utf(char **c, int *k, wchar_t n)
{
	(*c)[0] = (unsigned char)(((n << 6) | 0xF0000000) >> 24);
	(*c)[1] = (unsigned char)(((n << 4) >> 16) | 0x80);
	(*c)[2] = (unsigned char)((((n << 2) & 0x3FBF) >> 8) | 0x80);
	(*c)[3] = (unsigned char)((n & 0xBF) | 0x80);
	(*k) += 4;
}

char	*encode_c(wchar_t n, int *k, int p)
{
	char *c;

	c = ft_strnew(5);
	if (n <= 0x7F && p >= 1)
	{
		c[0] = (unsigned char)n;
		(*k) += 1;
	}
	else if (n <= 0x7FF && p >= 2)
	{
		c[0] = (unsigned char)(((n << 2) | 0xC000) >> 8);
		c[1] = (unsigned char)((n & 0xBF) | 0x80);
		(*k) += 2;
	}
	else if (n <= 0xFFFF && p >= 3)
	{
		c[0] = (unsigned char)(((n << 4) | 0xE00000) >> 16);
		c[1] = (unsigned char)((((n << 2) & 0x3FBF) >> 8) | 0x80);
		c[2] = (unsigned char)((n & 0xBF) | 0x80);
		(*k) += 3;
	}
	else if (n <= 0x1FFFFF && p >= 4)
		sub_utf(&c, k, n);
	return (c);
}
