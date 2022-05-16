/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   siumo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:44:59 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/03/28 19:41:17 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	location_p(char **read3, t_long *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (read3[i])
	{
		while (read3[i][j])
		{
			if (read3[i][j] == 'P')
			{
				m->ver = i;
				m->hor = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	mov_player1(char **read3, t_long **m, int keycode)
{
	if (keycode == D_KEY && read3[(*m)->ver][(*m)->hor + 1] != '1'
		&& read3[(*m)->ver][(*m)->hor + 1] != 'E')
	{
		if (read3[(*m)->ver][(*m)->hor + 1] == 'C')
			(*m)->c++;
		read3[(*m)->ver][(*m)->hor] = '0';
		put_image("img/vide.xpm", ((*m)->hor) * 50, ((*m)->ver) * 50, *m);
		(*m)->hor++;
		put_image("img/right.xpm", ((*m)->hor) * 50, ((*m)->ver) * 50, *m);
	}
	if (keycode == A_KEY && read3[(*m)->ver][(*m)->hor - 1] != '1'
		&& read3[(*m)->ver][(*m)->hor - 1] != 'E')
	{
		if (read3[(*m)->ver][(*m)->hor -1] == 'C')
			(*m)->c++;
		read3[(*m)->ver][(*m)->hor] = '0';
		put_image("img/vide.xpm", ((*m)->hor) * 50, ((*m)->ver) * 50, *m);
		(*m)->hor--;
		put_image("img/left.xpm", ((*m)->hor) * 50, ((*m)->ver) * 50, *m);
	}
	else if (keycode == ESCAPE_KEY)
		exit (0);
	(*m)->move++;
	ft_printf("The movement :%d\n", (*m)->move);
}

void	mov_player2(char **read3, t_long **m, int keycode)
{
	if (keycode == S_KEY && read3[(*m)->ver + 1][(*m)->hor] != '1'
		&& read3[(*m)->ver + 1][(*m)->hor] != 'E')
	{
		if (read3[(*m)->ver + 1][(*m)->hor] == 'C')
			(*m)->c++;
		read3[(*m)->ver][(*m)->hor] = '0';
		put_image("img/vide.xpm", ((*m)->hor) * 50, ((*m)->ver) * 50, *m);
		(*m)->ver++;
		put_image("img/down.xpm", ((*m)->hor) * 50, ((*m)->ver) * 50, *m);
	}
	else if (keycode == W_KEY && read3[(*m)->ver -1][(*m)->hor] != '1'
			&& read3[(*m)->ver - 1][(*m)->hor] != 'E')
	{
		if (read3[(*m)->ver - 1][(*m)->hor] == 'C')
			(*m)->c++;
		read3[(*m)->ver][(*m)->hor] = '0';
		put_image("img/vide.xpm", ((*m)->hor) * 50, ((*m)->ver) * 50, *m);
		(*m)->ver--;
		put_image("img/up.xpm", ((*m)->hor) * 50, ((*m)->ver) * 50, *m);
	}
	(*m)->move++;
	ft_printf("The movement :%d\n", (*m)->move);
}

void	exit_game(char **read3, t_long *m, int keycode)
{
	if (m->c == m->cont)
	{
		if ((keycode == S_KEY && read3[m->ver + 1][m->hor] == 'E')
			|| (keycode == W_KEY && read3[m->ver - 1][m->hor] == 'E')
			|| (keycode == D_KEY && read3[m->ver][m->hor + 1] == 'E')
			|| (keycode == A_KEY && read3[m->ver][m->hor - 1] == 'E'))
		{
			free (m->read2);
			exit (0);
		}
	}
}
