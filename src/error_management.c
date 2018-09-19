/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:46:13 by wphokomp          #+#    #+#             */
/*   Updated: 2017/11/28 12:36:10 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_print_err(char *msg, int time)
{
	if (time == 1)
	{
		ft_putstr("ft_ls: ");
		perror(msg);
	}
	else if (time == 2 && errno != 2)
	{
		ft_putstr(msg);
		ft_putendl(":");
		ft_putstr("ft_ls: ");
		perror(msg);
	}
}

void	ft_errmsg(char *msg, int terminate)
{
	perror(msg);
	if (terminate)
		exit(0);
}
