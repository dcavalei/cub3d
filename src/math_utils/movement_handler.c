/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:06:27 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/10 12:59:35 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_front(t_data *data)
{
	double	current_x;
	double	current_y;
	double	moved_x;
	double	moved_y;

	current_x = data->pos_x;
	current_y = data->pos_y;
	moved_x = data->pos_x + data->dir_x * data->move_speed;
	moved_y = data->pos_y + data->dir_y * data->move_speed;
	if (!is_wall_or_space(data->map[(int)moved_x][(int)current_y]))
		data->pos_x = moved_x;
	if (!is_wall_or_space(data->map[(int)current_x][(int)moved_y]))
		data->pos_y = moved_y;
}

void	move_left(t_data *data)
{
	double	current_x;
	double	current_y;
	double	moved_x;
	double	moved_y;

	current_x = data->pos_x;
	current_y = data->pos_y;
	moved_x = data->pos_x - data->dir_y * data->move_speed;
	moved_y = data->pos_y + data->dir_x * data->move_speed;
	if (data->map[(int)moved_x][(int)current_y] != WALL)
		data->pos_x = moved_x;
	if (data->map[(int)current_x][(int)moved_y] != WALL)
		data->pos_y = moved_y;
}

void	move_right(t_data *data)
{
	double	current_x;
	double	current_y;
	double	moved_x;
	double	moved_y;

	current_x = data->pos_x;
	current_y = data->pos_y;
	moved_x = data->pos_x + data->dir_y * data->move_speed;
	moved_y = data->pos_y - data->dir_x * data->move_speed;
	if (data->map[(int)moved_x][(int)current_y] != WALL)
		data->pos_x = moved_x;
	if (data->map[(int)current_x][(int)moved_y] != WALL)
		data->pos_y = moved_y;
}

void	move_back(t_data *data)
{
	double	current_x;
	double	current_y;
	double	moved_x;
	double	moved_y;

	current_x = data->pos_x;
	current_y = data->pos_y;
	moved_x = data->pos_x - data->dir_x * data->move_speed;
	moved_y = data->pos_y - data->dir_y * data->move_speed;
	if (data->map[(int)moved_x][(int)current_y] != WALL)
		data->pos_x = moved_x;
	if (data->map[(int)current_x][(int)moved_y] != WALL)
		data->pos_y = moved_y;
}

void	movement_handler(t_data *data)
{
	if (data->key.a)
		move_left(data);
	if (data->key.s)
		move_back(data);
	if (data->key.d)
		move_right(data);
	if (data->key.w)
		move_front(data);
	if (data->key.left)
		rotate_left(data);
	if (data->key.right)
		rotate_right(data);
}
