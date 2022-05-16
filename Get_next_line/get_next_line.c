/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:29:19 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/03/28 21:57:22 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*printf_ligne(char *s)
{
	int		i;
	char	*b;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	b = malloc(sizeof(char) * (i + 2));
	if (!b)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		b[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		b[i++] = '\n';
	b[i] = '\0';
	return (b);
}

char	*read_s(int fd, char *ru)
{
	char	*str;
	int		i;
	int		buf;

	buf = 1000;
	str = malloc(sizeof(char) * buf + 1);
	if (!str)
		return (NULL);
	i = 1;
	while (i != 0)
	{
		i = read(fd, str, buf);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		ru = ft_strjoin(ru, str);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free (str);
	return (ru);
}

char	*next_ligne(char *s)
{
	char	*d;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
	{
		free (s);
		return (NULL);
	}
	d = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!d)
		return (NULL);
	i++;
	while (s[i])
		d[k++] = s[i++];
	d[k] = '\0';
	free (s);
	return (d);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*dest;
	int			buf;

	buf = 1000;
	if ((fd < 0) || (buf <= 0))
		return (NULL);
	str = read_s(fd, str);
	if (!str)
		return (NULL);
	dest = printf_ligne(str);
	str = next_ligne(str);
	if (dest[0] == '\0')
	{
		free(str);
		free(dest);
		return (NULL);
	}
	return (dest);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
//     int fd;
//     char *line;  
//     fd = open("mm", O_RDWR |  O_CREAT , 0777 );
//     // get_next_line(fd);
//     while (1)
//     {
//         line = get_next_line(fd);
//         if (!line)
//             return (0);
//         printf("%s", line);
//     }
//     return (0);
// }
