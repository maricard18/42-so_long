/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:27:27 by maricard          #+#    #+#             */
/*   Updated: 2023/03/05 19:15:42 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rectangle(t_map *map)
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
			ft_error("Map lines don't have the same length");
		i++;
	}
	if (map->lines == map->columns)
		ft_error("Map need's to be a rectangle!");
	return (0);
}

int	values(t_map *map)
{
	if (map->collectibles == 0)
		ft_error("No collectibles in this map");
	if (map->exits > 1)
		ft_error("There's more than 1 exit in this map");
	if (map->exits < 1)
		ft_error("The map doesn't have a exit");
	if (map->players > 1)
		ft_error("There's more than 1 player in this map");
	if (map->players < 1)
		ft_error("The map doesn't have a player");
	return (0);
}

int	walls(t_map *map)
{
	map->i = 1;
	map->a = 0;
	while (map->map_array[0])
	{
		if (map->map_array[0][map->a] != '1')
			ft_error("Map walls are invalid 1");
		map->a++;
	}
	while (map->i < (map->lines - 1))
	{
		if (map->map_array[map->i][0] != '1')
			ft_error("Map walls are invalid 2");
		if (map->map_array[map->i][map->columns - 1] != '1')
			ft_error("Map walls are invalid 3");
		map->i++;
	}
	map->a = 0;
	while (map->map_array[map->lines - 1][map->a])
	{
		if (map->map_array[map->lines - 1][map->a] != '1')
			ft_error("Map walls are invalid 4");
		map->a++;
	}
	return (0);
}

int	check_characters(t_map *map)
{
	map->i = 0;
	while (map->map_array[map->i])
	{
		map->a = 0;
		while (map->map_array[map->i][map->a])
		{
			if (map->map_array[map->i][map->a] != '0')
				ft_error("Invalid character");
			if (map->map_array[map->i][map->a] != '1')
				ft_error("Invalid character");
			if (map->map_array[map->i][map->a] != 'P')
				ft_error("Invalid character");
			if (map->map_array[map->i][map->a] != 'E')
				ft_error("Invalid character");
			if (map->map_array[map->i][map->a] != 'C')
				ft_error("Invalid character");
			map->a++;
		}
		map->i++;
	}
	return (0);
}

int	map_validations(char *str, t_map *map)
{
	map_values(str, map);
	rectangle(map);
	values(map);
	walls(map);
	check_characters(map);
	return (0);
}
