/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:06:48 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/11 12:06:12 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_ending_correctly(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (*line)
		return (0);
	return (1);
}

int	check_resolution(char *line)
{
	int	num;

	if (*line == 0)
		return (0);
	num = ft_atoi(line);
	if (num <= 0 || num > MAX_RESOLUTION_X)
		return (0);
	while (ft_isdigit(*line))
		line++;
	while (ft_isspace(*line))
		line++;
	num = ft_atoi(line);
	if (num <= 0 || num > MAX_RESOLUTION_Y)
		return (0);
	return (1);
}

int	check_floor_or_ceilling(char *line)
{
	int	num;
	int	counter;

	num = 0;
	counter = 0;
	while (*line)
	{
		if ((ft_isdigit(*line) || *line == ',') && counter <= 2)
		{
			if (ft_isdigit(*line) && ft_atoi(line) > 255)
				return (0);
			else if (*line == ',')
			{
				if (!ft_isdigit(*(line + 1)))
					return (0);
				counter++;
			}
			line++;
		}
		else
			return (0);
	}
	return (1);
}

int	is_empty_line(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		return (1);
	return (0);
}
