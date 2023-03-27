

#include "so_long.h"

void    move_player(t_root *root, int x, int y)
{
    if (root->map.map_array[y][x] == COLLECTIBLE)
    {
        root->map.c++;
    }
    mlx_put_image_to_window(root->mlx.ptr, \
        root->mlx.window, root->sprites.player, x, y);
    mlx_put_image_to_window(root->mlx.ptr, \
        root->mlx.window, root->sprites.floor, root->map.x, root->map.y);
}

int     check_next_tile(t_root *root, int x, int y)
{
    if (root->map.map_array[y][x] == WALL)
        return (0);
    else if (root->map.map_array[y][x] == EXIT 
                && root->map.c == root->map.collectibles)
    {
        move_player(root, x, y);
        ft_printf("YOU WON\n");
        exit(0);
    }
    root->map.x = x;
    root->map.y = y;
    move_player(root, x, y);
    return (0);
}

void    key_pressed(t_root *root, int key)
{
    if (key == UP)
    {
        check_next_tile(root, root->map.x, root->map.y + 1);
        root->map.y++;
    }
    else if (key == DOWN)
    {
        check_next_tile(root, root->map.x, root->map.y - 1);
        root->map.y--;
    }
    else if (key == LEFT)
    {
        check_next_tile(root, root->map.x - 1, root->map.y);
        root->map.x--;
    }
    else if (key == RIGHT)
    {
        check_next_tile(root, root->map.x + 1, root->map.y);
        root->map.x++;
    }
    else if (key == ESC)
        ft_printf("GAME OVER\n");
}