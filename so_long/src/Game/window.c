/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:55:23 by maricard          #+#    #+#             */
/*   Updated: 2023/03/11 10:26:40 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int start_game(t_mlx *mlx)
{
    mlx->ptr = mlx_init();
//    mlx->window = mlx_new_window(mlx->ptr, 32*(mlx->map.lines), 32*(mlx->map.columns), "so long");
//    mlx->image = mlx_xpm_file_to_image(mlx->ptr, "./images/player.xpm", &mlx->sprite.x, &mlx->sprite.y);
    mlx_loop(mlx->ptr);
    return (0);
}