/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:09:46 by maricard          #+#    #+#             */
/*   Updated: 2023/12/08 03:19:59 by maricard         ###   ########.fr       */
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
	if (root->map.map_array)
		free_arrays(root->map.map_array);
	if (root->sprites.collectible)
		mlx_destroy_image(root->mlx.ptr, root->sprites.collectible);
	if (root->sprites.wall)
		mlx_destroy_image(root->mlx.ptr, root->sprites.wall);
	if (root->sprites.player)
		mlx_destroy_image(root->mlx.ptr, root->sprites.player);
	if (root->sprites.exit)
		mlx_destroy_image(root->mlx.ptr, root->sprites.exit);
	if (root->sprites.floor)
		mlx_destroy_image(root->mlx.ptr, root->sprites.floor);
	if (root->mlx.window)
		mlx_destroy_window(root->mlx.ptr, root->mlx.window);
	if (root->mlx.ptr)
		//mlx_destroy_display(root->mlx.ptr);
	if (root->mlx.ptr)
		free(root->mlx.ptr);
	exit(0);
}

int	close_game(t_root *root)
{
	ft_printf("---------\nGAME OVER\n");
	destroy(root);
	return (0);
}
