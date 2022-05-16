/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:41:26 by mbenaoui          #+#    #+#             */
/*   Updated: 2021/12/02 19:37:15 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_nbr( unsigned int n)
{
	long	x;
	int		len;

	x = n;
	len = 0;
	if (x <= 9)
		len += ft_putchar(x + '0');
	else
	{
		len += ft_unsigned_nbr(x / 10);
		len += ft_unsigned_nbr(x % 10);
	}
	return (len);
}
