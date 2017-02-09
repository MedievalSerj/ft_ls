/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:56:44 by sladonia          #+#    #+#             */
/*   Updated: 2017/01/18 20:56:45 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFTPRINTF_H
# define __LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# define BUFF 1024

typedef struct	s_d_dec
{
	void		*data;
	char		*size;
	char		type;
	int			width;
	int			precision;
	int			precision_flag;
	int			sign;
	int			plus;
	int			minus;
	int			zero;
	int			space;
	int			pound;
}				t_d_dec;
int				ft_printf(const char *format, ...);
char			*ft_str_append(char *s, char c);
void			select_f(t_d_dec *val, int *n);
void			d_signed_decimal(t_d_dec *val, int *n);
void			u_unsigned_decimal(t_d_dec *val, int *n);
void			x_hex(t_d_dec *val, int *n);
void			persent(t_d_dec *val, int *n);
void			c_char(t_d_dec *val, int *n);
void			wc_char(t_d_dec *val, int *n);
void			s_string(t_d_dec *val, int *n);
void			ws_string(t_d_dec *val, int *n);
void			p_hex(t_d_dec *val, int *n);
char			*ft_str_long(long long n, char *tmp);
char			*ft_str_append_unsafe(char *s, char c);
char			*ft_char_n_str(char c, size_t n);
const char		*define_t(const char *s, char *type);
void			define_description(const char *sring, char **desc);
void			validate_size(char **desc);
t_d_dec			*fill_t_d_desc(char type, char **desc, va_list args,
				t_d_dec *val);
char			*ft_str_u_long(unsigned long long n, char *tmp);
char			*ft_str_hex(unsigned long long n, int h, int base);
void			o_octal(t_d_dec *val, int *n);
t_d_dec			*init_t_d_dec(void);
char			*encode_c(wchar_t n, int *k, int p);
#endif
