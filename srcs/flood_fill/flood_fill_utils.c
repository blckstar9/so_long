/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:33:20 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/06 20:56:15 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	is_within_bounds(int x, int y, int width, int height)
{
	return (x >= 0 && x < width && y >= 0 && y < height);
}

int	init_visited(int width, int height)
{
	int	**visited;
	int	i;

	visited = (int **)ft_calloc(sizeof(int *), height);
	if (!visited)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		visited[i] = (int *)ft_calloc(sizeof(int), width);
		if (!visited[i])
			return (NULL);
	}
	return (visited);
}

t_point	*init_queue(int width, int height, int start_x, int start_y)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->data = (t_point *)malloc(width * height * sizeof(t_point));
	if (!queue->data)
	{
		free(queue);
		return (NULL);
	}
	queue->front = 0;
	queue->rear = 0;
	queue->data[queue->rear++] = (t_point){start_x, start_y};
	return (queue);
}

void	initialize_directions(t_point *directions)
{
	directions[0] = (t_point){0, 1};
	directions[1] = (t_point){1, 0};
	directions[2] = (t_point){0, -1};
	directions[3] = (t_point){-1, 0};
}

t_bfs_params	init_bfs_params(char **matrix, int width, int height, int **visited, t_queue *queue)
{
    t_bfs_params	params;

	params.matrix = matrix;
	params.width = width;
	params.height = height;
	params.visited = visited;
	params.queue = queue;
	params.collectibles = count_character(matrix, width, height, COLLECTIBLE);
	return (params);
}
