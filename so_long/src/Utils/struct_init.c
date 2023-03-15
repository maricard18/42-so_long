/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:25:07 by maricard          #+#    #+#             */
/*   Updated: 2023/03/14 12:23:03 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	struct_map_init(t_map *map)
{
	map->lines = 0;
	map->columns = 0;
	map->map_array = 0;
	map->exits = 0;
	map->collectibles = 0;
	map->players = 0;
}
void	struct_mlx_init(t_mlx *mlx)
{
	mlx->ptr = 0;
	mlx->window = 0;	
	mlx->image = 0;
}

void	strcut_sprite_init(t_sprite *sprite, t_root *root)
{
	int	x;
	int	y;
	
	sprite->floor = mlx_xpm_file_to_image(root->mlx.ptr, \
											"./images/floor.xpm", &x, &y);
	sprite->wall = mlx_xpm_file_to_image(root->mlx.ptr, \
											"./images/wall.xpm", &x, &y);
	sprite->player = mlx_xpm_file_to_image(root->mlx.ptr, \
											"./images/player.xpm", &x, &y);
	sprite->collectible = mlx_xpm_file_to_image(root->mlx.ptr, \
											"./images/collectible.xpm", &x, &y);
	sprite->exit = mlx_xpm_file_to_image(root->mlx.ptr, \
											"./images/exit.xpm", &x, &y);
}