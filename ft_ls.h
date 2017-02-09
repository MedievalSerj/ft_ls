/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sladonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:08:47 by sladonia          #+#    #+#             */
/*   Updated: 2017/02/08 19:08:50 by sladonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LS_FT_LS_H
# define _FT_LS_FT_LS_H
# include "libft/libft.h"
# include "libftprintf/libftprintf.h"
# include <sys/xattr.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# define MAX(x, y) x > y ? x : y

typedef struct	s_width
{
	size_t		w_link;
	size_t		w_owner;
	size_t		w_group;
	size_t		w_size;
	size_t		w_name;
}				t_width;
typedef struct	s_flags
{
	int			one;
	int			l;
	int			rec;
	int			a;
	int			r;
	int			t;
	int			d_n;
	int			d_newline;
}				t_flags;
typedef struct	s_info
{
	int			no_such_file;
	char		*name;
	char		*path;
	char		type;
	int			mode;
	char		*modes;
	int			n_links;
	char		*c_n_links;
	char		*owner;
	char		*group;
	blkcnt_t	blocks;
	off_t		size;
	char		*c_size;
	int			major;
	int			minor;
	time_t		mod_time;
	char		*mod_date;
	char		*links_to;
	char		*links_to_final;
	char		*year;
	char		*month;
	char		*day;
	char		*time;
	int			l;
	int			rec;
	int			a;
	int			r;
	int			t;
	size_t		w_link;
	size_t		w_owner;
	size_t		w_group;
	size_t		w_size;
}				t_info;
void			chose_f(t_flags *flags, t_list *targets);
t_list			*proc_input(int ac, char **av, t_flags *flags);
t_list			*get_t_list_infos(t_list *f_n, t_flags *flags, char *path);
t_flags			*init_flags(void);
t_list			*list_dir(char *path);
void			print_no_such_file(t_list *elem);
void			print_info_global(t_list *elem);
void			del_list_info(void *data, size_t size);
void			buble_sort(t_list *infos, t_flags *flags);
t_list			*initial_sort(t_list *targets, t_flags *flags);
void			sort_string(t_list *s);
int				get_field_width(t_list *head);
void			ft_put_str_w(char *s, size_t w, char c);
void			get_initial_width(t_list *head);
size_t			list_size(t_list *head);
void			process_link(t_info *info);
char			*get_name(char *path);
void			process_time(t_info *info, struct stat *buf);
char			*get_modes(mode_t mode);
char			get_filetype(mode_t mode);
t_info			*get_info(char *path, t_flags *flags);
void			iterate_links(t_list *targets, t_flags *flags);
void			def_lags(t_flags *flags, char *av);
void			print_info_global_dir(t_list *elem);
void			sub_process_dir(t_list *targets, t_flags *flags);
void			print_time_year(t_info *info);
#endif
