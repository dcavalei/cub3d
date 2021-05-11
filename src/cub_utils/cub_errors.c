/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:20:25 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/11 11:54:47 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	base_error(int error)
{
	if (error == INVALID_CUB)
		printf ("error: Invalid *.cub file\n");
	else if (error == INVALID_MAP)
		printf ("error: Invalid map\n");
	else if (error == TOO_MANY_ARGUMENTS)
		printf ("error: Too many arguments\n");
	else if (error == errno)
		perror("error");
}

void	error_handler(int error)
{
	base_error(error);
	exit(-1);
}

void	error_cub(int error, t_cub *cub)
{
	if (error == INVALID_MAP)
		free_map(cub);
	free_cub(cub);
	base_error(error);
	exit(1);
}

void	error_after_load(int error, t_data *data, t_cub *cub)
{
	base_error(error);
	free_cub(cub);
	free_map(cub);
	free_data(data);
}
