/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:34:34 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/06 20:58:22 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL_H
#define FLOOD_FILL_H

#include "so_long.h"

typedef struct s_point
{
	int x;
	int y;
} t_point;

typedef struct s_queue
{
	int front;
	int rear;
	t_point *data;
} t_queue;

typedef struct s_bfs_params
{
	char **matrix;
	int width;
	int height;
	int **visited;
	t_queue *queue;
	int collectibles;
} t_bfs_params;

int is_within_bounds(int x, int y, int width, int height);
int init_visited(int width, int height);
t_point *init_queue(int width, int height, int start_x, int start_y);
void initialize_directions(t_point *directions);
t_bfs_params init_bfs_params(char **matrix, int width, int height, int **visited, t_queue *queue);
#endif