/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:32:16 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/11 12:13:48 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keys_init(t_data *data)
{
	data->key.a = 0;
	data->key.s = 0;
	data->key.d = 0;
	data->key.w = 0;
	data->key.left = 0;
	data->key.right = 0;
}

void	data_setup(t_data *data, t_cub *cub, char **argv)
{
	cub_to_data(cub, data);
	keys_init(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->res_x, data->res_y, *argv);
	data->img.ptr = mlx_new_image(data->mlx, data->res_x, data->res_y);
	data->img.addr = (int *)mlx_get_data_addr(data->img.ptr, &data->img.bpp,
			&data->img.size_line, &data->img.endian);
	data->dir_x = -1.0;
	data->dir_y = 0.0;
	data->plane_x = 0.0;
	data->plane_y = 0.66;
	data->move_speed = MOVEMENT_SPEED;
	data->rot_speed = ROTATION_SPEED;
	data->buffer = create_matrix(data->res_y, data->res_x);
	data->texture = create_matrix(TEXTURES_AMOUNT, TEX_HEIGHT * TEX_WIDTH);
	data->ray_buffer = ft_calloc(data->res_x, sizeof(int));
	sprite_counter(data);
	do_sprite_array(data);
	spawn_direction(data);
}

void	do_sprite_array(t_data *data)
{
	int			x;
	int			y;
	int			i;
	t_sprite	sprite;

	data->sprite = malloc(sizeof(t_sprite) * (data->num_sprites));
	if (!data->sprite)
		error_handler(errno);
	i = -1;
	y = -1;
	while (++y < data->map_height)
	{
		x = -1;
		while (++x < data->map_width)
		{
			if (data->map[y][x] == SPRITE)
			{
				sprite.pos_x = y;
				sprite.pos_y = x;
				data->sprite[++i] = sprite;
			}
		}
	}
}

void	sprite_counter(t_data *data)
{
	int	x;
	int	y;

	data->num_sprites = 0;
	y = -1;
	while (++y < data->map_height)
	{
		x = -1;
		while (++x < data->map_width)
		{
			if (data->map[y][x] == SPRITE)
				data->num_sprites += 1;
		}
	}
}

void	cub_to_data(t_cub *cub, t_data *data)
{
	data->res_x = ft_atoi(cub->resolution);
	data->res_y = ft_atoi(ft_strrchr(cub->resolution, ' ') + 1);
	data->map_width = cub->width;
	data->map_height = cub->height;
	data->floor_color = atoi_color(cub->floor_color);
	data->ceilling_color = atoi_color(cub->ceilling_color);
	data->map = cub->map;
	data->pos_x = cub->player_x + 0.5;
	data->pos_y = cub->player_y + 0.5;
	data->spawn_dir = cub->spawn_dir;
}
