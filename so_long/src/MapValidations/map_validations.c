/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:27:27 by maricard          #+#    #+#             */
/*   Updated: 2023/03/29 13:07:08 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rectangle(t_root *root, t_map *map)
{
	int	i;
	int	a;
	int	len;

	i = 0;
	len = ft_strlen(map->map_array[0]);
	while (map->map_array[i])
	{
		a = ft_strlen(map->map_array[i]);
		if (a != len)
			ft_error(root, "Map lines don't have the same length.");
		i++;
	}
	if (map->lines == map->columns)
		ft_error(root, "Map need's to be a rectangle.");
	return (0);
}

int	values(t_root *root, t_map *map)
{
	if (map->collectibles == 0)
		ft_error(root, "No collectibles in this map.");
	if (map->exits > 1)
		ft_error(root, "There's more than 1 exit in this map.");
	if (map->exits < 1)
		ft_error(root, "The map doesn't have a exit.");
	if (map->players > 1)
		ft_error(root, "There's more than 1 player in this map.");
	if (map->players < 1)
		ft_error(root, "The map doesn't have a player.");
	return (0);
}

int	walls(t_root *root, t_map *map)
{
	map->y = 1;
	map->x = 0;
	while (map->map_array[0][map->x])
	{
		if (map->map_array[0][map->x] != '1')
			ft_error(root, "Map walls are invalid 1.");
		map->x++;
	}
	while (map->y < (map->lines - 1))
	{
		if (map->map_array[map->y][0] != '1')
			ft_error(root, "Map walls are invalid 2.");
		if (map->map_array[map->y][map->columns - 1] != '1')
			ft_error(root, "Map walls are invalid 3.");
		map->y++;
	}
	map->x = 0;
	while (map->map_array[map->lines - 1][map->x])
	{
		if (map->map_array[map->lines - 1][map->x] != '1')
			ft_error(root, "Map walls are invalid 4.");
		map->x++;
	}
	return (0);
}

int	check_characters(t_root *root, t_map *map)
{
	map->y = 0;
	while (map->map_array[map->y])
	{
		map->x = 0;
		while (map->map_array[map->y][map->x])
		{
			if (map->map_array[map->y][map->x] != '0'
					&& map->map_array[map->y][map->x] != '1'
						&& map->map_array[map->y][map->x] != 'P'
							&& map->map_array[map->y][map->x] != 'C'
								&& map->map_array[map->y][map->x] != 'E')
				ft_error(root, "invalid character.");
			map->x++;
		}
		map->y++;
	}
	return (0);
}

int	map_validations(t_root *root, char *str, t_map *map)
{
	map_values(root, str, map);
	rectangle(root, map);
	values(root, map);
	walls(root, map);
	check_characters(root, map);
	path_validation(root, map);
	return (0);
}
