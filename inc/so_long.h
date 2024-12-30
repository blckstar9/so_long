/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:52:34 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/30 16:32:43 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <X11/X.h>
#include <X11/keysym.h>
#include <assert.h>
#include <fcntl.h>
#include <stdbool.h>
#include "../minilibx-linux/mlx.h"
#include "hooks.h"
#include "../libft/inc/gnl_inc/get_next_line.h"
#include "../libft/inc/libft_inc/libft.h"
#include "../libft/inc/printf_inc/ft_printf.h"

#define W_HEIGHT 1080
#define W_WIDTH 1920
# define TILE_SIZE 64
# define WALL '1'
# define EMPTY_SPACE '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}	t_map;

#endif