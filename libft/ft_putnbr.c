/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvitoux <tvitoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:56:18 by tvitoux           #+#    #+#             */
/*   Updated: 2013/11/20 15:56:19 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nbr)
{
	int display;

	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	display = nbr % 10;
	nbr = nbr / 10;
	if (nbr > 0)
		ft_putnbr(nbr);
	ft_putchar(display + '0');
}

