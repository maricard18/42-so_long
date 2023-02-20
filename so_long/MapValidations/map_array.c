/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:45:34 by maricard          #+#    #+#             */
/*   Updated: 2023/02/20 13:37:59 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	line_counter(int fd)
{
	int		i;
	char	*buf;

	i = 0;
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			return (i);
		i++;
		free(buf);
	}
}

char	**map_array(int fd, int lines)
{
	char	**map;
	char	*temp;
	int		i;

	i = 0;
	map = ft_calloc(sizeof(char *), lines + 1);
	if (!map)
		return (0);
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			return (map);
		map[i] = temp;
		i++;
	}
}

int	map_array_validations(char *str)
{
	int		fd;
	int		lines;
	char	**map;

	fd = open(str, O_RDONLY);
	lines = line_counter(fd);
	close(fd);
	fd = open(str, O_RDONLY);
	map = map_array(fd, lines);
	while (*map)
	{
		printf("%s", *map);
		map++;
	}
	printf("\nJob Done!\n\n");
	close(fd);
	return (0);
}
