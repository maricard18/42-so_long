/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:45:34 by maricard          #+#    #+#             */
/*   Updated: 2023/02/17 13:35:51 by maricard         ###   ########.fr       */
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
		{
			free(buf);
			return (i);
		}
		i++;
	}
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
		{
			free(temp);
			return (map);
		}
		*map = temp;
		map++;
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
	while (**map)
	{
		printf("%s\n", *map);
		map++;
	}
	printf("\nJob Done!\n\n");
	close(fd);
	return (0);
}
