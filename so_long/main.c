/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:40:25 by maricard          #+#    #+#             */
/*   Updated: 2023/03/06 23:42:37 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	struct_initializer(t_map *map)
{
	map->lines = 0;
	map->columns = 0;
	map->map_array = 0;
	map->exits = 0;
	map->collectibles = 0;
	map->players = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;

	struct_initializer(&map);
	if (argc != 2)
	{
		ft_printf("Program needs <so_long> & <map.ber> to start!");
		return (0);
	}
	extension(argv[1]);
	map_validations(argv[1], &map);
	ft_printf("OK!\n");
}
