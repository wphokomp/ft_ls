/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 11:16:08 by wphokomp          #+#    #+#             */
/*   Updated: 2017/08/11 17:05:18 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include "libft/libft.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_env	t_env;

struct	s_env
{
	DIR				*dir;
	char			*path;
	char			**content;
	time_t			time;
	struct dirent	*sd;
	struct stat		fstat;
};

void	ft_permissions(struct stat fstat);
void	ft_ls_sort(char **list);
void	ft_getcontent(t_env *e);
char	*ft_getusr(struct stat fstat);
void	ft_getdate(struct stat fstat);
void	ft_printsize(char *str, t_env *e);
//Flags
void	ft_l(struct stat fstat, t_env *e);
void	ft_list(t_env *e);
void	ft_list_all(t_env *e);

#endif
