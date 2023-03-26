/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:16:15 by maricard          #+#    #+#             */
/*   Updated: 2023/03/26 10:48:40 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **map_duplicate(t_map *map, char **map_array2)
{
    int x;
    int y;

    y = 0;
    while (y < map->lines)
    {
        map_array2[y] = malloc(sizeof(char) * (map->columns + 1));
        if (!map_array2[y])
            return (0);
        y++;
    }
    map_array2[y] = NULL;
    y = 0;
    while (map_array2[y])
    {
        x = 0;
        while (x < map->columns)
        {
            map_array2[y][x] = map->map_array[y][x];
            x++;
        }
        y++;
    }
    return (map_array2);
}

int     path_validation(t_map *map)
{
    int     x;
    int     y;
    char    **map_array2;

    x = map->player_x_position;
    y = map->player_y_position;
    map_array2 = malloc(sizeof(char *) * (map->lines + 1));
    if (!map_array2)
        return (0);
    map_duplicate(map, map_array2);
    flood_fill(x, y, map, map_array2);
    if (map->c == map->collectibles && map->e == map->exits)
        return (0);
    else
        ft_error("There isn't a way out of this map!");
    map->c = 0;
    map->x = map->player_x_position;
    map->y = map->player_y_position;
    return (0);
}

void    flood_fill(int x, int y, t_map *map, char **map_array2)
{
    if (map_array2[y][x] == WALL)
        return ;
    else if (map_array2[y][x] == COLLECTIBLE)
        map->c++;
    else if (map_array2[y][x] == EXIT)
        map->e++;
    map_array2[y][x] = '1';
    flood_fill(x + 1, y, map, map_array2);
    flood_fill(x, y + 1, map, map_array2);
    flood_fill(x - 1, y, map, map_array2);
    flood_fill(x, y - 1, map, map_array2);
}