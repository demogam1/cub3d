/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:23:42 by misaev            #+#    #+#             */
/*   Updated: 2022/01/29 12:16:35 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

static	void	ft_draw_line_left(t_data *data)
{
	data->wall->length = 0;
	if (fabs(data->wall->x_2_left - data->player_x)
		>= fabs(data->wall->y_2_left - data->player_y))
		data->wall->length = fabs(data->player_x - data->wall->x_2_left);
	else
		data->wall->length = fabs(data->player_y - data->wall->y_2_left);
	data->wall->delta_x_left = (data->wall->x_2_left - data->player_x)
		/ data->wall->length;
	data->wall->delta_y_left = (data->wall->y_2_left - data->player_y)
		/ data->wall->length;
}

int	check_the_limit_left(t_data *data, int i)
{
	if (i == 1)
	{
		if ((data->wall->ay_left / PXL) > 0 && (data->wall->ay_left / PXL)
			< data->wall->max_y && (data->wall->ax_left / PXL) > 0
			&& (data->wall->ax_left / PXL) < data->wall->max_x)
			return (1);
		else
			return (0);
	}
	else if (i == 2)
	{
		if ((data->wall->by_left / PXL) > 0 && (data->wall->by_left / PXL)
			< data->wall->max_y && (data->wall->bx_left / PXL) > 0
			&& (data->wall->bx_left / PXL) < data->wall->max_x)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

static	void	wall_exception(t_data *data)
{
	if (data->wall->ax_left == 0 && data->wall->ay_left == 0)
	{
		data->wall->x_2_left = data->wall->bx_left;
		data->wall->y_2_left = data->wall->by_left;
	}
	else if (data->wall->bx_left == 0 && data->wall->by_left == 0)
	{
		data->wall->x_2_left = data->wall->ax_left;
		data->wall->y_2_left = data->wall->ay_left;
	}
}

static	void	near_wall_left(t_data *data)
{
	double	a;
	double	b;

	a = sqrt(pow(data->player_x - data->wall->ax_left, 2)
			+ pow(data->player_y - data->wall->ay_left, 2));
	b = sqrt(pow(data->player_x - data->wall->bx_left, 2)
			+ pow(data->player_y - data->wall->by_left, 2));
	if (a < b)
	{
		data->wall->x_2_left = data->wall->ax_left;
		data->wall->y_2_left = data->wall->ay_left;
	}
	else
	{
		data->wall->x_2_left = data->wall->bx_left;
		data->wall->y_2_left = data->wall->by_left;
	}
	wall_exception(data);
}

void	ft_left_ray(t_data *data)
{
	find_wall_a_left(data);
	find_wall_a_left(data);
	near_wall_left(data);
	ft_draw_line_left(data);
}
