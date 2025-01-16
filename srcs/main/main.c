/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:23:33 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/16 22:31:53 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	init_gamespace(t_map *map)
{
	if (init_window(map) < 0)
		return (-1);
	if (init_images(map) < 0)
		return (-1);
	draw_floor(map);
	draw_wnc(map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (ft_printf("Error\nUsage: ./so_long [map_path]\n"), -1);
	if (map_init(argv[1], &map) == -1)
		return (ft_printf("Error\nInvalid map\n"), -1);
	if (init_gamespace(&map) < 0)
	{
		free_map(&map);
		return (ft_printf("Error\nFailed to initialize gamespace\n"), -1);
	}
	return (0);
}
