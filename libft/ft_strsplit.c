/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 19:01:06 by tvitoux           #+#    #+#             */
/*   Updated: 2013/11/29 19:22:29 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char **ft_masplit(const char *s, char c)
{
	unsigned int i;
	unsigned int nb_word;
	char **ret;

	i = 0;
		if (s[i] != c)
		nb_word = 1;
	else
		nb_word = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			nb_word++;
		i++;
	}
	ret = (char **)ft_memalloc(sizeof(char *) * (nb_word + 1));
	return (ret);
}

static char **ft_ret(char const *s, char c)
{
	unsigned int i;
	unsigned int j;
	char **ret;
	size_t len;

	i = 0;
	j = 0;
	len = 0;
	ret = NULL;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i + len] != c)
			len++;
		else if (s[i + len] == c)
		{
			ret[j] = ft_strsub(s, i, len);
			j++;
			i = i + len;
			len = 0;
		}
	}
	*ret[j] = '\0';
	return (ret);
}

char **ft_strsplit(char const *s, char c)
{
	unsigned int i;
	char **ret;
	unsigned int j;

	ret = ft_masplit(s, c);
	i = 0;
	j = 0;
	while (s[i] != c)
	{
		if (!s[i])
		{
			ret[j] = ft_strsub(s, j, ft_strlen(s));
			return (ret);
		}
		else
			i++;
	}
	if (ret)
	{
		ret = ft_ret(s, c);
		return (ret);
	}
	return (NULL);
}

