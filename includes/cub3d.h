/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:00:48 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/10 15:00:55 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "macros.h"
# include "structs.h"

/*
**	cub_utils/cub_errors.c
*/

void		error_handler(int error);
void		error_cub(int error, t_cub *cub);
void		error_after_load(int error, t_data *data, t_cub *cub);

/*
**  cub_utils/cub_handler.c
*/

void		cub_handler(int fd, t_cub *cub);
void		map_handler(int fd, t_cub *cub);
void		tabulation_handler(char **line);
void		create_map(t_cub *cub, int y, int x);
int			check_map(t_cub *cub);

/*
**  cub_utils/cub_map_utils.c
*/

int			is_player(char c);
int			is_map_border(t_cub *cub, int y, int x);
int			is_wall_or_space(char c);
int			is_valid_char(char c);
int			set_player(t_cub *cub, int y, int x, char dir);

/*
**	cub_utils/cub_utils_0.c
*/

int			cub_init(char *path, t_cub *cub);
int			is_cub_full(t_cub *cub);

/*
**	cub_utils/free_utils.c
*/

void		free_cub(t_cub *cub);
void		free_map(t_cub *cub);
void		free_data(t_data *data);

/*
**	cub_utils/parsing_utils.c
*/

int			store_and_validate(t_cub *cub, char *line);
int			get_resolution(t_cub *cub, char *line);
int			get_wall_texture(t_cub *cub, char *line);
int			get_sprite_texture(t_cub *cub, char *line);
int			get_floor_or_ceilling(t_cub *cub, char *line);

/*
**	cub_utils/parsing_validate.c
*/

int			is_ending_correctly(char *line);
int			check_resolution(char *line);
int			check_floor_or_ceilling(char *line);
int			is_empty_line(char *line);

/* ------------ */

void		data_setup(t_data *data, t_cub *cub, char **argv);
void		calc_init_texture(t_data *data, t_vars_storage *v, int x);
void		calc_side_dist(t_data *data, t_vars_storage *v);
void		calc_perp_wall_dist(t_data *data, t_vars_storage *v);
void		calc_line_height(t_data *data, t_vars_storage *v);
void		choose_texture(t_vars_storage *v);
void		texture_size_adjust(t_data *data, t_vars_storage *v);
void		tex_to_buffer(t_data *data, t_vars_storage *v, int x);
void		calc_init_sprite(t_data *data, t_vars_storage *v, int i);
void		sprite_to_buffer(t_data *data, t_vars_storage *v);
void		cub_to_data(t_cub *cub, t_data *data);
void		keys_init(t_data *data);
void		update_data(t_data *data);
int			main_loop(t_data *data);
int			press_key(int key, t_data *data);
int			release_key(int key, t_data *data);
void		movement_handler(t_data *data);
int			color(int t, int r, int g, int b);
int			atoi_color(char *str);
void		draw_buffer(t_data *data);
void		paint_image(int color, t_img *image, int x, int y);
int			**create_matrix(int height, int width);
int			load_image(t_data *data, int *texture, char *path, t_img *img);
int			load_textures(t_data *data, t_cub *cub);
void		do_sprite_array(t_data *data);
void		sprite_counter(t_data *data);
void		spawn_direction(t_data *data);
void		move_front(t_data *data);
void		move_back(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);
void		rotate_left(t_data *data);
void		rotate_right(t_data *data);
void		sort_sprites(t_data *data);
void		bmp_handler(t_data *data, t_cub *cub);

#endif
