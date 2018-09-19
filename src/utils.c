/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:45:56 by wphokomp          #+#    #+#             */
/*   Updated: 2017/11/29 10:05:55 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		ft_get_col_len(t_content *lead, char field)
{
	t_content	*ptr;
	int			l;
	int			tmp;

	ptr = lead;
	l = 0;
	while (ptr)
	{
		if (field == 1)
			tmp = ptr->link;
		else if (field == 2)
			tmp = ptr->size;
		if ((tmp = ft_strlen(ft_itoa(tmp))) > l)
			l = tmp;
		ptr = ptr->next;
	}
	return (l);
}

void	ft_pad(t_content *file, int size, char field)
{
	int		tmp;

	if (field == 1)
		tmp = ft_strlen(ft_itoa(file->link));
	else
		tmp = ft_strlen(ft_itoa(file->size));
	while (tmp < size)
	{
		ft_putchar(' ');
		tmp++;
	}
}

int		ft_get_size(t_content *lead)
{
	t_content	*ptr;
	int			res;

	ptr = lead;
	res = 0;
	while (ptr)
	{
		res += ptr->blocks;
		ptr = ptr->next;
	}
	return (res);
}
