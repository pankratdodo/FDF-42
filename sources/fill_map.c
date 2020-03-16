/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:16:39 by plettie           #+#    #+#             */
/*   Updated: 2020/03/15 16:16:41 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_number(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			result = 0;
		i++;
	}
	if (result)
		result = compare_with_max(str);
	return (result);
}

void		remove_points(t_map *map)
{
	t_point	**points;
	int		y;

	y = 0;
	if (map)
	{
		points = map->points;
		while (y < map->height)
		{
			free(points[y]);
			y++;
		}
		free(points);
	}
}

void		malloc_points(t_map *map)
{
	t_point	**points;
	int		y;

	y = 0;
	if (map)
	{
		if (!(points = (t_point **)malloc(map->height * sizeof(t_point *))))
			on_crash(MALLOC_ERR);
		while (y < map->height)
		{
			if (!(points[y] = (t_point *)malloc(map->width * sizeof(t_point))))
				on_crash(MALLOC_ERR);
			y++;
		}
		map->points = points;
	}
}

int			fill_map_2(t_map *map, char **number, t_point **points, int y)
{
	int		x;

	x = 0;
	while (number[x])
	{
		if (check_number(number[x]))
		{
			points[y][x].x = x;
			points[y][x].y = y;
			points[y][x].z = ft_atoi(number[x]);
		}
		else
		{
			del_double_arr(number);
			remove_points(map);
			return (0);
		}
		x++;
	}
	return (1);
}

int			fill_map(t_map *map, t_lst *list)
{
	char	**number;
	t_point	**points;
	int		y;

	y = 0;
	malloc_points(map);
	points = map->points;
	while (list)
	{
		number = ft_strsplit(list->data, ' ');
		if (!fill_map_2(map, number, points, y))
			return (0);
		y++;
		del_double_arr(number);
		list = list->next;
	}
	return (1);
}
