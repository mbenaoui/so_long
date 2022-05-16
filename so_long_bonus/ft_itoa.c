/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:03:53 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/03/28 15:08:36 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bouns.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_convert(char *p, int n, int lenp)
{
	int	k;

	k = 0;
	if (n < 0)
	{
		p[0] = '-';
		k++;
		n = n * -1;
	}
	while (n != 0)
	{
		p[lenp - 1] = (n % 10) + 48;
		n = n / 10;
		k++;
		lenp--;
	}
	p[k] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	int		i;
	int		k;
	char	*p;

	k = 0;
	if (n == -2147483648)
		return ("-2147483648");
	if (n == 0)
		return ("0");
	i = ft_intlen(n);
	p = (char *) malloc(sizeof(char) * (i + 1));
	if (!p)
		return (0);
	return (ft_convert(p, n, i));
}
