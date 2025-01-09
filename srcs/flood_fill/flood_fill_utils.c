/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:33:20 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/09 20:26:13 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	is_within_bounds(int x, int y, int width, int height)
{
	return (x >= 0 && x < width && y >= 0 && y < height);
}

int	**init_visited(int width, int height)
{
	int	**visited;
	int	i;

	visited = (int **)ft_calloc(height, sizeof(int *));
	if (!visited)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		visited[i] = (int *)ft_calloc(width, sizeof(int));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
	}
	return (visited);
}

t_queue	*init_queue(int width, int height, int start_x, int start_y)
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

void	free_resources(int **visited, int height, t_queue *queue)
{
	int	i;

	i = -1;
	while (++i < height)
		free(visited[i]);
	free(visited);
	free(queue->data);
	free(queue);
}
