/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:28:10 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/02 20:43:58 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int check_matrix(char **matrix, int width, int height)
{
	if (check_matrix_walls(matrix, width, height) < 0)
		return (-1);
	if (check_matrix_interior(matrix, width, height) < 0)
		return (-1);
	return (0);
}

int fill_map_struct(t_map *map, char **matrix, int width, int height, int fd)
{
    char *line;
    int i;

    line = get_next_line(fd);
    if (!line)
        return (-1);
    i = 0;
    while (line)
	{
		clear_newline(line);
		if ((int)ft_strlen(line) != width)
			return (free(line), free_matrix(matrix), -1);
		matrix[i++] = line;
		line = get_next_line(fd);
    }
    if (check_matrix(matrix, width, height) < 0)
		return (free_matrix(matrix), -1);
	map->map = matrix;
	map->width = width;
	map->height = height;
    return (0);
}

int map_init(char *filename, t_map *map)
{
	int		fd;
	char	**matrix;
	int		width;
	int		height;

	if (!has_ber_extension(filename))
		return (-1);
	if (get_matrix_dimensions(&width, &height, filename) < 0)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	matrix = ft_calloc(sizeof(char *), (height + 1));
	if (!matrix)
		return (close(fd), -1);
	if (fill_map_struct(map, matrix, width, height, fd) < 0)
		return(free_matrix(matrix), free_map(map), close(fd), -1);
	close(fd);
	return (0);
}
