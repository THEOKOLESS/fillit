/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:45:48 by tvitoux           #+#    #+#             */
/*   Updated: 2013/11/29 19:24:47 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] && n)
	{
		if (s1[i] == s2[j])
			j++;
		i++;
		n--;
	}
	if (i == j)
		return (1);
	return (0);
}
