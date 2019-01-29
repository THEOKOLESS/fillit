/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:00:23 by tvitoux           #+#    #+#             */
/*   Updated: 2013/11/26 21:23:24 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *ss1;
	const unsigned char *ss2;

	ss1 = s1;
	ss2 = s2;
	while (n != 0)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
	ss1++;
	ss2++;
	n--;
	}
	return (0);
}
