/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:40:25 by maricard          #+#    #+#             */
/*   Updated: 2023/03/10 12:28:03 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	struct_init(t_root *root)
{
	struct_map_init(root->map);
	struct_mlx_init(root->mlx);
	strcut_sprite_init(root->sprite);
}

int	main(int argc, char **argv)
{
	t_root	*root;

	root = 0;
	struct_init(root);
	if (argc != 2)
	{
		ft_printf("Program needs <so_long> & <map.ber> to start!");
		return (0);
	}
	extension_validation(argv[1]);
	map_validations(argv[1], root->map);
	start_game(root->mlx);
}