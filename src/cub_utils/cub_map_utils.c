/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:46:48 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/06 14:20:34 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_map_border(t_cub *cub, int y, int x)
{
	if (y == 0 || x == 0 || y == cub->height - 1 || x == cub->width - 1)
		return (1);
	return (0);
}

int	is_wall_or_space(char c)
{
	if (c == SPACE || c == WALL)
		return (1);
	return (0);
}

int	is_valid_char(char c)
{
	if (c == '0'
		|| c == '1'
		|| c == '2'
		|| c == 'N'
		|| c == 'S'
		|| c == 'E'
		|| c == 'W'
		|| c == ' ')
		return (1);
	return (0);
}

int	set_player(t_cub *cub, int y, int x, char dir)
{
	if (cub->player_y == -1 && cub->player_x == -1)
	{
		cub->player_y = x;
		cub->player_x = y;
		cub->spawn_dir = dir;
		return (1);
	}
	else
		return (0);
}
