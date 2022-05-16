/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:26:33 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/03/28 21:49:53 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bouns.h"

void	put_image(char *b, int l, int k, t_long *ing)
{
	void	*im;
	int		z;
	int		e;

	z = 0;
	e = 0;
	im = mlx_xpm_file_to_image(ing->mlx, b, &z, &e);
	mlx_put_image_to_window(ing->mlx, ing->mlx_win, im, l, k);
}
