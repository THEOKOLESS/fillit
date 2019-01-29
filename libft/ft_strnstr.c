/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:09:55 by tvitoux           #+#    #+#             */
/*   Updated: 2013/11/27 12:53:38 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	char *b;

	i = -1;
	j = 0;
	b = (char *)s1;
	while (s1[++i] && s2[j] && n > i)
	{
		if (s1[i] == s2[j] && j == 0)
		{
			b = (char *)&s1[i];
			j++;
		}
		else if (s1[i] == s2[j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
	}
	if (!s2[j])
		return (b);
	return (NULL);
}
