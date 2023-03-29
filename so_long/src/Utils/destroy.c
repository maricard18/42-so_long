/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:09:46 by maricard          #+#    #+#             */
/*   Updated: 2023/03/29 12:55:46 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arrays(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}	

void	destroy(t_root *root)
{
	free_arrays(root->map.map_array);
	if (root->sprites.collectible)
		mlx_destroy_image(root->mlx.ptr, root->sprites.collectible);
	if (root->sprites.collectible)
		mlx_destroy_image(root->mlx.ptr, root->sprites.wall);
	if (root->sprites.collectible)
		mlx_destroy_image(root->mlx.ptr, root->sprites.player);
	if (root->sprites.collectible)
		mlx_destroy_image(root->mlx.ptr, root->sprites.exit);
	if (root->sprites.collectible)
		mlx_destroy_image(root->mlx.ptr, root->sprites.floor);
	if (root->sprites.collectible)
		mlx_destroy_window(root->mlx.ptr, root->mlx.window);
	if (root->sprites.collectible)
		mlx_destroy_display(root->mlx.ptr);
	if (root->sprites.collectible)
		free(root->mlx.ptr);
	exit(0);
}
