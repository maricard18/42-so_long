/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:25:07 by maricard          #+#    #+#             */
/*   Updated: 2023/03/25 11:22:58 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_map *map)
{
	map->exits = 0;
	map->collectibles = 0;
	map->players = 0;
	map->c = 0;
	map->e = 0;
}

void	init_window(t_root *root)
{
	root->mlx.ptr = mlx_init();
    root->mlx.window = mlx_new_window(root->mlx.ptr, \
        1100, 200, "so long");
}

void	load_sprites(t_root *root)
{
	int	x;
	int	y;
	
	root->sprites.floor = mlx_xpm_file_to_image(root->mlx.ptr, \
		"./images/floor.xpm", &x, &y);
	root->sprites.wall = mlx_xpm_file_to_image(root->mlx.ptr, \
		"./images/wall.xpm", &x, &y);
	root->sprites.player = mlx_xpm_file_to_image(root->mlx.ptr, \
		"./images/player.xpm", &x, &y);
	root->sprites.collectible = mlx_xpm_file_to_image(root->mlx.ptr, \
		"./images/collectible.xpm", &x, &y);
	root->sprites.exit = mlx_xpm_file_to_image(root->mlx.ptr, \
		"./images/exit.xpm", &x, &y);
}