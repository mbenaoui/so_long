/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:10:54 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/03/28 14:39:37 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(char *s1, char *s2)
{
	size_t			i;
	unsigned char	*m;
	unsigned char	*b;

	i = 0;
	m = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (m[i] && b[i] && m[i] == b[i])
		i++;
	return (m[i] - b[i]);
}
