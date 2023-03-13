/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:55:23 by maricard          #+#    #+#             */
/*   Updated: 2023/03/13 12:15:07 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int start_game(t_root *root)
{
    int y;
    int x;
    
    root->mlx.ptr = mlx_init();
    root->mlx.window = mlx_new_window(root->mlx.ptr, 800, 600, "so long");
    root->mlx.image = mlx_xpm_file_to_image(root->mlx.ptr, root->sprite.wall, &x, &y);
    mlx_put_image_to_window(root->mlx.ptr, root->mlx.window, root->mlx.window, 32, 32);
    mlx_loop(root->mlx.ptr);
    return (0);
}