/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:16:15 by maricard          #+#    #+#             */
/*   Updated: 2023/03/15 13:20:11 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int path_validation(t_map *map)
{
    int x;
    int y;

    x = map->player_y_position;
    y = map->player_x_position;
    flood_fill(x, y, map);
    if (map->c == map->collectibles && map->e == map->exits)
        return (0);
    else
        ft_error("There isn't a way out of this map!");
    return (0);
}

void flood_fill(int x, int y, t_map *map)
{
    if (map->map_array[y][x] == WALL)
        return ;
    else if (map->map_array[y][x] == COLLECTIBLE)
        map->c++;
    else if (map->map_array[y][x] == EXIT)
        map->e++;
    flood_fill(x + 1, y, map);
    flood_fill(x, y + 1, map);
    flood_fill(x - 1, y, map);
    flood_fill(x, y - 1, map);
}