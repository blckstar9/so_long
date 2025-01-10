/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:50:57 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/10 19:24:48 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int *find_player(char **matrix, int width, int height)
{
	int *coord;
	int i;
	int j;

	coord = malloc(sizeof(int) * 2);
	if (!coord)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (matrix[i][j] == PLAYER)
			{
				coord[0] = i;
				coord[1] = j;
				return (coord);
			}
		}
	}
	return (NULL);
}

int	init_player(t_map *map)
{
	int *coord;

	coord = find_player(map->map, map->width, map->height);
	if (!coord)
		return (ft_printf("Player not found\n"), -1);
	map->player_x = coord[1];
	map->player_y = coord[0];
	free(coord);
	return (0);
}