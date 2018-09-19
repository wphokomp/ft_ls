/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:06:53 by wphokomp          #+#    #+#             */
/*   Updated: 2017/11/29 10:07:14 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static int	ft_valid(char *arg, t_args *args_)
{
	while (*arg)
	{
		if (!ft_strchr(args_->auth_args, *arg) || !ft_isalnum(*arg))
		{
			ft_putstr("ft_ls: illegal options -- ");
			ft_putchar(*arg);
			ft_putchar('\n');
			ft_putstr("usage: ft_ls [-");
			ft_putstr(args_->auth_args);
			ft_putendl("] [file ...]");
			exit(0);
		}
		arg++;
	}
	return (1);
}

static int	ft_req_dir(char *dir_name, t_args *args_)
{
	t_content	*new_dir;

	if (!(new_dir = ft_get_detail(dir_name, 0)))
		return (0);
	if (new_dir->type != 'd')
	{
		if (new_dir->type == 'l' && !ft_strchr(args_->args, 'l'))
		{
			if (!(new_dir = ft_get_detail(dir_name, 1)))
				return (0);
		}
		else
		{
			ft_print_file(new_dir, args_, 0, 0);
			return (1);
		}
	}
	ft_lst_add(&(args_->dir_s), new_dir);
	return (1);
}

void		ft_check_args(int ac, char **av, t_args *args)
{
	int		i;
	char	*args_;

	i = 0;
	args_ = ft_strnew(2);
	while (++i < ac && av[i][0] == '-' && ft_valid(&av[i][1], args))
	{
		args_ = ft_mem_realloc(args_,
				ft_strlen(args_) + ft_strlen(av[i]));
		args_ = ft_strcat(args_, &av[i][1]);
	}
	args->args = ft_strdup(args_);
	ft_memdel((void **)&args_);
	if (i == ac)
		ft_req_dir(".", args);
	while (i < ac)
	{
		if (!ft_req_dir(av[i], args))
			ft_print_err(av[i], 1);
		i++;
	}
}
