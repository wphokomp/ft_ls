/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:48:47 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/09 15:28:47 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ls.h"

void	ft_do_lst(t_env *e)
{
	e->list = (t_dir *)malloc(sizeof(t_dir));
	e->list->dir = ".";
	e->list->next = NULL;
}

char	*ft_get_user(struct stat fstat)
{
	char			*str;
	struct passwd	*pw;
	struct group	*gr;

	pw = getpwuid(fstat.st_uid);
	gr = getgrgid(fstat.st_gid);
	str = ft_strjoin(ft_strjoin(pw->pw_name, "  "), gr->gr_name);
	return (ft_strjoin(str, "  "));
}

void	ft_permissions(t_dir *temp, struct stat fstat)
{
	if (temp->is_dir)
		ft_putchar('d');
	else
		ft_putchar((S_ISLNK(fstat.st_mode)) ? 'l' : '-');
	ft_putchar((fstat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((fstat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((fstat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putchar(' ');
}

void	ft_get_time(struct stat fstat, t_dir *temp)
{
	char	buff[13];
	char	*str;
	char	buf[64];
	size_t	len;

	str = ctime(&temp->time);
	ft_memcpy(buff, &str[4], 12);
	buff[12] = '\0';
	ft_putstr(buff);
	ft_putstr("  ");
	ft_putstr(temp->dir);
	if (S_ISLNK(fstat.st_mode))
	{
		ft_putstr("->");
		len = readlink(temp->full, buf, 64);
		buf[len] = '\0';
		ft_putstr(buf);
	}
}

void	ft_print_lst(t_dir *list)
{
	t_dir		*temp;
	struct stat fstat;

	temp = list;
	while (temp != NULL)
	{
		lstat(temp->full, &fstat);
		ft_putchar('\n');
		ft_permissions(temp, fstat);
		ft_putnbr(fstat.st_nlink);
		ft_putstr(" ");
		ft_putstr(ft_get_user(fstat));
		ft_putstr(ft_strjoin(ft_itoa(fstat.st_size), " "));
		ft_get_time(fstat, temp);
		temp = temp->next;
	}
}
