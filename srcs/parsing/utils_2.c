/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:53:01 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/03 19:35:44 by aybelaou         ###   ########.fr       */
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
    int count = count_character(matrix, width, height, COLLECTIBLE);
    ft_printf("Number of collectibles: %d\n", count);
    if (count >= 1)
        return (1);
    else
        return (-1);
}

static int	is_exit_present(char **matrix, int width, int height)
{
    int count = count_character(matrix, width, height, EXIT);
    ft_printf("Number of exits: %d\n", count);
    if (count == 1)
        return (1);
    else
        return (-1);
}

static int	is_player_present(char **matrix, int width, int height)
{
    int count = count_character(matrix, width, height, PLAYER);
    ft_printf("Number of players: %d\n", count);
    if (count == 1)
        return (1);
    else
        return (-1);
}

int	is_map_valid(char **matrix, int width, int height)
{
    ft_printf("Validating map...\n");
    if (is_collectible_present(matrix, width, height) < 0)
    {
        ft_printf("Invalid map: No collectibles\n");
        return (-1);
    }
    if (is_exit_present(matrix, width, height) < 0)
    {
        ft_printf("Invalid map: Incorrect number of exits\n");
        return (-1);
    }
    if (is_player_present(matrix, width, height) < 0)
    {
        ft_printf("Invalid map: Incorrect number of players\n");
        return (-1);
    }
    ft_printf("Map is valid\n");
    return (0);
}
