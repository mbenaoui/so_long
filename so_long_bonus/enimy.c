/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enimy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:15:21 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/03/28 21:55:06 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bouns.h"

void	location_x(char **read3, t_long *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (read3[i])
	{
		while (read3[i][j])
		{
			if (read3[i][j] == 'X')
			{
				m->ver_x = i;
				m->hor_x = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_image_enym(t_long **m)
{
	static int	bool;

	location_x((*m)->read3, *m);
	(*m)->read3[(*m)->ver_x][(*m)->hor_x] = '0';
	if (((*m)->ver_x == (*m)->ver) && ((*m)->hor_x == (*m)->hor))
		exit (0);
	put_image("img/vide.xpm", ((*m)->hor_x) * 50, ((*m)->ver_x) * 50, *m);
	if (!bool && (*m)->read3[(*m)->ver_x][(*m)->hor_x - 1] != '1'
		&& (*m)->read3[(*m)->ver_x][(*m)->hor_x - 1] != 'E'
		&& (*m)->read3[(*m)->ver_x][(*m)->hor_x - 1] != 'C')
	{
		(*m)->hor_x--;
		bool = 0;
	}
	else if ((*m)->read3[(*m)->ver_x][(*m)->hor_x + 1] != '1'
			&& (*m)->read3[(*m)->ver_x][(*m)->hor_x + 1] != 'E'
			&& (*m)->read3[(*m)->ver_x][(*m)->hor_x + 1] != 'C')
	{
		(*m)->hor_x++;
		bool = 1;
	}
	else
		bool = 0;
	usleep(100000);
	put_image("img/enemy3.xpm", ((*m)->hor_x) * 50, ((*m)->ver_x) * 50, *m);
}

int	eniym(t_long **m)
{
	ft_image_enym(m);
	return (0);
}
