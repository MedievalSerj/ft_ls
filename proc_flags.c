/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:22:17 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/08 17:22:20 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flags	*init_flags(void)
{
	t_flags *flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->l = 0;
	flags->rec = 0;
	flags->a = 0;
	flags->r = 0;
	flags->t = 0;
	flags->d_n = 1;
	flags->d_newline = 0;
	flags->one = 0;
	return (flags);
}

void	def_lags(t_flags *flags, char *av)
{
	int i;

	i = 0;
	while (av[++i])
	{
		if (av[i] == 'l')
			flags->l = 1;
		else if (av[i] == 'R')
			flags->rec = 1;
		else if (av[i] == 'a')
			flags->a = 1;
		else if (av[i] == 'r')
			flags->r = 1;
		else if (av[i] == 't')
			flags->t = 1;
		else if (av[i] == '1')
			flags->one = 1;
		else
		{
			ft_printf("ft_ls: illegal option -- %c\n", av[i]);
			ft_putstr("usage: ft_ls [-lRart] [file ...]\n");
			exit(0);
		}
	}
}
