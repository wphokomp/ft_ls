/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:46:56 by wphokomp          #+#    #+#             */
/*   Updated: 2017/11/29 10:00:03 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_free_one(t_content *lead)
{
	if (lead)
	{
		if (lead->permission)
			ft_memdel((void **)&lead->permission);
		if (lead->date)
			ft_memdel((void **)&lead->date);
		if (lead->name_)
			ft_memdel((void **)&lead->name_);
		if (lead->parent_dir)
			ft_memdel((void **)&lead->parent_dir);
		ft_memdel((void **)&lead);
	}
}

void	ft_free_lst(t_content *lead)
{
	t_content	*nxt;

	while (lead)
	{
		nxt = lead->next;
		ft_free_one(lead);
		lead = nxt;
	}
}

void	ft_free_flst(t_content *lead)
{
	t_content	*tmp;

	while (lead)
	{
		if (lead->name_)
			ft_memdel((void **)&lead->name_);
		if (lead->parent_dir)
			ft_memdel((void **)&lead->parent_dir);
		tmp = lead;
		lead = lead->next;
		ft_memdel((void **)&tmp);
	}
}

void	ft_free_args(t_args *args_)
{
	ft_memdel((void **)&args_->auth_args);
	ft_memdel((void **)&args_->auth_args);
	ft_free_flst(args_->dir_s);
	ft_memdel((void **)&args_);
}
