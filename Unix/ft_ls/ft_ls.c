/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 11:20:43 by wphokomp          #+#    #+#             */
/*   Updated: 2017/08/13 12:16:37 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_flag(char c, t_env e)
{
	struct stat	fstat;

	if (c == 'l')
		ft_l(fstat, &e);
	else if (c == 'a')
		ft_list_all(&e);
	exit(1);
}

char	**ft_input(char **av)
{
	size_t	len;
	int		i;
	char	**ret;

	i = -1;
	len = ft_strlen_point(av);
	ret = ft_strnew_point(len - 1);
	ret[len - 1] = 0;
	while (av[++i + 1])
	{
		ret[i] = ft_strnew(ft_strlen(av[i + 1]));
		ret[i] = av[i + 1];
	}
	return (ret);
}

int		main(int ac, char **av)
{
	t_env	e;
	int		i;
	int		h;
	char	**path;
	char	**flags;
	struct stat	fstat;

	e.path = NULL;
	i = -1;
	if (ac > 1)
	{
		//e.path = ".";
		flags = ft_input(av);
		while (flags[++i])
			ft_putstr(ft_strjoin(flags[i] ,"\n"));
	}
	else
	{
		e.path = ".";
		ft_list(&e);
	}
	return (0);
}
