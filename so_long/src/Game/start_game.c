/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:55:23 by maricard          #+#    #+#             */
/*   Updated: 2023/03/15 11:22:18 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int put_image_to_window(t_root *root, int column, int line)
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
    return (0);
}

int draw_map(t_root *root)
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
    return (0);
}

int start_game(t_root *root)
{
    int x = 0;
    int y = 0;
    
    mlx_put_image_to_window(root->mlx.ptr, \
        root->mlx.window, root->sprites.floor, x, y);
    draw_map(root);
    mlx_loop(root->mlx.ptr);
    return (0);
}