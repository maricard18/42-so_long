/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:44:39 by maricard          #+#    #+#             */
/*   Updated: 2023/03/09 13:05:12 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

// C Libraries
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <../mlx/mlx.h>

// Libft library
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

//Structs
typedef struct s_map
{
	int		lines;
	int		columns;
	char	**map_array;
	int		exits;
	int		collectibles;
	int		players;
	int		i;
	int		a;
}		t_map;

typedef struct s_game
{
	t_map	map;
	void	*mlx;
	void	*window;
	void	*image;
}		t_game;

// Functions
// MapValidations
int		map_values(char *str, t_map *map);
int		extension_validation(char *str);
int		map_validations(char *str, t_map *map);

//Utils
int	ft_error(char *str);

//Game
int	start_game(t_game *game);

#endif
