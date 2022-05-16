/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:22:23 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/03/28 20:05:56 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SO_LONG_H
# define SO_LONG_H
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include "../Get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define ESCAPE_KEY 53

typedef struct so_long{
	void	*mlx;
	void	*mlx_win;
	char	*read2;
	char	**read3;
	int		ver;
	int		hor;
	int		c;
	int		nomr_c;
	int		move;
	int		cont;
}t_long;

char	**ft_split(char *s, char c);
char	*ft_strjoin(char *path, char *bin);
int		ft_strichr(char *s, char c);
char	*ft_strdup(char *s1);
int		map_error(int t);
int		check_map3(char **str, char *src);
void	window_game(char **str, int i, int j, t_long **ing);
int		chack_str(char *str);
void	put_image(char *b, int l, int k, t_long *ing );
void	window_map(char **m, t_long *ing);
void	mov_player1(char **read3, t_long **m, int keycode);
void	location_p(char **read3, t_long *m);
void	read_map(int fd);
void	mov_player2(char **read3, t_long **m, int keycode);
void	exit_game(char **read3, t_long *m, int keycode);
int		check_nome_map(char *str);
int		exit_game2(int keycode, t_long *s);
#endif
