/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:49:21 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/03/25 18:15:44 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bouns.h"

int	simo(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (*str)
	{
		if (*str != c && j == 1)
		{
			j = 0;
			i++;
		}
		else if (*str == c && j == 0)
			j = 1;
		str++;
	}
	return (i);
}

char	*badr(const char *str, size_t n, size_t len)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc((len - n + 1) * (sizeof(char)));
	while (n < len)
	{
		s[i] = str[n];
		i++;
		n++;
	}
	s[i] = '\0';
	return (s);
}

char	**ft_split(char *s, char c)
{
	size_t		m;
	size_t		j;
	int			n;
	char		**src;

	m = -1;
	j = 0;
	n = -1;
	if (!s)
		return (0);
	src = malloc((simo(s, c) + 1) * sizeof(char *));
	if (!src)
		return (NULL);
	while (++m <= ft_strlen(s))
	{
		if (s[m] != c && n < 0)
			n = m;
		else if ((s[m] == c || m == ft_strlen(s)) && n >= 0)
		{
			src[j++] = badr(s, n, m);
			n = -1;
		}
	}
	src[j] = 0;
	return (src);
}
