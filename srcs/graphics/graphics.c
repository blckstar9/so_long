/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:38:23 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/16 22:03:43 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	draw_floor(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			mlx_put_image_to_window
				(map->mlx, map->win, map->empty_space, x * TILE, y * TILE);
	}
}

void	draw_wnc(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map[y][x] == WALL)
				mlx_put_image_to_window
					(map->mlx, map->win, map->wall, x * TILE, y * TILE);
			if (map->map[y][x] == COLLECTIBLE)
				mlx_put_image_to_window
					(map->mlx, map->win, map->collectible, x * TILE, y * TILE);
		}
	}
}

void	draw_player(t_map *map)
{
	find_player(map);
	mlx_put_image_to_window
		(map->mlx, map->win, map->player
			, map->player_x * TILE, map->player_y * TILE);
}

void	draw_exit(t_map *map)
{
	find_exit(map);
	mlx_put_image_to_window
		(map->mlx, map->win, map->exit
			, map->exit_x * TILE, map->exit_y * TILE);
}