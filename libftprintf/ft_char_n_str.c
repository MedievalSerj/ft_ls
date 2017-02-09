/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_n_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:16:37 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 18:16:40 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_char_n_str(char c, size_t n)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_strnew(n + 1);
	while ((size_t)(++i) < n)
		tmp[i] = c;
	return (tmp);
}
