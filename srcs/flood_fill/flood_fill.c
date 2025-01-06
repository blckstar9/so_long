/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:21:44 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/06 20:55:22 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int process_neighbor(t_bfs_params *params, t_point current, t_point direction, int *exit_found)
{
    int	new_x;
	int	new_y;

	new_x = current.x + direction.x;
	new_y = current.y + direction.y;
    if (is_within_bounds(new_x, new_y, params->width, params->height) &&
        !params->visited[new_y][new_x] && params->matrix[new_y][new_x] != WALL)
    {
        params->visited[new_y][new_x] = 1;
        params->queue->data[params->queue->rear++] = (t_point){new_x, new_y};
        if (params->matrix[new_y][new_x] == COLLECTIBLE)
            params->collectibles--;
        if (params->matrix[new_y][new_x] == EXIT)
            *exit_found = 1;
    }
    return (params->collectibles == 0 && *exit_found);
}

static int	bfs_traversal(t_bfs_params *params)
{
    static const t_point	directions[4];
    int						exit_found;
	t_point					current;
	int						i;

	initialize_directions(directions);
	exit_found = 0;
    while (params->queue->front < params->queue->rear)
    {
        current = params->queue->data[params->queue->front++];
		i = -1;
		while (++i < 4)
		{
			if (process_neighbor(params, current, directions[i], &exit_found))
				return (1);
		}
    }
    return (params->collectibles == 0 && exit_found);
}

int is_path_valid(char **matrix, int width, int height, int start_x, int start_y)
{
    int				**visited;
	t_queue			*queue;
	t_bfs_params	params;
	int				result;
	visited = init_visited(width, height);
    if (!visited)
        return (-1);
    queue = initialize_queue(width, height, start_x, start_y);
    if (!queue)
    {
        for (int i = 0; i < height; i++)
            free(visited[i]);
        free(visited);
        return (-1);
    }
    params = init_bfs_params(matrix, width, height, visited, queue);
    visited[start_y][start_x] = 1;
    result = bfs_traversal(&params);
    for (int i = 0; i < height; i++)
        free(visited[i]);
    free(visited);
    free(queue->data);
    free(queue);
    return (result);
}
