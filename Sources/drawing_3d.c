/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:20:51 by misaev            #+#    #+#             */
/*   Updated: 2022/02/01 12:06:57 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

static	void	draw_in_sec_img_1(t_data *data)
{
	if (fabs(data->x_2 - data->player_x) >= fabs(data->y_2 - data->player_y))
		data->wall->length = fabs(data->player_x
				- data->x_2) / cos(convert_ang_rad(data->angle));
	else
		data->wall->length = fabs(data->player_y
				- data->y_2) / sin(convert_ang_rad(data->angle));
	data->wall->distance_to_slice = data->wall->length;
	data->wall->correct_distance = data->wall->distance_to_slice
		* cos(convert_ang_rad(data->save_angle - data->angle));
	data->wall->actual_slice_height = 32.0;
	data->wall->distance_project_plan = fabs(SCREEN_W / 2.0)
		/ tan(convert_ang_rad(30.0));
	data->wall->draw_height = fabs(data->wall->actual_slice_height
			/ data->wall->correct_distance) * data->wall->distance_project_plan;
}

static	void	draw_in_sec_img_2(t_data *data, int j, double draw)
{
	int	top;
	int	bottom;
	int	color;

	bottom = 1050;
	top = 0;
	while (top < 540 && bottom > 10)
	{
		my_mlx_pixel_put(data, j, top, convert_rbg(data, 2));
		top++;
		my_mlx_pixel_put(data, j, bottom, convert_rbg(data, 1));
		bottom--;
	}
	top = 540 - draw;
	bottom = 540 + draw;
	if (top < 0)
		top = 0;
	while (top < bottom && top < 1050)
	{
		data->texture_y = (1.0 - (double)(bottom - top)
				/ data->wall->draw_height) * 32.0;
		color = data->txture->addr[data->texture_x + data->texture_y * 32];
		my_mlx_pixel_put(data, j, top, color);
		top++;
	}
}

void	draw_in_sec_img_3(t_data *data)
{
	data->txture->addr = (int *)mlx_get_data_addr(data->txture->txt_ea,
			&data->txture->bits_per_pixel, &data->txture->size_line,
			&data->txture->endian);
}

void	draw_in_sec_img_4(t_data *data)
{
	data->txture->addr = (int *)mlx_get_data_addr(data->txture->txt_we,
			&data->txture->bits_per_pixel, &data->txture->size_line,
			&data->txture->endian);
}

void	draw_in_sec_img(t_data *data, int j)
{
	double	draw;

	draw_in_sec_img_1(data);
	draw = data->wall->draw_height / 2.0;
	if (data->mure_vertical)
	{
		if (data->angle < 90 || data->angle > 270)
			draw_in_sec_img_3(data);
		else
			draw_in_sec_img_4(data);
		data->texture_x = fmod(data->y_2 / 32.0, 1.0) * 32.0;
	}
	else
	{
		if (data->angle < 180 && data->angle > 0)
			data->txture->addr = (int *)mlx_get_data_addr(data->txture->txt_no,
					&data->txture->bits_per_pixel, &data->txture->size_line,
					&data->txture->endian);
		else
			data->txture->addr = (int *)mlx_get_data_addr(data->txture->txt_so,
					&data->txture->bits_per_pixel, &data->txture->size_line,
					&data->txture->endian);
		data->texture_x = fmod(data->x_2 / 32.0, 1.0) * 32.0;
	}
	draw_in_sec_img_2(data, j, draw);
}
