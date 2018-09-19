/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:17:09 by wphokomp          #+#    #+#             */
/*   Updated: 2017/11/29 10:13:00 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		ft_lst_add(t_content **lead, t_content *nxt)
{
	t_content	*tmp;

	if (!(*lead))
		*lead = nxt;
	else
	{
		tmp = *lead;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = nxt;
	}
}

void		ft_lst_insert(t_content *target, char *nxt)
{
	t_content	*nxt_dir;

	nxt_dir = (t_content *)ft_memalloc(sizeof(t_content));
	nxt_dir->name_ = ft_strdup(nxt);
	nxt_dir->next = target->next;
	target->next = nxt_dir;
}

t_content	*ft_cpylnk(t_content *lnk)
{
	t_content	*cpy;

	cpy = (t_content *)ft_memalloc(sizeof(t_content));
	cpy = (t_content *)ft_memcpy(cpy, lnk, sizeof(t_content));
	return (cpy);
}

void		ft_addto_lst(t_content *target, t_content *nxt)
{
	t_content	*tmp;

	tmp = target->next;
	target->next = nxt;
	while (nxt->next)
		nxt = nxt->next;
	nxt->next = tmp;
}
