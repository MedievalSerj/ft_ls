/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:26:35 by sladonia          #+#    #+#             */
/*   Updated: 2016/11/29 13:26:38 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_d(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char		*swap(char *s)
{
	int		i;
	int		n;
	char	tmp;

	i = 0;
	n = (int)ft_strlen(s) - 1;
	while (i <= n / 2)
	{
		tmp = s[i];
		s[i] = s[n - i];
		s[n - i] = tmp;
		i++;
	}
	return (s);
}

static char		*min_int(void)
{
	char *min;

	min = (char*)malloc(12);
	min[0] = '-';
	min[1] = '2';
	min[2] = '1';
	min[3] = '4';
	min[4] = '7';
	min[5] = '4';
	min[6] = '8';
	min[7] = '3';
	min[8] = '6';
	min[9] = '4';
	min[10] = '8';
	min[11] = '\0';
	return (min);
}

static char		*calculate(char *out, int n, int i, const char *c)
{
	while (1)
	{
		out[i++] = c[n % 10];
		if ((n = n / 10) == 0)
			break ;
	}
	return (out);
}

char			*ft_itoa(int n)
{
	char	*c;
	char	*out;
	int		i;
	int		p;

	i = 0;
	c = "0123456789";
	if (n == -2147483648)
		return (min_int());
	p = num_d(n);
	if (!(out = (char*)malloc(sizeof(char) * (p + 1))))
		return (NULL);
	if (n < 0)
	{
		out[p - 1] = '-';
		n = n * (-1);
	}
	out = calculate(out, n, i, c);
	out[p] = '\0';
	out = swap(out);
	return (out);
}
