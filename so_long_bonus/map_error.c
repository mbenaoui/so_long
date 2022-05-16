/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:07:34 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/03/28 20:32:31 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bouns.h"

int	map_error(int t)
{
	if (t == 1)
		write(2, "The map is not protected", 25);
	if (t == 2)
		write(2, "The map is not equal", 20);
	if (t == 3)
		write(2, "The map must contain only one game", 34);
	if (t == 4)
		write(2, "The map must be rectangular", 27);
	if (t == 5)
		write(2, "Map with caracter no !", 22);
	if (t == 6)
		write(2, "The Map is incomplete", 21);
	return (0);
}
