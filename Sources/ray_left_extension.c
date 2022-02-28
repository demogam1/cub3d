/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_left_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:23:42 by misaev            #+#    #+#             */
/*   Updated: 2022/01/29 12:16:42 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

static	double	angle_exception(t_data *data)
{
	double	angle;

	angle = data->save_angle - 90;
	if (angle == 180)
		angle = 175;
	else if (angle == 5)
		angle = 10;
	else if (angle == 0 || angle == -5)
		angle = -10;
	return (angle);
}

static	void	find_wall_a_left_exception(t_data *data, int xa, int ya)
{
	data->wall->ax_left += xa;
	data->wall->ay_left += ya;
}

int	find_wall_a_left(t_data *data)
{
	double	ya;
	double	xa;
	double	angle;

	angle = angle_exception(data);
	ya = 0;
	if (angle <= 180 && angle >= 0)
	{
		ya -= PXL;
		data->wall->ay_left = floor(data->player_y / PXL) * (PXL) - 0.00000001;
	}
	else
	{
		ya = PXL;
		data->wall->ay_left = floor(data->player_y / PXL) * (PXL) + PXL;
	}
	xa = -ya / tan(convert_ang_rad(angle));
	data->wall->ax_left = data->player_x
		+ (data->player_y - data->wall->ay_left) / tan(convert_ang_rad(angle));
	while (check_the_limit_left(data, 1) == 1
		&& data->map->map[(int)data->wall->ay_left
			/ PXL][(int)data->wall->ax_left / PXL] == '0')
		find_wall_a_left_exception(data, xa, ya);
	return (0);
}

static	void	find_wall_b_left_exception(t_data *data, int xa, int ya)
{
	data->wall->bx_left += xa;
	data->wall->by_left += ya;
}

int	find_wall_b_left(t_data *data)
{
	double	ya;
	double	xa;
	double	angle;

	angle = angle_exception(data);
	xa = 0;
	if (angle > 90 && angle < 270)
	{	
		xa -= PXL;
		data->wall->bx_left = floor(data->player_x / PXL) * (PXL) - 0.00000001;
	}
	else
	{
		xa = PXL;
		data->wall->bx_left = floor(data->player_x / PXL) * (PXL) + PXL;
	}
	ya = -xa * tan(convert_ang_rad((angle)));
	data->wall->by_left = data->player_y + (data->player_x
			- data->wall->bx_left) * tan(convert_ang_rad(angle));
	while (check_the_limit_left(data, 2) == 1
		&& data->map->map[(int)data->wall->by_left
			/ PXL][(int)data->wall->bx_left / PXL] == '0')
		find_wall_b_left_exception(data, xa, ya);
	return (0);
}
