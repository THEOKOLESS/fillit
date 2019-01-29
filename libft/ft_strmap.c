/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:40:47 by tvitoux           #+#    #+#             */
/*   Updated: 2013/11/26 17:23:18 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	int 	i;

	i = 0;
	map = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		map[i] = f(s[i]);
		i++;
	}
	return (map);
}
