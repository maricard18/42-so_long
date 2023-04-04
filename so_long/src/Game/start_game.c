/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:48:59 by maricard          #+#    #+#             */
/*   Updated: 2023/04/04 11:49:57 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_root *root, int x, int y)
{
	if (root->map.map_array[y][x] == COLLECTIBLE)
	{
		root->map.map_array[y][x] = '0';
		root->map.c++;
	}
	if (root->map.map_array[root->map.y][root->map.x] == EXIT)
	{
		mlx_put_image_to_window(root->mlx.ptr, \
			root->mlx.window, root->sprites.player, x * SIZE, y * SIZE);
		mlx_put_image_to_window(root->mlx.ptr, \
			root->mlx.window, root->sprites.exit, \
				root->map.x * SIZE, root->map.y * SIZE);
		root->map.moves++;
		return ;
	}
	mlx_put_image_to_window(root->mlx.ptr, \
		root->mlx.window, root->sprites.player, x * SIZE, y * SIZE);
	mlx_put_image_to_window(root->mlx.ptr, \
		root->mlx.window, root->sprites.floor, \
			root->map.x * SIZE, root->map.y * SIZE);
	root->map.moves++;
}

int	check_next_tile(t_root *root, int x, int y)
{
	if (root->map.map_array[y][x] == WALL)
		return (0);
	else if (root->map.map_array[y][x] == EXIT)
	{
		if (root->map.c == root->map.collectibles)
		{
			move_player(root, x, y);
			ft_printf("Moves: %d\n", root->map.moves);
			ft_printf("---------\n YOU WON\n");
			destroy(root);
		}
	}
	move_player(root, x, y);
	ft_printf("Moves: %d\n", root->map.moves);
	root->map.x = x;
	root->map.y = y;
	return (0);
}

int	key_pressed(int key, t_root *root)
{
	if (key == UP || key == W)
		check_next_tile(root, root->map.x, root->map.y - 1);
	else if (key == DOWN || key == S)
		check_next_tile(root, root->map.x, root->map.y + 1);
	else if (key == LEFT || key == A)
		check_next_tile(root, root->map.x - 1, root->map.y);
	else if (key == RIGHT || key == D)
		check_next_tile(root, root->map.x + 1, root->map.y);
	else if (key == ESC)
	{
		ft_printf("---------\nGAME OVER\n");
		destroy(root);
	}	
	return (0);
}
