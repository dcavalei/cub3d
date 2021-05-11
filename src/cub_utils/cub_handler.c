/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcavalei <dcavalei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:04:04 by dcavalei          #+#    #+#             */
/*   Updated: 2021/05/10 14:50:08 by dcavalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_handler(int fd, t_cub *cub)
{
	char	*line;

	while (ft_get_next_line(fd, &line))
	{
		if (!is_empty_line(line))
		{
			if (!store_and_validate(cub, line))
				error_cub(INVALID_CUB, cub);
			if (is_cub_full(cub))
				break ;
		}
		ft_free_machine((void *)(&line));
	}
	ft_free_machine((void *)(&line));
}

void	map_handler(int fd, t_cub *cub)
{
	char	*line;
	int		trigger;

	cub->width = 0;
	trigger = 0;
	while (ft_get_next_line(fd, &line))
	{
		if (is_empty_line(line) && trigger)
			break ;
		else if (!is_empty_line(line))
		{
			trigger = 1;
			tabulation_handler(&line);
			ft_lstadd_back(&(cub->linked_map), ft_lstnew(ft_strdup(line)));
			if (ft_strlen(ft_lstlast(cub->linked_map)->content)
				> (size_t)cub->width)
				cub->width = ft_strlen(ft_lstlast(cub->linked_map)->content);
		}
		free(line);
	}
	free(line);
	cub->height = ft_lstsize(cub->linked_map) - 1;
	create_map(cub, cub->height, cub->width);
	if (!check_map(cub))
		error_cub(INVALID_MAP, cub);
}

void	tabulation_handler(char **line)
{
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	while (ft_strchr(*line, '\t'))
	{
		i = -1;
		while ((*line)[++i])
		{
			if ((*line)[i] == '\t')
			{
				temp = ft_substr(*line, 0, i);
				str = ft_strjoin(temp, "    ");
				free(temp);
				temp = ft_strjoin(str, &(*line)[i + 1]);
				free(*line);
				free(str);
				*line = temp;
			}
		}
	}
}

void	create_map(t_cub *cub, int y, int x)
{
	int	i;

	cub->map = malloc(sizeof(char *) * (y + 1));
	if (!cub->map)
		error_cub(errno, cub);
	cub->map[y] = NULL;
	i = 0;
	while (i < y)
	{
		cub->map[i] = malloc(sizeof(char) * (x + 1));
		if (!cub->map[i])
			error_cub(errno, cub);
		ft_memset(cub->map[i], ' ', x);
		cub->map[i][x] = '\0';
		i++;
	}
	i = -1;
	while (cub->linked_map->next)
	{
		cub->linked_map = cub->linked_map->next;
		ft_memcpy(cub->map[++i], cub->linked_map->content,
			ft_strlen(cub->linked_map->content));
		printf("[%s]\n", cub->map[i]);
	}
}

int	check_map(t_cub *cub)
{
	int	y;
	int	x;

	y = -1;
	while (++y < cub->height)
	{
		x = -1;
		while (++x < cub->width)
		{
			if (!is_valid_char(cub->map[y][x]))
				return (0);
			else if (is_map_border(cub, y, x)
				&& !is_wall_or_space(cub->map[y][x]))
				return (0);
			else if (!is_wall_or_space(cub->map[y][x])
				&& (cub->map[y - 1][x] == SPACE || cub->map[y + 1][x] == SPACE
				|| cub->map[y][x - 1] == SPACE || cub->map[y][x + 1] == SPACE))
				return (0);
			if (is_player(cub->map[y][x])
				&& !set_player(cub, y, x, cub->map[y][x]))
				return (0);
		}
	}
	return (!(cub->player_x == -1 || cub->player_y == -1));
}
