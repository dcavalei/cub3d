/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:49:19 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/06 14:53:33 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_init(char *path, t_cub *cub)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_handler(errno);
	cub->resolution = NULL;
	cub->north_texture = NULL;
	cub->south_texture = NULL;
	cub->west_texture = NULL;
	cub->east_texture = NULL;
	cub->sprite_texture = NULL;
	cub->floor_color = NULL;
	cub->ceilling_color = NULL;
	cub->linked_map = ft_lstnew(NULL);
	cub->player_y = -1;
	cub->player_x = -1;
	return (fd);
}

int	is_cub_full(t_cub *cub)
{
	if ((cub->resolution)
		&& (cub->north_texture)
		&& (cub->south_texture)
		&& (cub->west_texture)
		&& (cub->east_texture)
		&& (cub->sprite_texture)
		&& (cub->floor_color)
		&& (cub->ceilling_color))
	{
		printf("Resolution	[%s]\n", cub->resolution);
		printf("North texture	[%s]\n", cub->north_texture);
		printf("South texture	[%s]\n", cub->south_texture);
		printf("West texture	[%s]\n", cub->west_texture);
		printf("East texture	[%s]\n", cub->east_texture);
		printf("Sprite texture	[%s]\n", cub->sprite_texture);
		printf("Floor color	[%s]\n", cub->floor_color);
		printf("Ceilling color	[%s]\n", cub->ceilling_color);
		return (1);
	}
	return (0);
}
