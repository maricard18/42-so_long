/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:40:25 by maricard          #+#    #+#             */
/*   Updated: 2023/04/04 12:37:12 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_root		root;

	ft_bzero(&root, sizeof(root));
	map_init(&(root.map));
	if (argc != 2)
	{
		ft_printf("Program needs <so_long> & <map.ber> to start!");
		return (0);
	}
	extension_validation(&root, argv[1]);
	map_validations(&root, argv[1], &(root.map));
	init_window(&root);
	load_sprites(&root);
	game(&root);
}
