/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:31:48 by plettie           #+#    #+#             */
/*   Updated: 2020/03/16 19:30:49 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_app(void *param)
{
	(void)param;
	exit(0);
}

void		initialize_image(t_main *fdf)
{
	t_img	*image;

	image = &fdf->image;
	image->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT - 190);
	image->adr = (int *)mlx_get_data_addr(image->img, &image->bits,
			&image->size_line, &image->endian);
	image->bits /= 8;
}

void		initialize_rotation(t_main *data)
{
	data->rotate.iso = 0;
	data->rotate.x_angle = 0;
	data->rotate.y_angle = 0;
	data->rotate.z_angle = 0;
	data->def_color = 0x000066;
}

void		initialize_offset(t_main *data)
{
	data->offset.offset_x = 0;
	data->offset.offset_y = 0;
}

void		init_struct(t_main *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
	initialize_image(data);
	initialize_rotation(data);
	initialize_offset(data);
	print(data);
	mlx_hook(data->win, 2, 0, key_hook, data);
	mlx_hook(data->win, 17, 0, close_app, data);
	mlx_loop(data->mlx);
}
