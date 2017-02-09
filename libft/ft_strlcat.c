/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:49:22 by sladonia          #+#    #+#             */
/*   Updated: 2016/11/22 12:49:26 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[j] && (i + 1) < size)
		dest[i++] = src[j++];
	dest[i] = 0;
	if (!j)
		i = size;
	while (src[j++])
		i++;
	return (i);
}
