/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:45:34 by maricard          #+#    #+#             */
/*   Updated: 2023/03/29 13:05:59 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	map = ft_calloc(lines + 1, sizeof(char *));
	if (!map)
		return (0);
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			return (map);
		map[i] = ft_strtrim(temp, "\n");
		free(temp);
		i++;
	}
}

void	characters(t_map *map)
{
	int		i;
	int		a;

	i = 0;
	while (map->map_array[i])
	{
		a = 0;
		while (map->map_array[i][a])
		{
			if (map->map_array[i][a] == 'C')
				map->collectibles++;
			if (map->map_array[i][a] == 'P')
			{
				map->players++;
				map->player_x_position = a;
				map->player_y_position = i;
			}
			if (map->map_array[i][a] == 'E')
				map->exits++;
			a++;
		}
		i++;
	}
}

int	map_values(t_root *root, char *str, t_map *map)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	map->lines = line_counter(fd);
	close(fd);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	map->map_array = map_array(fd, map->lines);
	if (map->lines == 0)
		ft_error(root, "Empty file :(");
	map->columns = ft_strlen(map->map_array[0]);
	close(fd);
	characters(map);
	return (0);
}
