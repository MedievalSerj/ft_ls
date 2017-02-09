/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 13:23:15 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/15 13:23:18 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	sub_validate_size(char **desc, int *i, char **tmp, int *k)
{
	while (desc[1][*i] && desc[1][*i] == 'h')
	{
		(*k)++;
		(*i)++;
	}
	if (*k == 2 && *tmp[0] == '\0')
		*tmp = "hh";
	else if (*k == 1 && *tmp[0] == '\0')
		*tmp = "h";
	*k = 0;
	while (desc[1][*i] && desc[1][*i] == 'l')
	{
		(*k)++;
		(*i)++;
	}
	if (*k >= 2)
	{
		*tmp = "ll";
		(*i)--;
	}
	else if (*k == 1)
	{
		*tmp = "l";
		(*i)--;
	}
}

void	validate_size(char **desc)
{
	int		i;
	char	*tmp;
	int		k;

	tmp = "";
	i = -1;
	k = 0;
	while (desc[1][++i])
	{
		sub_validate_size(desc, &i, &tmp, &k);
		k = 0;
		if (desc[1][i] && desc[1][i] == 'j')
			tmp = "j";
		else if (desc[1][i] && desc[1][i] == 'z')
			tmp = "z";
	}
	desc[1] = ft_strdup(tmp);
}
