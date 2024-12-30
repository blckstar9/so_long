/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:28:10 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/30 18:54:40 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	has_ber_extension(const char *filename)
{
	const char	*ext;
	size_t		len;
	size_t		ext_len;

	ext = ".ber";
	len = ft_strlen(filename);
	ext_len = ft_strlen(ext);
	if (len >= ext_len)
		return (ft_strncmp(filename + len - ext_len, ext, ext_len) == 0);
	return (0);
}

int check_matrix_walls(char **matrix, int width, int height)
{
	int i;
	int j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		if (matrix[i][0] != WALL || matrix[i][width - 1] != WALL)
			return (-1);
		while (++j < width)
		{
			if (matrix[0][j] != WALL || matrix[height - 1][j] != WALL)
				return (-1);
		}
	}
	return (0);
}

int get_matrix_dimensions(int *width, int *height, char *filename)
{
    char *line;
    int max_width;
    int max_height;
	int fd;
	
	fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), -1);
	max_width = ft_strlen(line);
	max_height = 0;
    while (line)
    {  
        if (ft_strlen(line) != max_width)
            return (free(line), close(fd), -1);
        max_height++;
		free(line);
		line = get_next_line(fd);
    }
    *width = max_width;
    *height = max_height;
	close(fd);
    return (0);
}

int fill_map_struct(t_map *map, char **matrix, int width, int height, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line)
	{
		if (ft_strlen(line) != width)
			return (free(line), -1);
		*matrix = line;
		matrix++;
		line = get_next_line(fd);
	}
	if (check_matrix_walls(matrix, width, height) < 0)
		return (-1);
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
	int i;

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
	i = -1;
	if (fill_map_struct(map, matrix, width, height, fd) < 0)
	{	
        while (++i < height)
            free(matrix[i]);
        return (free(matrix), close(fd), -1);
	}
	close(fd);
	return (0);
}
