/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:28:10 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/31 17:09:34 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	check_matrix(t_map *map, char **matrix, int width, int height)
{
	ft_printf(YL "Checking matrix walls...\n" RS);
	if (check_matrix_walls(matrix, width, height) < 0)
		return (ft_printf(RED "Error\nIncorrect walls!\n" RS), -1);
	ft_printf(YL "Checking matrix interior...\n" RS);
	if (check_matrix_interior(map, matrix, width, height) < 0)
		return (ft_printf(RED "Error\nIncorrect interrior\n" RS), -1);
	return (0);
}

static int	fill_map_struct(t_map *map, char **matrix)
{
	char	*line;
	int		i;

	ft_printf(YL "Filling map structure...\n" RS);
	line = get_next_line(map->fd);
	if (!line)
		return (-1);
	i = 0;
	while (line)
	{
		clear_newline(line);
		if ((int)ft_strlen(line) != map->width)
			return (free(line), free_matrix(matrix), -1);
		matrix[i++] = line;
		line = get_next_line(map->fd);
	}
	if (check_matrix(map, matrix, map->width, map->height) < 0)
	{
		ft_printf(RED "Error\nInvalid map\n" RS);
		return (free_matrix(matrix), -1);
	}
	map->map = matrix;
	if (find_player(map) < 0 || find_exit(map) < 0)
		return (free_matrix(matrix), -1);
	return (0);
}

int	map_init(char *filename, t_map *map)
{
	char	**matrix;

	ft_printf(YL "Initializing map from file: %s\n" RS, filename);
	if (!has_ber_extension(filename))
		return (ft_printf(RED "Error\nIncorrect file\n" RS), -1);
	if (get_matrix_dimensions(&map->width, &map->height, filename) < 0)
		return (-1);
	map->fd = open(filename, O_RDONLY);
	if (map->fd < 0)
		return (-1);
	matrix = ft_calloc(sizeof(char *), (map->height + 1));
	if (!matrix)
		return (close(map->fd), -1);
	if (fill_map_struct(map, matrix) < 0)
	{
		ft_printf(RED "Error\nFailed to fill map structure\n" RS);
		return (close(map->fd), -1);
	}
	close(map->fd);
	if (!is_path_valid(map, map->p_x, map->p_y))
	{
		ft_printf(RED "Error\nInvalid path in map\n" RS);
		return (free_matrix(matrix), -1);
	}
	return (ft_printf(GR "Valid path in map\n" RS), close(map->fd), 0);
}
