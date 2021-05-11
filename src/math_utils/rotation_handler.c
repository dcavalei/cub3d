/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:16:35 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/06 14:57:36 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	data->dir_x *= cos(data->rot_speed);
	data->dir_x -= data->dir_y * sin(data->rot_speed);
	data->dir_y *= cos(data->rot_speed);
	data->dir_y += old_dir_x * sin(data->rot_speed);
	data->plane_x *= cos(data->rot_speed);
	data->plane_x -= data->plane_y * sin(data->rot_speed);
	data->plane_y *= cos(data->rot_speed);
	data->plane_y += old_plane_x * sin(data->rot_speed);
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	data->dir_x *= cos(-data->rot_speed);
	data->dir_x -= data->dir_y * sin(-data->rot_speed);
	data->dir_y *= cos(-data->rot_speed);
	data->dir_y += old_dir_x * sin(-data->rot_speed);
	data->plane_x *= cos(-data->rot_speed);
	data->plane_x -= data->plane_y * sin(-data->rot_speed);
	data->plane_y *= cos(-data->rot_speed);
	data->plane_y += old_plane_x * sin(-data->rot_speed);
}

void	spawn_direction(t_data *data)
{
	data->rot_speed = PI;
	if (data->spawn_dir == EAST || data->spawn_dir == WEAST)
		data->rot_speed /= 2;
	if (data->spawn_dir == SOUTH)
		rotate_right(data);
	else if (data->spawn_dir == EAST)
		rotate_right(data);
	else if (data->spawn_dir == WEAST)
		rotate_left(data);
	data->rot_speed = ROTATION_SPEED;
}
