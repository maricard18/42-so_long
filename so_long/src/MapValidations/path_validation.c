/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:16:15 by maricard          #+#    #+#             */
/*   Updated: 2023/03/14 12:24:23 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int flood(t_map *map)
{
    char    **pl;

    map->y = map->y2;
    map->x = map->x2;
    if (map->x < 0 || map->x >= map->columns
            || map->y < 0 || map->y >= map->lines
                || pl[map->y][map->x] != '0')
        break;
    else
    {
        pl[map->y][map->x] = 
    }
}

int flood_fill(t_map *map)
{
    
}