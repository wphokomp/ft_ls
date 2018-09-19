/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:46:37 by wphokomp          #+#    #+#             */
/*   Updated: 2017/11/29 10:05:35 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_content	*ft_sort_by_name(t_content *lead)
{
	t_content	*ptr;
	t_content	*prev;
	t_content	*tmp;

	ptr = lead;
	prev = ptr;
	while (ptr->next)
	{
		if (ft_strcmp(ptr->name_, (ptr->next)->name_) > 0)
		{
			lead = (ptr == lead) ? ptr->next : lead;
			prev->next = ptr->next;
			tmp = (ptr->next)->next;
			(ptr->next)->next = ptr;
			ptr->next = tmp;
			ptr = lead;
			prev = ptr;
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
	}
	return (lead);
}

t_content	*ft_sort_by_time(t_content *lead)
{
	t_content	*ptr;
	t_content	*prev;
	t_content	*tmp;

	ptr = lead;
	prev = ptr;
	while (ptr->next)
	{
		if (ptr->timestamp < (ptr->next)->timestamp)
		{
			lead = (ptr == lead) ? ptr->next : lead;
			prev->next = ptr->next;
			tmp = (ptr->next)->next;
			(ptr->next)->next = ptr;
			ptr->next = tmp;
			ptr = lead;
			prev = ptr;
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
	}
	return (lead);
}

t_content	*ft_rev_lst(t_content *lead)
{
	t_content	*ptr;
	t_content	*prev;
	t_content	*tmp;

	ptr = lead->next;
	prev = lead;
	while (lead->next)
		lead = lead->next;
	prev->next = NULL;
	while (ptr)
	{
		tmp = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = tmp;
	}
	return (lead);
}

t_content	*ft_sort_by_args(t_content *lead, char *args, char name_)
{
	if (lead)
	{
		if (name_)
			lead = ft_sort_by_name(lead);
		if (ft_strchr(args, 'r'))
			lead = ft_rev_lst(lead);
		if (ft_strchr(args, 't'))
			lead = ft_sort_by_time(lead);
	}
	return (lead);
}
