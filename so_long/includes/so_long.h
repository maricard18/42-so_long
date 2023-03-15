/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:44:39 by maricard          #+#    #+#             */
/*   Updated: 2023/03/14 11:20:20 by maricard         ###   ########.fr       */
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

// Image Macros
# define SIZE 64
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

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
	int		x2;
	int		y2;
}		t_map;

typedef struct s_sprite
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
}		t_sprite;

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
	t_sprite	sprite;
}		t_root;


// Functions
// Main
void	struct_init(t_root *root);

// MapValidations
int		map_values(char *str, t_map *map);
int		extension_validation(char *str);
int		map_validations(char *str, t_map *map);

// Utils
int		ft_error(char *str);
void	struct_map_init(t_map *map);
void	struct_mlx_init(t_mlx *mlx);
void	strcut_sprite_init(t_sprite *sprite, t_root *root);

// Game
int	start_game(t_root *root);

#endif
