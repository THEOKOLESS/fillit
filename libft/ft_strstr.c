/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:59:04 by tvitoux           #+#    #+#             */
/*   Updated: 2013/11/26 21:22:55 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	char *b;

	i = -1;
	j = 0;
	b = (char *)s1;
	while (s1[++i] && s2[j])
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
	if (s2[j] == '\0')
		return (b);
	return (NULL);
}
