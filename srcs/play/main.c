/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:23:33 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/31 15:11:07 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	init_gamespace(t_map *map)
{
	if (init_window(map) < 0)
		return (-1);
	if (init_images(map) < 0)
		return (-1);
	draw_base(map);
	draw_walls(map);
	draw_coll(map);
	draw_player(map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (ft_printf(RED "Error\nIncorrect number of args\n" RS), -1);
	if (map_init(argv[1], &map) < 0)
		exit(1);
	if (init_gamespace(&map) < 0)
	{
		free_map(&map);
		return (ft_printf(RED "Error\nFailed to initialize game\n" RS), -1);
	}
	map.n_moves = 0;
	mlx_hook(map.win, 17, 0, close_window, &map);
	mlx_key_hook(map.win, handle_key, &map);
	if (mlx_loop(map.mlx) < 0)
	{
		free_map(&map);
		return (ft_printf(RED "Error\nmlx_loop failed\n" RS), -1);
	}
	free_map(&map);
	mlx_destroy_display(map.mlx);
	free(map.mlx);
	exit(0);
	return (0);
}
