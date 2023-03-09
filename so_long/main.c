/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:40:25 by maricard          #+#    #+#             */
/*   Updated: 2023/03/09 13:05:35 by maricard         ###   ########.fr       */
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
void	struct_game_init(t_game *game)
{
	game->mlx = 0;
	game->window = 0;	
	game->image = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;

	struct_map_init(&map);
	struct_game_init(&game);
	if (argc != 2)
	{
		ft_printf("Program needs <so_long> & <map.ber> to start!");
		return (0);
	}
	extension_validation(argv[1]);
	map_validations(argv[1], &map);
	start_game(&game);
}
