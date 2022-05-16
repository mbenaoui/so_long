/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:13:28 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/03/29 12:54:52 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(int fd)
{
	t_long	*ing;
	char	*read1;
	char	**read3;

	ing = malloc(sizeof(t_long));
	ing->read2 = ft_strdup("");
	while (1)
	{
		read1 = get_next_line(fd);
		if (!read1)
			break ;
		if (read1[0] != '1' || read1[ft_strlen(read1) - 2] != '1')
		{
			map_error (1);
			return ;
		}
		ing->read2 = ft_strjoin(ing->read2, read1);
		free (read1);
	}
	read3 = ft_split(ing->read2, '\n');
	if (check_map3(read3, ing->read2) == 1)
		return ;
	window_game(read3, ft_strlen(read3[0]) * 50,
		(chack_str(ing->read2) + 1) * 50, &ing);
}

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc > 2 || argc < 2)
	{
		write(2, "eroor :", 7);
		return (0);
	}
	if (check_nome_map(argv[1]) == 0)
	{
		write(2, "eroor :", 7);
		return (0);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(2, "eroor :", 7);
			return (0);
		}
	}
	read_map(fd);
}
