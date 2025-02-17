/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:46:12 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/30 21:14:03 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	init_window(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (ft_printf("Error\nFailed to initialize mlx\n"), -1);
	map->win = mlx_new_window
		(map->mlx, map->width * TILE, map->height * TILE, "so_long");
	if (!map->win)
	{
		ft_printf("Error\nFailed to create window\n");
		mlx_destroy_display(map->mlx);
		free(map->mlx);
		return (-1);
	}
	return (0);
}

int	init_images(t_map *map)
{
	map->wall = mlx_xpm_file_to_image
		(map->mlx, "srcs/assets/wall.xpm", &map->width, &map->height);
	map->empty_space = mlx_xpm_file_to_image
		(map->mlx, "srcs/assets/empty_space.xpm", &map->width, &map->height);
	map->collectible = mlx_xpm_file_to_image
		(map->mlx, "srcs/assets/collectible.xpm", &map->width, &map->height);
	map->exit = mlx_xpm_file_to_image
		(map->mlx, "srcs/assets/exit.xpm", &map->width, &map->height);
	map->player = mlx_xpm_file_to_image
		(map->mlx, "srcs/assets/player.xpm", &map->width, &map->height);
	if (!map->wall || !map->empty_space
		|| !map->collectible || !map->exit || !map->player)
	{
		free_images(map);
		return (ft_printf("Error\nFailed to load images\n"), -1);
	}
	return (0);
}

void	free_images(t_map *map)
{
	if (map->wall)
		mlx_destroy_image(map->mlx, map->wall);
	if (map->empty_space)
		mlx_destroy_image(map->mlx, map->empty_space);
	if (map->collectible)
		mlx_destroy_image(map->mlx, map->collectible);
	if (map->exit)
		mlx_destroy_image(map->mlx, map->exit);
	if (map->player)
		mlx_destroy_image(map->mlx, map->player);
}

void	draw_player(t_map *map)
{
	mlx_put_image_to_window
		(map->mlx, map->win, map->player
			, map->p_x * TILE, map->p_y * TILE);
}

void	draw_exit(t_map *map)
{
	if (map->n_collect == 0)
		mlx_put_image_to_window
			(map->mlx, map->win, map->exit
				, map->e_x * TILE, map->e_y * TILE);
}
