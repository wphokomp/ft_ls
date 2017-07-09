/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:04:48 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/09 16:28:20 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "lib/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>

typedef	struct s_dir	t_dir;
typedef	struct s_env	t_env;

struct	s_dir
{
	char				*dir;
	time_t				time;
	int					is_dir;
	char				*full;
	struct s_dir		*next;
};

struct	s_env
{
	int					l;
	int					a;
	int					r;
	int					t;
	int					rev;
	char				*path;
	DIR					*dirp;
	struct dirent		*dp;
	struct stat			sb;
	t_dir				*list;
};

void	ft_ls(t_env *e);
void	ft_do_ls(char *dir, t_env *e);
void	ft_sort_lst(t_dir **head, int (*cmp)(t_dir, t_dir), int done);
void	ft_do_lst(t_env *e);
void	ft_print_lst(t_dir *list);
void	ft_init(t_env *e);
void	ft_free_var(t_dir *lst, t_env *tmp);

int		ft_cmptime(t_dir d1, t_dir d2);
int		ft_cmpstr(t_dir s1, t_dir s2);
int		ft_free_lst(t_dir *list);
int		ft_get_path(char *dir, char *name, t_dir *temp);

#endif
