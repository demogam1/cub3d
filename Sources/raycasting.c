/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:26:35 by misaev            #+#    #+#             */
/*   Updated: 2022/01/29 12:43:02 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

static	void	ft_draw_line_2(t_data *data)
{
	data->wall->length = 0;
	if (fabs(data->x_2 - data->player_x) >= fabs(data->y_2 - data->player_y))
		data->wall->length = fabs(data->player_x - data->x_2);
	else
		data->wall->length = fabs(data->player_y - data->y_2);
	data->delta_x = (data->x_2 - data->player_x) / data->wall->length;
	data->delta_y = (data->y_2 - data->player_y) / data->wall->length;
}

static	int	check_the_limit(t_data *data, int i)
{
	if (i == 1)
	{
		if ((data->wall->Ay / PXL) > 0 && (data->wall->Ay / PXL)
			< data->wall->max_y && (data->wall->Ax / PXL) > 0
			&& (data->wall->Ax / PXL) < data->wall->max_x)
			return (1);
		else
			return (0);
	}
	else if (i == 2)
	{
		if ((data->wall->By / PXL > 0 && data->wall->By / PXL
				< data->wall->max_y) && (data->wall->Bx / PXL > 0
				&& data->wall->Bx / PXL < data->wall->max_x))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int	find_wall_a(t_data *data)
{
	double	ya;
	double	xa;

	ya = 0;
	if (data->angle <= 180 && data->angle >= 0)
	{
		ya -= PXL;
		data->wall->Ay = floor(data->player_y / PXL) * (PXL) - 0.00000001;
	}
	else
	{
		ya = PXL;
		data->wall->Ay = floor(data->player_y / PXL) * (PXL) + PXL;
	}
	xa = -ya / tan(convert_ang_rad(data->angle));
	data->wall->Ax = data->player_x + (data->player_y
			- data->wall->Ay) / tan(convert_ang_rad(data->angle));
	while (check_the_limit(data, 1) == 1
		&& data->map->map[(int)data->wall->Ay / PXL][(int)data->wall->Ax
		/ PXL] == '0')
	{		
		data->wall->Ax += xa;
		data->wall->Ay += ya;
	}
	return (0);
}

int	find_wall_b(t_data *data)
{
	double	ya;
	double	xa;

	xa = 0;
	if (data->angle > 90 && data->angle < 270)
	{	
		xa -= PXL;
		data->wall->Bx = floor(data->player_x / PXL) * (PXL) - 0.00000001;
	}
	else
	{
		xa = PXL;
		data->wall->Bx = floor(data->player_x / PXL) * (PXL) + PXL;
	}
	ya = -xa * tan(convert_ang_rad(data->angle));
	data->wall->By = data->player_y + (data->player_x
			- data->wall->Bx) * tan(convert_ang_rad(data->angle));
	while (check_the_limit(data, 2) == 1
		&& data->map->map[(int)data->wall->By / PXL][(int)data->wall->Bx
		/ PXL] == '0')
	{
		data->wall->Bx += xa;
		data->wall->By += ya;
	}
	return (0);
}

void	near_wall(t_data *data)
{
	double	a;
	double	b;

	a = sqrt(pow(data->player_x - data->wall->Ax, 2)
			+ pow(data->player_y - data->wall->Ay, 2));
	b = sqrt(pow(data->player_x - data->wall->Bx, 2)
			+ pow(data->player_y - data->wall->By, 2));
	if (a < b)
	{
		data->x_2 = data->wall->Ax;
		data->y_2 = data->wall->Ay;
		data->mure_vertical = 0;
	}
	else
	{
		data->x_2 = data->wall->Bx;
		data->y_2 = data->wall->By;
		data->mure_vertical = 1;
	}
	ft_draw_line_2(data);
}
