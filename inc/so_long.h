/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:52:34 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/10 19:11:21 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <assert.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "hooks.h"
# include "flood_fill.h"
# include "../libft/inc/gnl_inc/get_next_line.h"
# include "../libft/inc/libft_inc/libft.h"
# include "../libft/inc/printf_inc/ft_printf.h"

# define W_HEIGHT 1080
# define W_WIDTH 1920
# define TILE_SIZE 64
# define WALL '1'
# define EMPTY_SPACE '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

typedef struct s_map
{
	int		fd;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	char	**map;
}	t_map;

int		map_init(char *filename, t_map *map);
void	clear_newline(char *line);
int		fill_map_struct(t_map *map, char **matrix);
int		get_matrix_dimensions(int *width, int *height, char *filename);
int		check_matrix_walls(char **matrix, int width, int height);
int		check_matrix_interior(char **matrix, int width, int height);
int		has_ber_extension(const char *filename);
void	free_map(t_map *map);
void	free_matrix(char **matrix);
int		is_map_valid(char **matrix, int width, int height);
int		count_character(char **matrix, int width, int height, char c);
int		is_path_valid(t_map *map, int start_x, int start_y);
int		init_player(t_map *map);
#endif