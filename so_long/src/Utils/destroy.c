/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:09:46 by maricard          #+#    #+#             */
/*   Updated: 2023/03/29 10:54:05 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy(t_root *root)
{
	mlx_destroy_image(root->mlx.ptr, root->sprites.collectible);
	mlx_destroy_image(root->mlx.ptr, root->sprites.wall);
	mlx_destroy_image(root->mlx.ptr, root->sprites.player);
	mlx_destroy_image(root->mlx.ptr, root->sprites.exit);
	mlx_destroy_image(root->mlx.ptr, root->sprites.floor);
	mlx_destroy_window(root->mlx.ptr, root->mlx.window);
}
