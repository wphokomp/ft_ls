/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 09:33:15 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/18 08:20:31 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int x;
	int check;

	x = 0;
	check = n;
	if (check < 0)
		return (s1);
	while (s1[x])
		x++;
	i = 0;
	while (s2[i] && n > 0)
	{
		s1[x] = s2[i];
		i++;
		x++;
		n--;
	}
	s1[x] = '\0';
	return (s1);
}
