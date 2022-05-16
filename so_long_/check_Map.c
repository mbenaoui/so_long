/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_Map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:38:24 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/03/29 12:58:28 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chck_map(char **str, char *src)
{
	size_t	j;
	int		y;

	y = 0;
	if (ft_strchr(src, 'P') == 0 || ft_strchr(src, '0') == 0
		||ft_strchr(src, 'C') == 0 || ft_strchr(src, '1') == 0
		||ft_strchr(src, 'E') == 0)
	{
		map_error (6);
		return (1);
	}
	j = ft_strlen(str[0]);
	while (str[y] != '\0')
	{
		if (ft_strlen(str[y]) != j)
		{
			map_error (2);
			return (1);
		}
		y++;
	}
	return (0);
}

int	chack_str(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

int	chck_map1(char **str, char *src)
{
	size_t	i;

	i = chack_str(src);
	if (ft_strlen(str[0]) == i)
	{
		map_error (4);
		return (1);
	}
	if (!str[0] || ft_strchr(str[0], '0') != 0 || ft_strchr(str[0], 'P') != 0
		|| ft_strchr(str[0], 'E') != 0 || ft_strchr(str[0], 'C') != 0)
	{
		map_error (1);
		return (1);
	}
	if (!str[i] || ft_strchr(str[i], '0') != 0 || ft_strchr(str[i], 'P') != 0
		|| ft_strchr(str[i], 'E') != 0 || ft_strchr(str[i], 'C') != 0)
	{
		map_error (1);
		return (1);
	}
	return (0);
}

int	chack_map2(char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == 'P')
			j++;
		if (src[i] != 'P' && src[i] != 'E' && src[i] != '0'
			&& src[i] != '1' && src[i] != 'C' && src[i] != '\n')
		{
			map_error (5);
			return (1);
		}
		if (j > 1)
		{
			map_error (3);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_map3(char **str, char *src)
{
	if (chck_map(str, src) == 1 || chck_map1(str, src) == 1
		|| chack_map2(src) == 1)
		return (1);
	return (0);
}
