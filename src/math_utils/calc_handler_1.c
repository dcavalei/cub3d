/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_handler_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:21:10 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/07 11:34:33 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_size_adjust(t_data *data, t_vars_storage *v)
{
	if (v->side == 0)
		v->wall_x = data->pos_y + v->perp_wall_dist * v->raydir_y;
	else
		v->wall_x = data->pos_x + v->perp_wall_dist * v->raydir_x;
	v->wall_x -= floor(v->wall_x);
	v->tex_x = (int)(v->wall_x * (double)TEX_WIDTH);
	if (v->side == 0 && v->raydir_x > 0)
		v->tex_x = TEX_WIDTH - v->tex_x - 1;
	if (v->side == 1 && v->raydir_y < 0)
		v->tex_x = TEX_WIDTH - v->tex_x - 1;
	v->step = 1.0 * TEX_HEIGHT / v->line_height;
	v->tex_pos = (v->draw_start - data->res_y
			/ 2 + v->line_height / 2) * v->step;
	if (v->draw_start > data->res_y || v->draw_start < 0)
		v->draw_start = data->res_y;
	if (v->draw_end > data->res_y || v->draw_end < 0)
		v->draw_end = data->res_y;
}

void	tex_to_buffer(t_data *data, t_vars_storage *v, int x)
{
	int	y;

	y = 0;
	while (y < v->draw_start)
	{
		data->buffer[y][x] = data->ceilling_color;
		y++;
	}
	while (y < v->draw_end)
	{
		v->tex_y = (int)v->tex_pos & (TEX_HEIGHT - 1);
		v->tex_pos += v->step;
		v->color = data->texture[v->tex_num][TEX_HEIGHT * v->tex_y + v->tex_x];
		data->buffer[y][x] = v->color;
		y++;
	}
	while (y < data->res_y)
	{
		data->buffer[y][x] = data->floor_color;
		y++;
	}
}

static void	edge_handler(t_data *data, t_vars_storage *v)
{
	if (v->draw_start_y < 0)
		v->draw_start_y = 0;
	v->draw_end_y = v->sprite_height / 2 + data->res_y / 2 + v->v_move_screen;
	if (v->draw_end_y >= data->res_y)
		v->draw_end_y = data->res_y - 1;
	v->sprite_width = (int)fabs((data->res_y / v->transform_y) / U_DIV);
	v->draw_start_x = -v->sprite_width / 2 + v->sprite_screen_x;
	if (v->draw_start_x < 0)
		v->draw_start_x = 0;
	v->draw_end_x = v->sprite_width / 2 + v->sprite_screen_x;
	if (v->draw_end_x >= data->res_x)
		v->draw_end_x = data->res_x - 1;
}

void	calc_init_sprite(t_data *data, t_vars_storage *v, int i)
{
	v->sprite_x = (double)data->sprite[i].pos_x - data->pos_x + 0.5;
	v->sprite_y = (double)data->sprite[i].pos_y - data->pos_y + 0.5;
	v->inv_det = 1.0 / (data->plane_x
			* data->dir_y - data->dir_x * data->plane_y);
	v->transform_x = data->dir_y
		* v->sprite_x - data->dir_x * v->sprite_y;
	v->transform_y = -data->plane_y
		* v->sprite_x + data->plane_x * v->sprite_y;
	v->sprite_screen_x = (int)((data->res_x / 2)
			* (1 + v->transform_x / v->transform_y));
	v->v_move_screen = (int)(V_MOVE / v->transform_y);
	v->sprite_height = (int)fabs((data->res_y
				/ v->transform_y) / V_DIV);
	v->draw_start_y = -v->sprite_height
		/ 2 + data->res_y / 2 + v->v_move_screen;
	edge_handler(data, v);
}

void	sprite_to_buffer(t_data *data, t_vars_storage *v)
{
	int	y;

	v->stripe = v->draw_start_x;
	while (v->stripe < v->draw_end_x)
	{
		v->tex_x = ((int)(v->stripe - (-v->sprite_width / 2
						+ v->sprite_screen_x))) * TEX_WIDTH / v->sprite_width;
		if (v->transform_y > 0 && v->stripe > 0 && v->stripe
			< data->res_x && v->transform_y < data->ray_buffer[v->stripe])
		{
			y = v->draw_start_y;
			while (y < v->draw_end_y)
			{
				v->d = (y - v->v_move_screen) * 256 - data->res_y
					* 128 + v->sprite_height * 128;
				v->tex_y = ((v->d * TEX_HEIGHT) / v->sprite_height) / 256;
				v->color = data->texture[4][TEX_WIDTH * v->tex_y + v->tex_x];
				if ((v->color & 0x00FFFFFF) != 0)
					data->buffer[y][v->stripe] = v->color;
				y++;
			}
		}
		v->stripe++;
	}
}
