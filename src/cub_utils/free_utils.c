/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:35:31 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/10 14:51:06 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	free all allocated memmory besides the map
*/

void	free_cub(t_cub *cub)
{
	if (cub->resolution)
		ft_free_machine((void *)(&(cub->resolution)));
	if (cub->north_texture)
		ft_free_machine((void *)(&(cub->north_texture)));
	if (cub->south_texture)
		ft_free_machine((void *)(&(cub->south_texture)));
	if (cub->west_texture)
		ft_free_machine((void *)(&(cub->west_texture)));
	if (cub->east_texture)
		ft_free_machine((void *)(&(cub->east_texture)));
	if (cub->sprite_texture)
		ft_free_machine((void *)(&(cub->sprite_texture)));
	if (cub->floor_color)
		ft_free_machine((void *)(&(cub->floor_color)));
	if (cub->ceilling_color)
		ft_free_machine((void *)(&(cub->ceilling_color)));
	ft_lstclear(&(cub->linked_map), free);
}

void	free_map(t_cub *cub)
{
	int	i;

	if (cub->map)
	{
		i = 0;
		while (cub->map[i])
		{
			ft_free_machine((void *)&(cub->map[i]));
			i++;
		}
		ft_free_machine((void *)&(cub->map));
	}
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->res_y)
	{
		ft_free_machine((void *)(&(data->buffer[i])));
		if (i < TEXTURES_AMOUNT)
			ft_free_machine((void *)(&(data->texture[i])));
		i++;
	}
	ft_free_machine((void *)(&(data->buffer)));
	ft_free_machine((void *)(&(data->texture)));
	ft_free_machine((void *)(&(data->ray_buffer)));
	ft_free_machine((void *)(&(data->sprite)));
	printf("\nProgram closed correctly!\n");
	exit(1);
}	
