/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:28:10 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/03 20:21:20 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	check_matrix(char **matrix, int width, int height)
{
	ft_printf("Checking matrix walls...\n");
	if (check_matrix_walls(matrix, width, height) < 0)
		return (-1);
	ft_printf("Checking matrix interior...\n");
	if (check_matrix_interior(matrix, width, height) < 0)
		return (-1);
	return (0);
}

int	fill_map_struct(t_map *map, char **matrix)
{
	char	*line;
	int		i;

	ft_printf("Filling map structure...\n");
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
	if (check_matrix(matrix, map->width, map->height) < 0)
	{
		ft_printf("Invalid map\n");
		return (free_matrix(matrix), -1);
	}
	map->map = matrix;
	return (0);
}

int	map_init(char *filename, t_map *map)
{
	char	**matrix;

	ft_printf("Initializing map from file: %s\n", filename);
	if (!has_ber_extension(filename))
		return (-1);
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
		ft_printf("Failed to fill map structure\n");
        //free_matrix(matrix);
		//ft_printf("Freed matrix\n");
        close(map->fd);
		ft_printf("Closed file descriptor\n");
        return (-1);
    }
	close(map->fd);
	return (0);
}
