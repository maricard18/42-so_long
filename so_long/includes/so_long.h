/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:44:39 by maricard          #+#    #+#             */
/*   Updated: 2023/12/08 03:01:35 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Libraries
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifdef __APPLE__
#  include "../mlx_macos/mlx.h"
# else
#  include "../mlx_linux/mlx.h"
#  include <X11/X.h>
# endif

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

# ifdef __APPLE__
#  define ESC 53
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
#  define W 13
#  define A 0
#  define S 1
#  define D 2
# else
#  define ESC 65307
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define W 119
#  define S 115
#  define A 97
#  define D 100
# endif

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
	int		moves;
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
// MapValidations
int		map_values(t_root *root, char *str, t_map *map);
int		extension_validation(t_root *root, char *str);
int		map_validations(t_root *root, char *str, t_map *map);
int		path_validation(t_root *root, t_map *map);
void	flood_fill(int x, int y, t_map *map, char **map_array2);

// Utils
int		ft_error(t_root *root, char *str);
int		close_game(t_root *root);
void	destroy(t_root *root);
void	free_arrays(char **array);
void	map_init(t_map *map);
void	init_window(t_root *root);
void	load_sprites(t_root *root);

// Game
int		game(t_root *root);
int		key_pressed(int key, t_root *root);

#endif
