/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:36:53 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/16 22:27:15 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int    move_player(t_map *map, int x, int y)
{
	if (map->map[map->player_y + y][map->player_x + x] == WALL)
		return (0);
	if (map->map[map->player_y + y][map->player_x + x] == COLLECTIBLE)
	{
		map->n_collect--;
		ft_printf("Collectibles left: %d\n", map->n_collect);
	}
	if (map->map[map->player_y + y][map->player_x + x] == EXIT && map->n_collect == 0)
	{
		ft_printf("You won!\n");
		free_map(map);
		exit(0);
	}
	map->map[map->player_y][map->player_x] = EMPTY_SPACE;
	map->player_x += x;
	map->player_y += y;
	map->map[map->player_y][map->player_x] = PLAYER;
	return (1);
}

