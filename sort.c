/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:03:32 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/09 14:39:34 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_cmptime(t_dir d1, t_dir d2)
{
	if (d1.time < d2.time)
		return (1);
	else
		return (0);
}

int		ft_cmpstr(t_dir s1, t_dir s2)
{
	return (ft_strcmp(s1.dir, s2.dir));
}

int		ft_get_path(char *dir, char *name, t_dir *temp)
{
	char	*path;
	char	*full;

	path = ft_strjoin(dir, "/");
	full = ft_strjoin(path, name);
	temp->full = strdup(full);
	free(full);
	free(path);
	full = NULL;
	path = NULL;
	return (1);
}

int		ft_free_lst(t_dir *list)
{
	t_dir	*temp;
	t_dir	*tofree;

	temp = list;
	while (temp != NULL)
	{
		free(temp->dir);
		free(temp->full);
		temp->dir = NULL;
		temp->full = NULL;
		tofree = temp;
		temp = temp->next;
		free(tofree);
		tofree = NULL;
	}
	return (1);
}
