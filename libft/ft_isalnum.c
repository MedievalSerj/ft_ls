/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:38:25 by sladonia          #+#    #+#             */
/*   Updated: 2016/11/24 15:38:33 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	if (c < 0 || c > 127)
		return (0);
	if (((unsigned char)c >= 'A' && (unsigned char)c <= 'Z') ||
		((unsigned char)c >= 'a' && (unsigned char)c <= 'z') ||
			((unsigned char)c >= '0' && (unsigned char)c <= '9'))
		return (1);
	else
		return (0);
}
