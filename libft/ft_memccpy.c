/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:59:53 by tvitoux           #+#    #+#             */
/*   Updated: 2013/11/26 10:16:08 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char *dest;
	const char *src;

	dest = s1;
	src = s2;
	if (n != 0)
	{
		while (n > 0 && *src != (unsigned char) c)
		{
			*dest++ = *src++;
			n--;
		}
		if (*src == (unsigned char) c)
		{
			*dest++ = *src;
			return (dest);
		}
	}
	return (NULL);
}
