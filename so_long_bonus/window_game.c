/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:05:16 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/03/28 21:28:16 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bouns.h"

int	move(int keycode, t_long **ing)
{
	char	*x;

	exit_game((*ing)->read3, *ing, keycode);
	if (keycode == D_KEY || keycode == ESCAPE_KEY || keycode == A_KEY)
		mov_player1((*ing)->read3, ing, keycode);
	if (keycode == S_KEY || keycode == W_KEY)
		mov_player2((*ing)->read3, ing, keycode);
	put_image("img/woodblock.xpm", 50, 0, (*ing));
	x = ft_itoa((*ing)->move);
	mlx_string_put((*ing)->mlx, (*ing)->mlx_win, 70, 0, 0xff00ff, x);
	free (x);
	mlx_string_put((*ing)->mlx, (*ing)->mlx_win, 0, 0, 0xffffff, "mov :");
	return (0);
}

void	window_game(char **str, int i, int j, t_long **ing)
{
	(*ing)->mlx = mlx_init();
	(*ing)->mlx_win = mlx_new_window((*ing)->mlx, i, j, "so_long");
	(*ing)->cont = 0;
	window_map(str, (*ing));
	location_p(str, (*ing));
	(*ing)->read3 = str;
	(*ing)->c = 0;
	(*ing)->move = 0;
	mlx_loop_hook((*ing)->mlx, eniym, ing);
	mlx_hook((*ing)->mlx_win, 2, 1L, move, ing);
	mlx_hook((*ing)->mlx_win, 17, 1L, exit_game2, ing);
	mlx_loop((*ing)->mlx);
}
