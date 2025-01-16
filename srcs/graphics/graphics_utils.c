/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:46:12 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/16 21:50:39 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	init_window(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (-1);
	map->win = mlx_new_window
		(map->mlx, map->width * TILE, map->height * TILE, "so_long");
	if (!map->win)
		return (-1);
	return (0);
}

int	init_images(t_map *map)
{
	map->wall = mlx_xpm_file_to_image
		(map->mlx, "../assets/wall.xpm", &map->width, &map->height);
	map->empty_space = mlx_xpm_file_to_image
		(map->mlx, "../assets/empty_space.xpm", &map->width, &map->height);
	map->collectible = mlx_xpm_file_to_image
		(map->mlx, "../assets/collectible.xpm", &map->width, &map->height);
	map->exit = mlx_xpm_file_to_image
		(map->mlx, "../assets/exit.xpm", &map->width, &map->height);
	map->player = mlx_xpm_file_to_image
		(map->mlx, "../assets/player.xpm", &map->width, &map->height);
	if (!map->wall || !map->empty_space
		|| !map->collectible || !map->exit || !map->player)
		return (-1);
	return (0);
}
