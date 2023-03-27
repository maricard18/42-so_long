/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:44:39 by maricard          #+#    #+#             */
/*   Updated: 2023/03/27 08:12:41 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

// Libraries
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <../mlx/mlx.h>

// Libft library
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

// Macros
# define SIZE 32

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

# define ESC 27
# define UP 87
# define DOWN 83
# define LEFT 65
# define RIGHT 68

// Structs
typedef struct s_map
{
	int		lines;
	int		columns;
	char	**map_array;
	int		exits;
	int		collectibles;
	int		players;
	int		x;
	int		y;
	int		c;
	int		e;
	int		player_x_position;
	int		player_y_position;
}		t_map;

typedef struct s_sprites
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
}		t_sprites;

typedef struct s_mlx
{
	void		*ptr;
	void		*window;
	void		*image;
}		t_mlx;

typedef struct s_root
{
	t_map		map;
	t_mlx		mlx;
	t_sprites	sprites;
}		t_root;


// Functions
// Main
void	init_context(t_root *root);

// MapValidations
int		map_values(char *str, t_map *map);
int		extension_validation(char *str);
int		map_validations(char *str, t_map *map);
int		path_validation(t_map *map);
void 	flood_fill(int x, int y, t_map *map, char **map_array2);

// Utils
int		ft_error(char *str);
void	map_init(t_map *map);
void	init_window(t_root *root);
void	load_sprites(t_root *root);

// Game
int	game(t_root *root);
#endif
