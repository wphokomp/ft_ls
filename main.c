/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:53:27 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/09 15:28:32 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free_var(t_dir *list, t_env *temp)
{
	t_dir	*tmp;
	t_dir	*tofree;

	tmp = list;
	while (temp != NULL)
	{
		free(tmp->full);
		tmp->full = NULL;
		tofree = tmp;
		tmp = tmp->next;
		free(tofree);
		tofree = NULL;
	}
	(void)temp;
}

void	ft_init(t_env *e)
{
	e->l = 0;
	e->r = 0;
	e->a = 0;
	e->rev = 0;
	e->t = 0;
}

int		ft_add_arg(t_env *e, char *arg)
{
	int		x;

	x = 1;
	ft_init(e);
	while (arg[x] != '\0')
	{
		if (arg[x] == 'l')
			e->l = 1;
		else if (arg[x] == 'a')
			e->a = 1;
		else if (arg[x] == 'r')
			e->r = 1;
		else if (arg[x] == 'r')
			e->t = 1;
		else if (arg[x] == 'R')
			e->rev = 1;
		else
		{
			ft_putstr("Invalid argument");
			return (0);
		}
		x++;
	}
	return (1);
}

void	ft_sort_lst(t_dir **head, int (*cmp)(t_dir, t_dir), int done)
{
	t_dir	**src;
	t_dir	*temp;
	t_dir	*next;

	while (!done && *head != NULL && (*head)->next != NULL)
	{
		src = head;
		temp = *head;
		next = (*head)->next;
		done = 1;
		while (next)
		{
			if (cmp(*temp, *next) > 0)
			{
				temp->next = next->next;
				next->next = temp;
				*src = next;
				done = 0;
			}
			src = &temp->next;
			temp = next;
		}
	}
}

int		main(int argc, char **argv)
{
	int		i;
	t_env	e;
	t_dir	*temp;

	i = 1;
	e.list = NULL;
	while (i < argc)
	{
		if (argv[i][0] != '-' && (temp = (t_dir *)malloc(sizeof(t_dir))))
		{
			temp->dir = argv[i];
			temp->next = e.list;
			e.list = temp;
		}
		else if (ft_add_arg(&e, argv[i]) == 0)
			return (0);
		i++;
	}
	e.list == NULL ? ft_do_lst(&e) : ft_sort_lst(&e.list, ft_cmpstr, 0);
	ft_ls(&e);
	free(e.list);
	e.list = NULL;
	return (0);
}
