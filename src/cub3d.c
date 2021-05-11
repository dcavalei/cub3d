/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:06:04 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/10 17:44:12 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_cub	cub;
	int		fd;

	if (argc > 3)
		error_handler(TOO_MANY_ARGUMENTS);
	fd = cub_init(argv[1], &cub);
	cub_handler(fd, &cub);
	map_handler(fd, &cub);
	close(fd);
	data_setup(&data, &cub, argv);
	if (load_textures(&data, &cub))
		free_cub(&cub);
	else
		error_after_load(errno, &data, &cub);
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		bmp_handler(&data, &cub);
	mlx_hook(data.win, 2, 0, &press_key, &data);
	mlx_hook(data.win, 3, 0, &release_key, &data);
	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}

int	main_loop(t_data *data)
{
	movement_handler(data);
	sort_sprites(data);
	update_data(data);
	draw_buffer(data);
	return (0);
}

void	update_data(t_data *data)
{
	t_vars_storage	v;
	int				x;
	int				i;

	x = -1;
	while (++x < data->res_x)
	{
		calc_init_texture(data, &v, x);
		calc_side_dist(data, &v);
		calc_perp_wall_dist(data, &v);
		calc_line_height(data, &v);
		choose_texture(&v);
		texture_size_adjust(data, &v);
		tex_to_buffer(data, &v, x);
		data->ray_buffer[x] = v.perp_wall_dist;
	}
	i = -1;
	while (++i < data->num_sprites)
	{
		calc_init_sprite(data, &v, i);
		sprite_to_buffer(data, &v);
	}
}

int	color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	atoi_color(char *str)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(str);
	g = ft_atoi(ft_strchr(str, ',') + 1);
	b = ft_atoi(ft_strrchr(str, ',') + 1);
	return (color(0, r, g, b));
}
