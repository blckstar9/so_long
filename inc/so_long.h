/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:52:34 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/31 17:10:53 by aybelaou         ###   ########.fr       */
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
# include "flood_fill.h"
# include "../libft/inc/gnl_inc/get_next_line.h"
# include "../libft/inc/libft_inc/libft.h"
# include "../libft/inc/printf_inc/ft_printf.h"

# define TILE 64
# define WALL '1'
# define EMPTY_SPACE '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define RED "\033[31m"
# define RS "\033[0m"
# define CY "\033[36m"
# define YL "\033[33m"
# define GR "\033[32m"
# define MG "\033[35m"

typedef struct s_map
{
	int		fd;
	int		width;
	int		height;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		n_collect;
	int		n_moves;
	char	**map;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*empty_space;
	void	*collectible;
	void	*exit;
	void	*player;
}	t_map;

// Parsing and map management
int		map_init(char *filename, t_map *map);
void	clear_newline(char *line);
int		get_matrix_dimensions(int *width, int *height, char *filename);
int		check_matrix_walls(char **matrix, int width, int height);
int		check_matrix_interior(t_map *map, char **matrix, int width, int height);
int		has_ber_extension(const char *filename);
void	free_map(t_map *map);
void	free_matrix(char **matrix);
int		is_map_valid(t_map *map, char **matrix, int width, int height);
int		count_character(char **matrix, int width, int height, char c);
int		is_path_valid(t_map *map, int start_x, int start_y);
int		find_player(t_map *map);
int		find_exit(t_map *map);

// Graphic management
int		init_window(t_map *map);
int		init_images(t_map *map);
void	draw_base(t_map *map);
void	draw_walls(t_map *map);
void	draw_coll(t_map *map);
void	draw_player(t_map *map);
void	draw_exit(t_map *map);
void	draw_empty(t_map *map);
int		close_window(t_map *map);
int		handle_key(int key, t_map *map);
void	free_images(t_map *map);
#endif