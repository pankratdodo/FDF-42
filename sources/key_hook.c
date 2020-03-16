/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:32:05 by plettie           #+#    #+#             */
/*   Updated: 2020/03/10 18:32:09 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			compare_with_max(char *str)
{
	int		result;

	result = 1;
	if (*str == '-' || *str == '+')
		str++;
	if (ft_strlen(str) > ft_strlen("2147483648"))
		result = 0;
	else if (ft_strlen(str) == ft_strlen("2147483648"))
		if (ft_strcmp(str, "2147483647") >= 0)
			result = 0;
	return (result);
}

void		change_color(int key, t_main *data)
{
	if (key == KEY_1)
		data->def_color = 0x55004;
	else if (key == KEY_2)
		data->def_color = 0x4C0099;
	else if (key == KEY_3)
		data->def_color = 0x66033;
	else if (key == KEY_4)
		data->def_color = 0x000066;
}

void		clear_img(t_main *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->image.adr[x + y * WIDTH] = 0;
			x++;
		}
		y++;
	}
}

void		ft_destroy(t_main *data)
{
	t_img *image;

	image = &data->image;
	mlx_destroy_image(data->mlx, image->img);
	mlx_destroy_window(data->mlx, data->win);
	remove_points(&data->map);
	exit(0);
}

int			key_hook(int key, void *param)
{
	if (key == ESCAPE)
		ft_destroy(param);
	clear_img(param);
	if (key == KEY_LEFT || key == KEY_RIGHT
	|| key == KEY_UP || key == KEY_DOWN)
		change_offset(key, param);
	if (key == KEY_ZOOM_DEC || key == KEY_ZOOM_INC)
		change_zoom(key, param);
	if (key == KEY_Q || key == KEY_E
		|| key == KEY_A || key == KEY_D
		|| key == KEY_Z || key == KEY_C
		|| key == KEY_ISO)
		change_angle(key, param);
	if (key == KEY_1 || key == KEY_2 || key == KEY_3 ||
		key == KEY_4)
		change_color(key, param);
	print(param);
	return (0);
}
