/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:13:28 by tvitoux           #+#    #+#             */
/*   Updated: 2013/11/28 13:05:56 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s)
{
	char *ret;
	unsigned int len;
	unsigned int st;
	unsigned int i;

	st = 0;
	i = ft_strlen(s);
	if (s[st])
	{
		while ((s[st] == ' ' || s[st] == '\n' || s[st] == '\t') && s[st])
			st++;
		if (!s[i])
			i--;
		while ((s[i] < '!' || s[i] > '~') && i)
			i--;
		if (i > st)
		{
			len = i - st;
			ret = ft_strsub(s, st, len + 1);
			return (ret);
		}
	}
	return (NULL);
}
