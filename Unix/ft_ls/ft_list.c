/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 15:09:02 by wphokomp          #+#    #+#             */
/*   Updated: 2017/08/13 10:48:11 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_permissions(struct stat fstat)
{
	ft_putchar((S_ISDIR(fstat.st_mode)) ? 'd' : '-');
	ft_putchar((fstat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((fstat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((fstat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("  ");
}

char	*ft_getusr(struct stat fstat)
{
	char			*s;
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(fstat.st_uid);
	grp = getgrgid(fstat.st_gid);
	s = ft_strjoin(ft_strjoin(pwd->pw_name, "  "), grp->gr_name);
	return (ft_strjoin(s, "  "));
}

void	ft_getdate(struct stat fstat)
{
	char	*s;
	int		i;

	i = 0;
	s = ctime(&fstat.st_mtime) + 4;
	//ft_putchar(' ');
	while (i < ft_strlen(s) - 9)
		ft_putchar(s[i++]);
}

size_t	ft_padright(t_env *e)
{
	int		i;
	size_t	len;
	size_t	next;
	struct stat	fstat;

	i = 0;
	stat(e->content[i], &fstat);
	len = ft_strlen(ft_itoa(fstat.st_size));
	while (i++ < (ft_strlen_point(e->content) - 1))
	{
		stat(e->content[i + 1], &fstat);
		next = ft_strlen(ft_itoa(fstat.st_size));
		if (next > len)
			len = next;
	}
	return (len);
}

void	ft_printsize(char *str, t_env *e)
{
	size_t		i;
	struct stat	fstat;

	i = 0;
	while (i++ < (ft_padright(e) - ft_strlen(str)))
		ft_putchar(' ');
	ft_putstr(ft_strjoin(str, " "));
}

void	ft_ls_sort(char **list)
{
	char	*tmp;
	int		i;

	i = -1;
	while (++i < (ft_strlen_point(list) - 1))
		if (ft_strcmp(list[i], list[i + 1]) > 0)
		{
			tmp = list[i];
			list[i] = list[i + 1];
			list[i + 1] = tmp;
			i = -1;
		}
}

void	ft_getcontent(t_env *e)
{
	int		i;

	e->dir = opendir(e->path);
	if (e->dir)
	{
		i = 0;
		while ((e->sd = readdir(e->dir)))
			i++;
		e->content = ft_strnew_point(i);
		closedir(e->dir);
		e->dir = opendir(e->path);
		i = -1;
		while ((e->sd = readdir(e->dir)))
		{
			e->content[++i] = ft_strnew(ft_strlen((e->sd)->d_name));
			e->content[i] = (e->sd)->d_name;
		}
		closedir(e->dir);
	}
}

//<				START				>
void	ft_l(struct stat fstat, t_env *e)
{
	int		i;

	if (e->path == 0)
	{
		perror("String");
		exit(1);
	}
	i = -1;
	ft_getcontent(e);
	ft_ls_sort(e->content);
	e->dir = opendir(e->path);
	while ((e->sd = readdir(e->dir)) && ++i < ft_strlen_point(e->content))
		if (e->content[i][0] != '.')
		{
			stat(e->content[i], &fstat);
			ft_permissions(fstat);
			ft_putnbr(fstat.st_nlink);
			ft_putchar(' ');
			ft_putstr(ft_getusr(fstat));
			ft_printsize(ft_itoa(fstat.st_size), e);
			ft_getdate(fstat);
			ft_putchar(' ');
			ft_putstr(e->content[i]);
			ft_putchar('\n');
		}
	closedir(e->dir);
}

void	ft_list(t_env *e)
{
	int		i;

	i = -1;
	ft_getcontent(e);
	ft_ls_sort(e->content);
	while (e->content[++i])
		if (e->content[i][0] != '.')
			ft_putstr(ft_strjoin(e->content[i], "\n"));
}

void	ft_list_all(t_env *e)
{
	int		i;

	i = -1;
	ft_getcontent(e);
	ft_ls_sort(e->content);
	while (e->content[++i])
		ft_putstr(ft_strjoin(e->content[i], "\n"));
}

void	ft_list_rev(t_env *e)
{
	int		i;

	i = ft_strlen_point(e->content);
	while (--i >= 0)
		if (e->content[i][0] != '.')
		{

		}
}
//</			 END				>
