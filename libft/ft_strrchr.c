/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:37:38 by sladonia          #+#    #+#             */
/*   Updated: 2016/11/22 16:37:42 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	n;
	int		flag;

	i = 0;
	n = 0;
	flag = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
		{
			n = i;
			flag = 1;
		}
		i++;
	}
	if (flag != 0)
		return ((char *)&s[n]);
	else
		return (NULL);
}
