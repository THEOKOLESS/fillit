/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:57:20 by tvitoux           #+#    #+#             */
/*   Updated: 2013/11/29 19:31:06 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int i;
	char *tron;
	unsigned int	j;

	j = 0;
	i = start;
	tron = (char *)ft_memalloc(sizeof(char *) * (len + 1));
	while (j < len)
	{
		tron[j] = s[i];
		j++;
		i++;
	}
	return (tron);
}
