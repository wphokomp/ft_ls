/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stats.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:45:32 by wphokomp          #+#    #+#             */
/*   Updated: 2017/11/29 10:02:11 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*ft_get_grp(struct stat detail)
{
	struct group	*grp;

	if (!(grp = getgrgid(detail.st_gid)))
		ft_errmsg("get_group()", 1);
	return (grp->gr_name);
}

char	*ft_get_usr(struct stat detail)
{
	struct passwd	*usr;

	if (!(usr = getpwuid(detail.st_uid)))
		ft_errmsg("get_usr()", 1);
	return (usr->pw_name);
}

char	*ft_get_date(struct stat detail)
{
	char	*time_file;
	char	**tbl_file;
	char	*t_now;
	time_t	now;
	char	**tbl_now;

	now = time(NULL);
	t_now = ctime(&now);
	tbl_now = ft_strsplit(ft_strtrim(t_now), ' ');
	time_file = ft_strtrim(ctime(&(detail.st_mtimespec.tv_sec)));
	tbl_file = ft_strsplit(time_file, ' ');
	if (!ft_strcmp(tbl_now[4], tbl_file[4]))
	{
		tbl_file[3][5] = 0;
		time_file = ft_strjoin_nolim(' ', tbl_file[1],
				tbl_file[2], tbl_file[3], NULL);
	}
	else
		time_file = ft_strjoin_nolim(' ', tbl_file[1],
				tbl_file[2], tbl_file[3], NULL);
	ft_memdel((void **)&tbl_now);
	ft_memdel((void **)tbl_file);
	return (time_file);
}

char	ft_filetype(mode_t file_mode)
{
	if (S_ISDIR(file_mode))
		return ('d');
	else if (S_ISFIFO(file_mode))
		return ('p');
	else if (S_ISCHR(file_mode))
		return ('c');
	else if (S_ISBLK(file_mode))
		return ('b');
	else if (S_ISSOCK(file_mode))
		return ('s');
	else if (S_ISREG(file_mode))
		return ('-');
	else if (S_ISLNK(file_mode))
		return ('l');
	else
		return ('-');
}

char	*ft_permissions(mode_t file_mode)
{
	char	*p;

	p = ft_strnew(10);
	(file_mode & S_IRUSR) ? ft_strcat(p, "r") : ft_strcat(p, "-");
	(file_mode & S_IWUSR) ? ft_strcat(p, "w") : ft_strcat(p, "-");
	(file_mode & S_IXUSR) ? ft_strcat(p, "x") : ft_strcat(p, "-");
	(file_mode & S_IRGRP) ? ft_strcat(p, "r") : ft_strcat(p, "-");
	(file_mode & S_IWGRP) ? ft_strcat(p, "w") : ft_strcat(p, "-");
	(file_mode & S_IXGRP) ? ft_strcat(p, "x") : ft_strcat(p, "-");
	(file_mode & S_IROTH) ? ft_strcat(p, "r") : ft_strcat(p, "-");
	(file_mode & S_IWOTH) ? ft_strcat(p, "w") : ft_strcat(p, "-");
	(file_mode & S_IXOTH) ? ft_strcat(p, "x") : ft_strcat(p, "-");
	return (p);
}
