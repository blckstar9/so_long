/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:46:12 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/23 21:40:01 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

// int	init_window(t_map *map)
// {
// 	map->mlx = mlx_init();
// 	if (!map->mlx)
// 		return (-1);
// 	map->win = mlx_new_window
// 		(map->mlx, map->width * TILE, map->height * TILE, "so_long");
// 	if (!map->win)
// 		return (-1);
// 	return (0);
// }

// int	init_images(t_map *map)
// {
// 	map->wall = mlx_xpm_file_to_image
// 		(map->mlx, "srcs/assets/wall.xpm", &map->width, &map->height);
// 	map->empty_space = mlx_xpm_file_to_image
// 		(map->mlx, "srcs/assets/empty_space.xpm", &map->width, &map->height);
// 	map->collectible = mlx_xpm_file_to_image
// 		(map->mlx, "srcs/assets/collectible.xpm", &map->width, &map->height);
// 	map->exit = mlx_xpm_file_to_image
// 		(map->mlx, "srcs/assets/exit.xpm", &map->width, &map->height);
// 	map->player = mlx_xpm_file_to_image
// 		(map->mlx, "srcs/assets/player.xpm", &map->width, &map->height);
// 	if (!map->wall || !map->empty_space
// 		|| !map->collectible || !map->exit || !map->player)
// 		return (-1);
// 	return (0);
// }

int init_window(t_map *map)
{
    map->mlx = mlx_init();
    if (!map->mlx)
        return (ft_printf("Failed to initialize mlx\n"), -1);
    map->win = mlx_new_window(map->mlx, map->width * TILE, map->height * TILE, "so_long");
    if (!map->win)
        return (ft_printf("Failed to create window\n"), -1);
    return (0);
}

int init_images(t_map *map)
{
    map->wall = mlx_xpm_file_to_image(map->mlx, "srcs/assets/wall.xpm", &map->width, &map->height);
    if (!map->wall)
        return (ft_printf("Failed to load wall.xpm\n"), -1);

    map->empty_space = mlx_xpm_file_to_image(map->mlx, "srcs/assets/empty_space.xpm", &map->width, &map->height);
    if (!map->empty_space)
        return (ft_printf("Failed to load empty_space.xpm\n"), -1);

    map->collectible = mlx_xpm_file_to_image(map->mlx, "srcs/assets/collectible.xpm", &map->width, &map->height);
    if (!map->collectible)
        return (ft_printf("Failed to load collectible.xpm\n"), -1);

    map->exit = mlx_xpm_file_to_image(map->mlx, "srcs/assets/exit.xpm", &map->width, &map->height);
    if (!map->exit)
        return (ft_printf("Failed to load exit.xpm\n"), -1);

    map->player = mlx_xpm_file_to_image(map->mlx, "srcs/assets/player.xpm", &map->width, &map->height);
    if (!map->player)
        return (ft_printf("Failed to load player.xpm\n"), -1);

    return (0);
}