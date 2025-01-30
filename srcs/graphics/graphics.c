/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:38:23 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/30 21:13:05 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	draw_base(t_map *map)
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

void	draw_walls(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height && map->map[y])
	{
		x = -1;
		while (++x < map->width && map->map[y][x] != 0)
		{
			if (map->map[y][x] == WALL)
				mlx_put_image_to_window
					(map->mlx, map->win, map->wall, x * TILE, y * TILE);
		}
	}
}

void	draw_coll(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height && map->map[y] != 0)
	{
		x = -1;
		while (++x < map->width && map->map[y][x])
		{
			if (map->map[y][x] == COLLECTIBLE)
				mlx_put_image_to_window
					(map->mlx, map->win, map->collectible, x * TILE, y * TILE);
		}
	}
}

void	draw_empty(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height && map->map[y])
	{
		x = -1;
		while (++x < map->width && map->map[y][x] != 0)
		{
			if (map->map[y][x] == EMPTY_SPACE)
				mlx_put_image_to_window
					(map->mlx, map->win, map->empty_space, x * TILE, y * TILE);
		}
	}
}
