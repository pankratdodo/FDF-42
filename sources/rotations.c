/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 15:51:22 by plettie           #+#    #+#             */
/*   Updated: 2020/03/16 19:27:58 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			rotate_x(t_point *point, double angle)
{
	int			old_y;

	old_y = point->y;
	point->y = old_y * cos(angle) + point->z * sin(angle);
	point->z = -old_y * sin(angle) + point->z * cos(angle);
}

void			rotate_y(t_point *point, double angle)
{
	int			old_x;

	old_x = point->x;
	point->x = old_x * cos(angle) + point->z * sin(angle);
	point->z = -old_x * sin(angle) + point->z * cos(angle);
}

void			rotate_z(t_point *point, double angle)
{
	int			old_y;
	int			old_x;

	old_x = point->x;
	old_y = point->y;
	point->x = -old_y * sin(angle) + old_x * cos(angle);
	point->y = old_y * cos(angle) + old_x * sin(angle);
}

void			copy_point(t_point *dest, t_point *src)
{
	dest->color = src->color;
	dest->x = src->x;
	dest->y = src->y;
	dest->z = src->z;
}

t_point			*rot_po(t_point *point, t_main *data)
{
	t_point		*new_point;

	new_point = NULL;
	if (point && data)
	{
		if (!(new_point = (t_point *)malloc(sizeof(t_point))))
			on_crash(MALLOC_ERR);
		copy_point(new_point, point);
		new_point->x *= data->map.zoom;
		new_point->y *= data->map.zoom;
		new_point->z *= data->map.zoom / 2;
		new_point->x -= data->map.width * data->map.zoom / 2;
		new_point->y -= data->map.height * data->map.zoom / 2;
		rotate_x(new_point, data->rotate.x_angle);
		rotate_y(new_point, data->rotate.y_angle);
		rotate_z(new_point, data->rotate.z_angle);
		if (data->rotate.iso)
			iso(new_point);
		new_point->x += WIDTH / 2 + data->offset.offset_x;
		new_point->y += HEIGHT / 2 + data->offset.offset_y;
	}
	return (new_point);
}
