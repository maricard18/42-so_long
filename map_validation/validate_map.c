/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:45:34 by maricard          #+#    #+#             */
/*   Updated: 2023/02/16 13:34:59 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "./get_next_line/get_next_line.h"

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
	}
	return (i);
}

char	**map_array(int fd, int lines)
{
	char	**map;
	char	*temp;

	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (0);
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			return (map);
		*map = temp;
		map++;
	}
	return (map);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		lines;
	char	**map;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	lines = line_counter(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map = map_array(fd, lines);
	while (*map)
	{
		printf("%s\n", *map);
		map++;
	}
	printf("\nJob Done!\n\n");
	close(fd);
	return (0);
}
