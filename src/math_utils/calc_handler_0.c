/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_handler_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:18:30 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/06 14:58:21 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_init_texture(t_data *data, t_vars_storage *v, int x)
{
	v->camera_x = 2 * x / (double)data->res_x - 1;
	v->raydir_x = data->dir_x + data->plane_x * v->camera_x;
	v->raydir_y = data->dir_y + data->plane_y * v->camera_x;
	v->map_x = (int)data->pos_x;
	v->map_y = (int)data->pos_y;
	v->delta_dist_x = fabs(1 / v->raydir_x);
	v->delta_dist_y = fabs(1 / v->raydir_y);
}

void	calc_side_dist(t_data *data, t_vars_storage *v)
{
	if (v->raydir_x < 0)
	{
		v->step_x = -1;
		v->side_dist_x = (data->pos_x - v->map_x) * v->delta_dist_x;
	}
	else
	{
		v->step_x = 1;
		v->side_dist_x = (v->map_x + 1.0 - data->pos_x) * v->delta_dist_x;
	}
	if (v->raydir_y < 0)
	{
		v->step_y = -1;
		v->side_dist_y = (data->pos_y - v->map_y) * v->delta_dist_y;
	}
	else
	{
		v->step_y = 1;
		v->side_dist_y = (v->map_y + 1.0 - data->pos_y) * v->delta_dist_y;
	}
}

void	calc_perp_wall_dist(t_data *data, t_vars_storage *v)
{
	double	val_holder_x;
	double	val_holder_y;

	while (data->map[v->map_x][v->map_y] != WALL)
	{
		if (v->side_dist_x < v->side_dist_y)
		{
			v->side_dist_x += v->delta_dist_x;
			v->map_x += v->step_x;
			v->side = 0;
		}
		else
		{
			v->side_dist_y += v->delta_dist_y;
			v->map_y += v->step_y;
			v->side = 1;
		}
	}
	val_holder_x = v->map_x - data->pos_x + (1 - v->step_x) / 2;
	val_holder_y = v->map_y - data->pos_y + (1 - v->step_y) / 2;
	if (v->side == 0)
		v->perp_wall_dist = val_holder_x / v->raydir_x;
	else
		v->perp_wall_dist = val_holder_y / v->raydir_y;
}

void	calc_line_height(t_data *data, t_vars_storage *v)
{
	v->line_height = (int)(data->res_y / v->perp_wall_dist);
	v->draw_start = -v->line_height / 2 + data->res_y / 2;
	if (v->draw_start < 0)
		v->draw_start = 0;
	v->draw_end = v->line_height / 2 + data->res_y / 2;
	if (v->draw_end >= data->res_y)
		v->draw_end = data->res_y - 1;
}

void	choose_texture(t_vars_storage *v)
{
	if (v->side == 0)
	{
		if (v->raydir_x > 0)
			v->tex_num = 1;
		else
			v->tex_num = 0;
	}
	else
	{
		if (v->raydir_y > 0)
			v->tex_num = 2;
		else
			v->tex_num = 3;
	}
}
