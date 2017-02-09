/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:16:17 by sladonia          #+#    #+#             */
/*   Updated: 2016/11/28 16:16:20 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_w(const char *s, char c)
{
	size_t	i;
	size_t	n;
	int		f;

	i = 0;
	n = 0;
	f = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && f)
		{
			n++;
			f = 0;
		}
		else if (s[i] == c)
			f = 1;
		i++;
	}
	return (n);
}

static size_t	count_l(const char *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
			n++;
		else
			break ;
		i++;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**r;
	int		i;
	int		j;
	int		k;

	i = -1;
	k = -1;
	if (!s)
		return (NULL);
	if (!(r = (char**)malloc(sizeof(char*) * (count_w(s, c) + 1))))
		return (NULL);
	while (s[++i])
	{
		if (s[i] == c)
			continue ;
		if (!(*(r + (++k)) = (char*)malloc((count_l(&s[i], c) + 1))))
			return (NULL);
		j = -1;
		while (s[i + (++j)] != c && s[i + j])
			r[k][j] = s[i + j];
		i = i + j - 1;
		r[k][j] = '\0';
	}
	*(r + (++k)) = NULL;
	return (r);
}
