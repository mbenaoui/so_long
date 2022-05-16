/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:23:58 by mbenaoui          #+#    #+#             */
/*   Updated: 2021/12/02 19:37:11 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	x;
	int		len;

	x = n;
	len = 0;
	if (x < 0)
	{
		len += ft_putchar('-');
		x = -x;
	}
	if (x <= 9)
		len += ft_putchar(x + '0');
	else
	{
		len += ft_putnbr(x / 10);
		len += ft_putnbr(x % 10);
	}
	return (len);
}
