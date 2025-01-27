/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:36:53 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/27 21:48:55 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	close_window(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	free_map(map);
	exit(0);
	return (0);
}

static int	move_player(t_map *map, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = map->p_x + x;
	new_y = map->p_y + y;
	if (map->map[new_y][new_x] == WALL)
		return (0);
	if (map->map[new_y][new_x] == COLLECTIBLE)
	{
		map->n_collect--;
		ft_printf("Collectibles left: %d\n", map->n_collect);
	}
	if (new_x == map->e_x && new_y == map->e_y && map->n_collect == 0)
	{
		ft_printf("You won!\n");
		free_map(map);
		exit(0);
	}
	map->map[map->p_y][map->p_x] = EMPTY_SPACE;
	map->p_x = new_x;
	map->p_y = new_y;
	map->map[map->p_y][map->p_x] = PLAYER;
	if (map->n_collect == 0)
		draw_exit(map);
	return (1);
}

static int	translate_key(int key, int *x, int *y)
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

int	handle_key(int key, t_map *map)
{
	int	x;
	int	y;

	if (key == XK_Escape)
		close_window(map);
	if (translate_key(key, &x, &y))
	{
		if (move_player(map, x, y))
		{
			draw_empty(map);
			draw_coll(map);
			draw_player(map);
			draw_exit(map);
		}
	}
	return (0);
}
