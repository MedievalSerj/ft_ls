/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 19:13:37 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/06 19:13:42 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_tolower(char *s)
{
	char	*tmp;
	int		i;

	if (s == NULL)
		return (NULL);
	i = -1;
	tmp = ft_strnew(ft_strlen(s) + 1);
	while (s[++i])
		tmp[i] = (char)ft_tolower(s[i]);
	return (tmp);
}
