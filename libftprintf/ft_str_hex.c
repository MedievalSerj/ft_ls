/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:12:50 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 20:12:53 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count_i(unsigned long long k, int base)
{
	int i;

	i = -1;
	while (k > 0)
	{
		k = k / base;
		i++;
	}
	return (i);
}

char		*ft_str_hex(unsigned long long n, int h, int base)
{
	char	**valid;
	char	*result;
	int		i;

	if (n == 0)
		return ("0");
	result = ft_strnew(17);
	valid = (char**)malloc(sizeof(char*) * 2);
	valid[0] = "0123456789abcdef";
	valid[1] = "0123456789ABCDEF";
	i = count_i(n, base);
	while (n > 0)
	{
		if (h == 1)
			result[i] = valid[1][n % base];
		else
			result[i] = valid[0][n % base];
		n = n / base;
		i--;
	}
	return (result);
}
