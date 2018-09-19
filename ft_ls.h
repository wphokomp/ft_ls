/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:28:24 by wphokomp          #+#    #+#             */
/*   Updated: 2017/11/29 09:49:36 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <time.h>
# include <stdio.h>

typedef struct	s_content
{
	dev_t				device;
	char				type;
	char				*permission;
	int					link;
	char				*usr;
	char				*grp;
	int					size;
	int					blocks;
	char				*date;
	unsigned int		timestamp;
	char				*name_;
	char				*parent_dir;
	struct s_content	*next;
}				t_content;

typedef struct	s_args
{
	char		*auth_args;
	char		*args;
	t_content	*dir_s;
}				t_args;

void			ft_check_args(int ac, char **av, t_args *args);
void			ft_get_content(t_args *args);
void			ft_lst_add(t_content **lead, t_content *next);
void			ft_lst_insert(t_content *target, char *next);
void			ft_addto_lst(t_content *target, t_content *next);
void			ft_pad(t_content *file, int size, char field);

void			ft_print_err(char *msg, int time);
void			ft_errmsg(char *msg, int teminate);

void			ft_free(t_content *lead);
void			ft_free_lst(t_content *lead);
void			ft_free_args(t_args *args);
void			ft_print_file(t_content *file, t_args *args
		, int links, int size);
void			ft_print_dir(t_content *file, char *name, t_args *args);

t_content		*ft_get_detail(char *file, char lnk);
t_content		*ft_cpylnk(t_content *lnk);
t_content		*ft_sort_by_args(t_content *lead, char *args, char name_);

char			*ft_permissions(mode_t file);
char			ft_filetype(mode_t file);
char			*ft_get_date(struct stat details);
char			*ft_get_grp(struct stat details);
char			*ft_get_usr(struct stat details);

int				ft_get_col_len(t_content *lead, char field);
int				ft_get_size(t_content *lead);

#endif
