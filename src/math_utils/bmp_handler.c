/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:45:37 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/10 14:52:39 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef union u_itobc
{
	uint32_t	num;
	uint8_t		str[4];
}				t_itobc;

void	itoa_binary(unsigned char *start, int value)
{
	t_itobc			num;

	num.num = value;
	start[0] = num.str[0];
	start[1] = num.str[1];
	start[2] = num.str[2];
	start[3] = num.str[3];
}

static int	write_bmp_header(int fd, t_data *data)
{
	unsigned char	header[54];

	ft_memset(header, 0, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	itoa_binary(header + 2, 54 + data->res_x * data->res_y * 3);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	itoa_binary(header + 18, data->res_x);
	itoa_binary(header + 22, data->res_y);
	header[27] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	return (write(fd, header, 54));
}

void	bmp_handler(t_data *data, t_cub *cub)
{
	int	fd;
	int	y;
	int	x;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY, 0777);
	if (fd < 0 || write_bmp_header(fd, data) < 0)
		error_after_load(errno, data, cub);
	main_loop(data);
	y = data->res_y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->res_x)
		{
			write(fd, &data->buffer[y][x], 3);
			x++;
		}
		y--;
	}
	close(fd);
	free_map(cub);
	free_data(data);
}
