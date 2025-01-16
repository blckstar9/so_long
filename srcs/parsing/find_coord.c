/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:50:57 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/16 22:02:48 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	find_player(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == PLAYER)
			{
				map->player_x = j;
				map->player_y = i;
				return (0);
			}
		}
	}
	return (-1);
}

int	find_exit(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == EXIT)
			{
				map->exit_x = j;
				map->exit_y = i;
				return (0);
			}
		}
	}
	return (-1);
}
