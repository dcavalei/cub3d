/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:14:40 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/10 15:02:57 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
**	.cub file related structs
*/

typedef struct s_vars_storage
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	int			color;
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			v_move_screen;
	int			sprite_height;
	int			sprite_width;
	int			draw_start_y;
	int			draw_start_x;
	int			draw_end_y;
	int			draw_end_x;
	int			stripe;
	int			d;
}				t_vars_storage;

typedef struct s_cub
{
	char		*resolution;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*sprite_texture;
	char		*floor_color;
	char		*ceilling_color;

	char		spawn_dir;
	t_list		*linked_map;
	int			height;
	int			width;
	char		**map;
	int			player_y;
	int			player_x;
}				t_cub;

typedef struct s_img
{
	void	*ptr;
	int		*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_sprite
{
	int			pos_x;
	int			pos_y;
}				t_sprite;

typedef struct s_key
{
	int			a;
	int			s;
	int			d;
	int			w;
	int			left;
	int			right;
}				t_key;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	int			spawn_dir;
	int			map_width;
	int			map_height;
	int			**buffer;
	int			*ray_buffer;
	int			**texture;
	int			num_sprites;
	t_sprite	*sprite;
	t_key		key;
	int			floor_color;
	int			ceilling_color;
	int			map_x;
	int			map_y;
	int			res_x;
	int			res_y;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;	
	t_img		img;
}				t_data;

#endif
