/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 13:16:21 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/15 13:16:25 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		sub_define_description(char **desc, char valid, int *i, char *s)
{
	*desc = ft_str_append(*desc, valid);
	if (s[i[0] + 1] != '\0')
	{
		i[0]++;
		i[1] = -1;
	}
}

void		define_description(const char *string, char **desc)
{
	char	**valid;
	int		i[2];
	char	*s;

	valid = (char**)malloc(sizeof(char*) * 3);
	s = ft_strdup(string);
	valid[0] = "hljzzzzzzzzzzzz";
	valid[1] = "# -+.0123456789";
	valid[2] = "%sSpdDioOuUxXcC";
	i[0] = -1;
	desc[0] = ft_strnew(100);
	desc[1] = ft_strnew(100);
	while (s[++i[0]])
	{
		i[1] = -1;
		while (++i[1] < 15)
		{
			if (s[i[0]] == valid[1][i[1]])
				sub_define_description(&desc[0], valid[1][i[1]], i, s);
			else if (valid[0][i[1]] && s[i[0]] == valid[0][i[1]])
				sub_define_description(&desc[1], valid[0][i[1]], i, s);
			else if (s[i[0]] == valid[2][i[1]])
				return ;
		}
	}
}

void		mini_fuck(int *i)
{
	i[0]++;
	i[1] = -1;
}

int			sub_define_t(const char *s, char *type, int *i, char **types)
{
	i[1] = -1;
	while (s[i[0]] && ++i[1] <= 20)
	{
		if (i[1] == 20)
			return (1);
		else if (s[i[0]] == types[0][i[1]])
		{
			*type = types[0][i[1]];
			return (1);
		}
		else if (s[i[0]] == types[1][i[1]] &&
			((size_t)i[0] == ft_strlen(s) - 1))
		{
			*type = 'q';
			return (1);
		}
		else if (s[i[0]] == types[1][i[1]])
			mini_fuck(i);
	}
	return (0);
}

const char	*define_t(const char *s, char *type)
{
	int		i[2];
	char	**types;

	types = (char**)malloc(sizeof(char*) * 2);
	types[0] = "%sSpdDioOuUxXcCCCCC";
	types[1] = "# -+.0123456789hljz";
	i[0] = -1;
	while (s[++i[0]])
	{
		if (sub_define_t(s, type, i, types) == 1)
			return (&s[i[0]]);
	}
	*type = 'q';
	return (&s[i[0]]);
}
