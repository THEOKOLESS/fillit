/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:12:32 by tvitoux           #+#    #+#             */
/*   Updated: 2013/11/26 17:17:22 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
	char *map;
	int i;

	i = 0;
	map = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		map[i] = f(i, s[i]);
		i++;
	}
	return (map);
}
