/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:55:17 by tvitoux           #+#    #+#             */
/*   Updated: 2013/11/27 14:13:14 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *ptr;
	unsigned int i;
	unsigned int j;

	i = 0;
	j = ft_strlen(s1) + ft_strlen(s2);
	ptr = ft_strnew(j + 1);
	while (i < j)
	{
		if (i < ft_strlen(s1))
			ptr[i] = s1[i];
		else
		{
			ptr[i] = *s2;
			s2++;
		}
		i++;
	}
		ptr[i] = '\0';
		return (ptr);
}
