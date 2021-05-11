/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:01:49 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/06 14:56:47 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	store_and_validate(t_cub *cub, char *line)
{
	int	ret;

	ret = 0;
	while (ft_isspace(*line))
		line++;
	if (!ft_strncmp(line, "R", 1))
		ret = get_resolution(cub, line + 1);
	else if (!ft_strncmp(line, "NO", 2)
		|| !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2)
		|| !ft_strncmp(line, "EA", 2))
		ret = get_wall_texture(cub, line);
	else if (!ft_strncmp(line, "S", 1))
		ret = get_sprite_texture(cub, line + 1);
	else if (!ft_strncmp(line, "F", 1)
		|| !ft_strncmp(line, "C", 1))
		ret = get_floor_or_ceilling(cub, line);
	return (ret);
}

int	get_resolution(t_cub *cub, char *line)
{
	int	i;

	if (cub->resolution)
		return (0);
	while (ft_isspace(*line))
		line++;
	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	while (ft_isdigit(line[i]))
		i++;
	cub->resolution = ft_substr(line, 0, i);
	if (!is_ending_correctly(&line[i]))
		return (0);
	return (check_resolution(cub->resolution));
}

int	get_wall_texture(t_cub *cub, char *line)
{
	int	i;
	int	j;

	if ((ft_strncmp(line, "NO", 2) == 0 && cub->north_texture)
		|| (ft_strncmp(line, "SO", 2) == 0 && cub->south_texture)
		|| (ft_strncmp(line, "WE", 2) == 0 && cub->west_texture)
		|| (ft_strncmp(line, "EA", 2) == 0 && cub->east_texture))
		return (0);
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	j = i;
	while (ft_isprint(line[j]) && !ft_isspace(line[j]))
		j++;
	if (ft_strncmp(line, "NO", 2) == 0)
		cub->north_texture = ft_substr(line, i, j);
	else if (ft_strncmp(line, "SO", 2) == 0)
		cub->south_texture = ft_substr(line, i, j);
	else if (ft_strncmp(line, "WE", 2) == 0)
		cub->west_texture = ft_substr(line, i, j);
	else if (ft_strncmp(line, "EA", 2) == 0)
		cub->east_texture = ft_substr(line, i, j);
	if (!is_ending_correctly(&line[j]))
		return (0);
	return (1);
}

int	get_sprite_texture(t_cub *cub, char *line)
{
	int	i;

	if (cub->sprite_texture)
		return (0);
	while (ft_isspace(*line))
		line++;
	i = 0;
	while (ft_isprint(line[i]) && !ft_isspace(line[i]))
		i++;
	cub->sprite_texture = ft_substr(line, 0, i);
	if (!is_ending_correctly(&line[i]))
		return (0);
	return (1);
}

int	get_floor_or_ceilling(t_cub *cub, char *line)
{
	int	i;
	int	j;

	if ((ft_strncmp(line, "F", 1) == 0 && cub->floor_color)
		|| (ft_strncmp(line, "C", 1) == 0 && cub->ceilling_color))
		return (0);
	i = 1;
	while (ft_isspace(line[i]))
		i++;
	j = i;
	while (ft_isprint(line[j]))
		j++;
	if (ft_strncmp(line, "F", 1) == 0)
		cub->floor_color = ft_substr(line, i, j);
	if (ft_strncmp(line, "C", 1) == 0)
		cub->ceilling_color = ft_substr(line, i, j);
	if (!is_ending_correctly(&line[j]))
		return (0);
	if (ft_strncmp(line, "F", 1) == 0 && cub->floor_color)
		return (check_floor_or_ceilling(cub->floor_color));
	else
		return (check_floor_or_ceilling(cub->ceilling_color));
}
