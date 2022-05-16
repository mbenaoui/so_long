/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:00:59 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/03/28 21:48:18 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bouns.h"

int	ft_strcmp(char *s1, char *s2)
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

char	*cole(char m)
{
	char	*str;

	if (m == 'E')
		str = "img/port.xpm";
	if (m == '1')
		str = "img/woodblock.xpm";
	if (m == 'C')
		str = "img/coin.xpm";
	if (m == '0')
		str = "img/vide.xpm";
	if (m == 'P')
		str = "img/down.xpm";
	if (m == 'X')
		str = "img/enemy3.xpm";
	return (str);
}

void	window_map(char **m, t_long *ing)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (m[++i])
	{
		while (m[i][++j])
		{
			if (ft_strcmp(cole(m[i][j]), "img/coin.xpm") == 0)
			{
				put_image("img/vide.xpm", j * 50, i * 50, ing);
				put_image(cole(m[i][j]), j * 50, i * 50, ing);
				ing->cont++;
			}
			else if (ft_strcmp(cole(m[i][j]), "img/enemy3.xpm") == 0)
			{
				put_image("img/vide.xpm", j * 50, i * 50, ing);
				put_image(cole(m[i][j]), j * 50, i * 50, ing);
			}
			else
				put_image(cole(m[i][j]), j * 50, i * 50, ing);
		}
		j = -1;
	}
}
