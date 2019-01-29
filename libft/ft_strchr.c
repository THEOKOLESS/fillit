/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:00:51 by tvitoux           #+#    #+#             */
/*   Updated: 2013/11/23 21:22:03 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	const char *ret;

	ret = s;
	while (*ret != (char) c)
	{
		if (*ret == 0)
			return (NULL);
		ret ++;
	}
	return ((char *) ret);
}
