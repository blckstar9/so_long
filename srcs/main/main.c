/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:23:33 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/15 19:36:27 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (ft_printf("Error\nUsage: ./so_long [map_path]\n"), -1);
	if (map_init(argv[1], &map) == -1)
		return (ft_printf("Error\nInvalid map\n"), -1);
	else
		play(&map);
	return (0);
}
