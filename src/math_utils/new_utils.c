/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:17:36 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/10 12:08:50 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	**create_matrix(int height, int width)
{
	int	**buffer;
	int	i;

	buffer = ft_calloc(height, sizeof(int *));
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < height)
	{
		buffer[i] = ft_calloc(width, sizeof(int));
		if (!buffer[i])
			return (NULL);
		i++;
	}
	return (buffer);
}

int	load_image(t_data *data, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	img->ptr = mlx_xpm_file_to_image(data->mlx, path,
			&img->width, &img->height);
	if (!img->ptr)
		return (0);
	img->addr = (int *)mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size_line, &img->endian);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			texture[(img->width * y) + x] = img->addr[(img->width * y) + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img->ptr);
	return (1);
}

/*
**	North	[0]
**	South	[1]
**	East	[2]
**	Weast	[3]
**	Sprite	[4]
*/

int	load_textures(t_data *data, t_cub *cub)
{
	t_img	img;

	if (!load_image(data, data->texture[0], cub->north_texture, &img))
		return (0);
	if (!load_image(data, data->texture[1], cub->south_texture, &img))
		return (0);
	if (!load_image(data, data->texture[2], cub->east_texture, &img))
		return (0);
	if (!load_image(data, data->texture[3], cub->west_texture, &img))
		return (0);
	if (!load_image(data, data->texture[4], cub->sprite_texture, &img))
		return (0);
	return (1);
}
