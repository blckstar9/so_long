/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:36:53 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/24 22:11:39 by aybelaou         ###   ########.fr       */
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
	if (map->map[map->player_y + y][map->player_x + x]
		== EXIT && map->n_collect == 0)
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

int translate_key(int key, int *x, int *y)
{
	*x = 0;
	*y = 0;
	if (key == XK_w)
		*y = -1;
	else if (key == XK_a)
		*x = -1;
	else if (key == XK_s)
		*y = 1;
	else if (key == XK_d)
		*x = 1;
	else
		return (0);
	return (1);
}