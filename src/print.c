/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:45:41 by wphokomp          #+#    #+#             */
/*   Updated: 2017/11/29 10:05:13 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_print_file_size(t_content *file, int col_size)
{
	if (file->type == 'b' || file->type == 'c')
	{
		ft_putnbr((int)major(file->device));
		ft_putstr(", ");
		ft_putnbr((int)minor(file->device));
	}
	else
	{
		ft_pad(file, col_size, 2);
		ft_putnbr(file->size);
	}
}

void	ft_print_sfiles(t_content *file)
{
	ft_putstr(file->name_);
	ft_putstr("\033[0m");
	ft_putchar('\n');
}

void	ft_print_lfiles(t_content *file, int col_lnk, int col_size)
{
	ft_putchar(file->type);
	ft_putstr(file->permission);
	ft_putchar(' ');
	ft_pad(file, col_lnk, 1);
	ft_putnbr(file->link);
	ft_putchar(' ');
	ft_putstr(file->usr);
	ft_putchar(' ');
	ft_putstr(file->grp);
	ft_putchar(' ');
	ft_print_file_size(file, col_size);
	ft_putchar(' ');
	ft_putstr(file->date);
	ft_putchar(' ');
	ft_putstr(file->name_);
	ft_putchar('\n');
}

void	ft_print_dir(t_content *lead, char *dir_name, t_args *args_)
{
	int		col_lnk;
	int		col_size;

	col_lnk = ft_get_col_len(lead, 1);
	col_size = ft_get_col_len(lead, 2);
	ft_putstr(dir_name);
	ft_putendl(":");
	if (ft_strchr(args_->args, 'l') && lead)
	{
		ft_putstr("total ");
		ft_putnbr(ft_get_size(lead));
		ft_putchar('\n');
	}
	while (lead)
	{
		ft_print_file(lead, args_, col_lnk, col_size);
		lead = lead->next;
	}
}

void	ft_print_file(t_content *file, t_args *args_, int lnk_col, int col_size)
{
	if (ft_strchr(args_->args, 'l'))
		ft_print_lfiles(file, lnk_col, col_size);
	else
		ft_print_sfiles(file);
}
