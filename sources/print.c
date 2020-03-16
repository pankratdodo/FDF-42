/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:01:50 by plettie           #+#    #+#             */
/*   Updated: 2020/03/16 19:54:13 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			my_abs(int num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}

void		draw_line_2(t_point *first, t_point *last, int *adr, t_default *def)
{
	int		e2;

	while (1)
	{
		if (first->x > 0 && first->x < WIDTH &&
				first->y > 0 && first->y < HEIGHT)
			adr[first->x + first->y * WIDTH] = first->color;
		if (first->x == last->x && first->y == last->y)
			break ;
		e2 = 2 * def->err;
		if (e2 >= def->y)
		{
			def->err += def->y;
			first->x += def->sx;
		}
		if (e2 <= def->x)
		{
			def->err += def->x;
			first->y += def->sy;
		}
	}
}

void		draw_line(t_point *first, t_point *last, int *adr, t_default *def)
{
	def->x = my_abs(last->x - first->x);
	def->y = -my_abs(last->y - first->y);
	def->sx = first->x < last->x ? 1 : -1;
	def->sy = first->y < last->y ? 1 : -1;
	def->err = def->x + def->y;
	draw_line_2(first, last, adr, def);
	free(first);
	free(last);
}

void		ft_menu(t_main *data)
{
	mlx_string_put(data->mlx, data->win, 10, 1010, 0x808080,
			"Push '1', '2', '3', '4', to change color");
	mlx_string_put(data->mlx, data->win, 10, 1030, 0x808080,
			"Push 'ESC' to exit");
	mlx_string_put(data->mlx, data->win, 10, 1050, 0x808080,
			"Push 'LEFT' and 'RIGHT' to move on axis X");
	mlx_string_put(data->mlx, data->win, 10, 1070, 0x808080,
			"Push 'UP' and 'DOWN' to move on axis Y");
	mlx_string_put(data->mlx, data->win, 10, 1090, 0x808080,
			"Push '+' and '-' to change zoom");
	mlx_string_put(data->mlx, data->win, 10, 1110, 0x808080,
			"Push 'I' to change  projection");
	mlx_string_put(data->mlx, data->win, 10, 1130, 0x808080,
			"Push 'Q' and 'E' to rotate on axis X");
	mlx_string_put(data->mlx, data->win, 10, 1150, 0x808080,
			"Push 'A' and 'D' to rotate on axis Y");
	mlx_string_put(data->mlx, data->win, 10, 1170, 0x808080,
			"Push 'Z' and 'C' to rotate on axis Z");
}

void		print(t_main *data)
{
	int		x;
	int		y;
	t_point	**points;

	y = 0;
	points = data->map.points;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			points[y][x].color = (data->def_color + points[y][x].z) * 100;
			if (y != data->map.height - 1)
				draw_line(rot_po(&points[y][x], data), rot_po(&points[y + 1][x],
						data), data->image.adr, &data->def);
			if (x != data->map.width - 1)
				draw_line(rot_po(&points[y][x], data), rot_po(&points[y][x + 1],
						data), data->image.adr, &data->def);
			x++;
		}
		y++;
	}
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
	ft_menu(data);
}
