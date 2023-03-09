/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:55:23 by maricard          #+#    #+#             */
/*   Updated: 2023/03/09 13:20:58 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int start_game(t_game *game)
{
    game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx, 900, 600, "so long");
    game->image = mlx_new_image(game->mlx, 32, 32);
    mlx_loop(game->mlx);
    return (0);
} 