/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 16:34:55 by wphokomp          #+#    #+#             */
/*   Updated: 2017/08/08 14:16:07 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strnew_point(size_t size)
{
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (size + 1));
	ret[size + 1] = 0;
	return (ret);
}
