/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:13:30 by wphokomp          #+#    #+#             */
/*   Updated: 2017/11/29 10:13:13 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_content	*ft_get_detail(char *name_, char valid)
{
	struct stat	buff;
	t_content	*file;

	file = (t_content *)ft_memalloc(sizeof(t_content));
	if (lstat(name_, &buff) == -1)
		return (NULL);
	if (valid)
	{
		if (stat(name_, &buff) == -1)
			return (NULL);
	}
	file->device = buff.st_rdev;
	file->name_ = ft_strdup(name_);
	file->type = ft_filetype(buff.st_mode);
	file->permission = ft_permissions(buff.st_mode);
	file->link = buff.st_nlink;
	file->usr = ft_get_usr(buff);
	file->grp = ft_get_grp(buff);
	file->size = buff.st_size;
	file->blocks = buff.st_blocks;
	file->date = ft_get_date(buff);
	file->timestamp = buff.st_mtimespec.tv_sec;
	file->next = NULL;
	return (file);
}

int			ft_read_dir(t_content *curr_dir, t_args *args_, t_content **lead
			, t_content **rec)
{
	DIR				*dirp;
	struct dirent	*dir;
	char			*name;
	t_content		*tmp;

	if (!(dirp = opendir(curr_dir->name_)))
		return (0);
	while ((dir = readdir(dirp)))
	{
		if (!ft_strchr(args_->args, 'a') && dir->d_name[0] == '.')
			continue ;
		name = ft_strjoin_nolim(0, curr_dir->name_
				, "/", dir->d_name, NULL);
		if (!(tmp = ft_get_detail(name, 0)))
			return (0);
		if (ft_strchr(args_->args, 'R') && tmp->type == 'd' &&
			ft_strcmp(dir->d_name, ".") && ft_strcmp(dir->d_name, ".."))
			ft_lst_add(rec, ft_cpylnk(tmp));
		tmp->name_ = ft_strdup(dir->d_name);
		tmp->parent_dir = ft_strdup(curr_dir->name_);
		ft_lst_add(lead, tmp);
		ft_memdel((void **)&name);
	}
	closedir(dirp);
	return (1);
}

void		ft_get_content(t_args *args)
{
	t_content	*file_lst;
	t_content	*rec;
	t_content	*curr_dir;

	curr_dir = args->dir_s;
	while (curr_dir)
	{
		file_lst = NULL;
		rec = NULL;
		if (ft_read_dir(curr_dir, args, &file_lst, &rec))
		{
			file_lst = ft_sort_by_args(file_lst, args->args, 1);
			ft_print_dir(file_lst, (curr_dir)->name_, args);
		}
		else
			ft_print_err((curr_dir)->name_, 2);
		ft_free_lst(file_lst);
		if (rec)
		{
			rec = ft_sort_by_args(rec, args->args, 1);
			ft_addto_lst(curr_dir, rec);
		}
		if ((curr_dir = curr_dir->next))
			ft_putchar('\n');
	}
}
