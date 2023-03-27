/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:55:23 by maricard          #+#    #+#             */
/*   Updated: 2023/03/27 08:11:18 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_image_to_window(t_root *root, int column, int line)
{
    if (root->map.map_array[root->map.y][root->map.x] == WALL)
        mlx_put_image_to_window(root->mlx.ptr, \
            root->mlx.window, root->sprites.wall, column, line);
    else if (root->map.map_array[root->map.y][root->map.x] == FLOOR)
        mlx_put_image_to_window(root->mlx.ptr, \
            root->mlx.window, root->sprites.floor, column, line);
    else if (root->map.map_array[root->map.y][root->map.x] == PLAYER)
        mlx_put_image_to_window(root->mlx.ptr, \
            root->mlx.window, root->sprites.player, column, line);
    else if (root->map.map_array[root->map.y][root->map.x] == COLLECTIBLE)
        mlx_put_image_to_window(root->mlx.ptr, \
            root->mlx.window, root->sprites.collectible, column, line);
    else if (root->map.map_array[root->map.y][root->map.x] == EXIT)
        mlx_put_image_to_window(root->mlx.ptr, \
            root->mlx.window, root->sprites.exit, column, line);
}

void draw_map(t_root *root)
{
    int column;
    int line;

    line = 0;
    root->map.y = 0;
    while (root->map.map_array[root->map.y])
    {
        column = 0;
        root->map.x = 0;
        while (root->map.map_array[root->map.y][root->map.x])
        {
            put_image_to_window(root, column, line);
            root->map.x++;
            column += SIZE;
        }
        root->map.y++;
        line += SIZE;
    }
}

int game(t_root *root)
{
    draw_map(root);
    key_pressed(root, key);
    mlx_loop(root->mlx.ptr);
    return (0);
}