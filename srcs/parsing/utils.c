/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:36:01 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/03 19:31:59 by aybelaou         ###   ########.fr       */
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

void	clear_newline(char *line)
{
	size_t	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	get_matrix_dimensions(int *width, int *height, char *filename)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), -1);
	clear_newline(line);
	*width = ft_strlen(line);
	*height = 0;
	while (line)
	{
		if ((int)ft_strlen(line) != *width)
			return (free(line), close(fd), -1);
		(*height)++;
		free(line);
		line = get_next_line(fd);
		clear_newline(line);
	}
	close(fd);
	return (0);
}

int	check_matrix_interior(char **matrix, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	if (is_map_valid(matrix, width, height) < 0)
		return (-1);
	while (++i < height - 1)
	{
		j = 0;
		while (++j < width - 1)
		{
			if (matrix[i][j] != EMPTY_SPACE && matrix[i][j] != WALL
			&& matrix[i][j] != COLLECTIBLE && matrix[i][j] != EXIT
			&& matrix[i][j] != PLAYER)
			{
				ft_printf("Invalid character '%c' at (%d, %d)\n", matrix[i][j], i, j);
				return (-1);
			}
		}
	}
	return (0);
}

int	check_matrix_walls(char **matrix, int width, int height)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		if (matrix[i][0] != WALL || matrix[i][width - 1] != WALL)
			return (-1);
	}
	j = -1;
	while (++j < width)
	{
		if (matrix[0][j] != WALL || matrix[height - 1][j] != WALL)
			return (-1);
	}
	return (0);
}
