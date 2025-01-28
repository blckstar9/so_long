/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:28:53 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/28 18:14:09 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

#include "../../inc/so_long.h"

void free_map(t_map *map)
{
    int i;

    if (!map || !map->map)
        return;

    i = -1;
    while (++i < map->height)
    {
        if (map->map[i])
        {
            free(map->map[i]);
            map->map[i] = NULL; // Avoid dangling pointer
            ft_printf("Freed map row %d\n", i);
        }
    }
    free(map->map);
    map->map = NULL; // Avoid dangling pointer
    ft_printf("Freed map\n");
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		ft_printf("Freed matrix row %d\n", i);
		i++;
	}
	free(matrix);
	ft_printf("Freed matrix\n");
}
