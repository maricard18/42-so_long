/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:55:23 by maricard          #+#    #+#             */
/*   Updated: 2023/03/28 09:59:59 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    put_image_to_window(t_root *root, int column, int line)
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
    {
        mlx_put_image_to_window(root->mlx.ptr, \
            root->mlx.window, root->sprites.floor, column, line);
        mlx_put_image_to_window(root->mlx.ptr, \
            root->mlx.window, root->sprites.collectible, column, line);
    }
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
    root->map.x = root->map.player_x_position;
    root->map.y = root->map.player_y_position;
}

int game(t_root *root)
{
    draw_map(root);
    mlx_hook(root->mlx.window, 2, (1L<<0), key_pressed, root);
    mlx_loop(root->mlx.ptr);
    return (0);
}