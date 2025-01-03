/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:53:01 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/03 18:51:20 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	count_character(char **matrix, int width, int height, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	while (i < height - 1)
	{
		j = 1;
		while (j < width - 1)
		{
			if (matrix[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static int	is_collectible_present(char **matrix, int width, int height)
{
	if (count_character(matrix, width, height, COLLECTIBLE) >= 1)
		return (1);
	else
		return (-1);
}

static int	is_exit_present(char **matrix, int width, int height)
{
	if (count_character(matrix, width, height, EXIT) == 1)
		return (1);
	else
		return (-1);
}

static int	is_player_present(char **matrix, int width, int height)
{
	if (count_character(matrix, width, height, PLAYER) == 1)
		return (1);
	else
		return (-1);
}

int	is_map_valid(char **matrix, int width, int height)
{
	if (is_collectible_present(matrix, width, height) < 0)
		return (-1);
	if (is_exit_present(matrix, width, height) < 0)
		return (-1);
	if (is_player_present(matrix, width, height) < 0)
		return (-1);
	return (0);
}
