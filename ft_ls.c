/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:41:41 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/09 15:16:57 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir	*ft_rev_lst(t_dir *head)
{
	t_dir	*list;
	t_dir	*next;

	list = NULL;
	while (head)
	{
		next = head->next;
		head->next = list;
		list = head;
		head = next;
	}
	free(next);
	return (list);
}

void	ft_cap_r(t_dir *list, t_env *e)
{
	t_dir	*temp;

	temp = list;
	while (temp != NULL)
	{
		if (temp->is_dir == 1 && temp->dir[0] != '.')
			ft_do_ls(temp->full, e);
		temp = temp->next;
	}
}

void	ft_print_ls(t_dir *list, t_env *e, char *path)
{
	t_dir	*temp;
	char	*new;

	if (e->t == 1)
		ft_sort_lst(&list, ft_cmptime, 0);
	if (e->r == 1)
		list = ft_rev_lst(list);
	new = ft_strjoin(path, "/");
	ft_putstr(new);
	free(new);
	if (e->l == 1)
		ft_print_lst(list);
	else
	{
		temp = list;
		while (temp != NULL)
		{
			ft_putchar('\n');
			ft_putstr(temp->dir);
			temp = temp->next;
		}
	}
	ft_putchar('\n');
	if (e->rev == 1)
		ft_cap_r(list, e);
}

void	ft_do_ls(char *dir, t_env *e)
{
	t_dir	*list;
	t_dir	*temp;

	list = NULL;
	if ((e->dirp = opendir(dir)) != NULL)
	{
		while ((e->dp = readdir(e->dirp)) != NULL)
		{
			if (e->dp->d_name[0] != '.' || e->a == 1)
			{
				temp = (t_dir *)malloc(sizeof(t_dir));
				temp->dir = ft_strdup(e->dp->d_name);
				ft_get_path(dir, e->dp->d_name, temp);
				lstat(temp->full, &e->sb);
				temp->time = e->sb.st_mtime;
				if (S_ISDIR(e->sb.st_mode) == 1)
					temp->is_dir = 1;
				temp->next = list;
				list = temp;
			}
		}
		closedir(e->dirp);
		ft_print_ls(list, e, dir);
		ft_free_lst(list);
	}
}

void	ft_ls(t_env *e)
{
	t_dir	*temp;

	temp = e->list;
	while (temp != NULL)
	{
		ft_do_ls(temp->dir, e);
		temp = temp->next;
	}
}
