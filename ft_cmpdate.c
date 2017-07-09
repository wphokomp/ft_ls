/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmpdate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:46:38 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/09 13:48:08 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_comp_time(t_dir d1, t_dir d2)
{
	if (d1->time < d2->time)
		return (1);
	else
		return (0);
}

int		ft_com_str(t_dir s1, t_dir s2)
{
	return (ft_strcmp(s1.dir, s2.dir));
}
