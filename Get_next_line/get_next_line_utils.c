/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:01:59 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/03/21 20:03:36 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	char	*c;
	int		n;
	int		i;

	n = 0 ;
	while (s1[n])
		n++;
	c = malloc(sizeof(char) * (n + 1));
	if (!c)
		return (NULL);
	i = 0;
	while (i < n)
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

size_t	ft_strlen( char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		m;
	int		len;
	int		len1;
	char	*s4;

	i = 0;
	m = 0;
	if (!s1)
		s1 = ft_strdup("");
	len = ft_strlen(s1);
	len1 = ft_strlen(s2);
	s4 = (char *)malloc(sizeof (char) * (len + len1 + 1));
	if (s4 == NULL)
		return (NULL);
	while (i < len)
		s4[m++] = s1[i++];
	i = 0;
	while (i < len1)
		s4[m++] = s2[i++];
	s4[m] = '\0';
	free (s1);
	return (s4);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
