/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nome_MAP.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:01:51 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/03/28 21:51:43 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bouns.h"

int	check_nome_map(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str);
	if (str[j - 1] == 'r')
		if (str[j - 2] == 'e')
			if (str[j - 3] == 'b')
				if (str[j - 4] == '.')
					return (1);
	return (0);
}
