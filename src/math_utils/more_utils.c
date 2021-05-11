/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:07:00 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/10 14:48:19 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites(t_data *data)
{
	int	i;
	int	tmp_1;
	int	tmp_2;

	i = -1;
	while (++i < data->num_sprites - 1)
	{
		tmp_1 = hypot((data->pos_x - data->sprite[i].pos_x),
				(data->pos_y - data->sprite[i].pos_y));
		tmp_2 = hypot((data->pos_x - data->sprite[i + 1].pos_x),
				(data->pos_y - data->sprite[i + 1].pos_y));
		if (tmp_1 < tmp_2)
		{
			tmp_1 = data->sprite[i].pos_y;
			tmp_2 = data->sprite[i].pos_x;
			data->sprite[i].pos_y = data->sprite[i + 1].pos_y;
			data->sprite[i].pos_x = data->sprite[i + 1].pos_x;
			data->sprite[i + 1].pos_y = tmp_1;
			data->sprite[i + 1].pos_x = tmp_2;
			sort_sprites(data);
		}
	}
}

void	draw_buffer(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->res_y)
	{
		x = -1;
		while (++x < data->res_x)
			data->img.addr[y * data->res_x + x] = data->buffer[y][x];
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}

int	press_key(int key, t_data *data)
{
	if (key == A)
		data->key.a = 1;
	if (key == S)
		data->key.s = 1;
	if (key == D)
		data->key.d = 1;
	if (key == W)
		data->key.w = 1;
	if (key == LEFT_ARROW)
		data->key.left = 1;
	if (key == RIGHT_ARROW)
		data->key.right = 1;
	if (key == ESC)
		free_data(data);
	return (0);
}

int	release_key(int key, t_data *data)
{
	if (key == A)
		data->key.a = 0;
	if (key == S)
		data->key.s = 0;
	if (key == D)
		data->key.d = 0;
	if (key == W)
		data->key.w = 0;
	if (key == LEFT_ARROW)
		data->key.left = 0;
	if (key == RIGHT_ARROW)
		data->key.right = 0;
	return (0);
}
