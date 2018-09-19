/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:46:41 by wphokomp          #+#    #+#             */
/*   Updated: 2017/11/28 12:37:20 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		main(int ac, char **av)
{
	t_args	*args_;

	if (!(args_ = (t_args *)ft_memalloc(sizeof(t_args))))
		return (0);
	args_->auth_args = ft_strdup("Ralrt");
	ft_check_args(ac, av, args_);
	args_->dir_s = ft_sort_by_args(args_->dir_s, args_->args, 1);
	ft_get_content(args_);
	ft_free_args(args_);
	return (0);
}
