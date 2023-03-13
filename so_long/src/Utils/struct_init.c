/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:25:07 by maricard          #+#    #+#             */
/*   Updated: 2023/03/13 12:09:10 by maricard         ###   ########.fr       */
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

void	strcut_sprite_init(t_sprite *sprite)
{
	sprite->floor = "./images/floor.xpm";
	sprite->wall = "./images/wall.xpm";
	sprite->player = "./images/player.xpm";
	sprite->collectible = "./images/collectible.xpm";
	sprite->exit = "./images/exit.xpm";
	sprite->x = 32;
	sprite->y = 32;
}