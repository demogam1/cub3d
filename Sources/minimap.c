/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:56:12 by misaev            #+#    #+#             */
/*   Updated: 2022/01/29 14:01:37 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

static	int	check_the_limit(t_data *data, int i)
{
	if (i == 1)
	{
		if ((data->mini->horizontal_y / 16) > 0
			&& (data->mini->horizontal_y / 16)
			< data->wall->max_y && (data->mini->horizontal_x / 16) > 0
			&& (data->mini->horizontal_x / 16) < data->wall->max_x)
			return (1);
		else
			return (0);
	}
	else if (i == 2)
	{
		if ((data->mini->vertical_y / 16 > 0 && data->mini->vertical_y / 16
				< data->wall->max_y) && (data->mini->vertical_x / 16 > 0
				&& data->mini->vertical_x / 16 < data->wall->max_x))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

static	void	horizontal_wall_extension(t_data *data, double xa, double ya)
{
	while (check_the_limit(data, 1) == 1
		&& data->map->map[(int)data->mini->horizontal_y
			/ 16][(int)data->mini->horizontal_x / 16] == '0')
	{
		data->mini->horizontal_x += xa;
		data->mini->horizontal_y += ya;
	}
}

int	horizontal_wall(t_data *data)
{
	double	ya;
	double	xa;

	ya = 0;
	if (data->mini->minimap_angle <= 180 && data->mini->minimap_angle >= 0)
	{
		ya -= 16;
		data->mini->horizontal_y = floor(data->mini->mini_p_y / 16)
			* (16) - 0.01;
	}
	else
	{
		ya = 16;
		data->mini->horizontal_y = floor(data->mini->mini_p_y / 16)
			* (16) + 16;
	}
	xa = -ya / tan(convert_ang_rad(data->mini->minimap_angle));
	data->mini->horizontal_x = data->mini->mini_p_x + (data->mini->mini_p_y
			- data->mini->horizontal_y)
		/ tan(convert_ang_rad(data->mini->minimap_angle));
	horizontal_wall_extension(data, xa, ya);
	return (0);
}

static	void	vertical_wall_extension(t_data *data, double xa, double ya)
{
	while (check_the_limit(data, 2) == 1
		&& data->map->map[(int)data->mini->vertical_y
			/ 16][(int)data->mini->vertical_x / 16] == '0')
	{
		data->mini->vertical_x += xa;
		data->mini->vertical_y += ya;
	}
}

int	vertical_wall(t_data *data)
{
	double	ya;
	double	xa;

	xa = 0;
	if (data->mini->minimap_angle > 90 && data->mini->minimap_angle < 270)
	{	
		xa -= 16;
		data->mini->vertical_x = floor(data->mini->mini_p_x / 16)
			* (16) - 0.01;
	}
	else
	{
		xa = 16;
		data->mini->vertical_x = floor(data->mini->mini_p_x / 16)
			* (16) + 16;
	}
	ya = -xa * tan(convert_ang_rad(data->mini->minimap_angle));
	data->mini->vertical_y = data->mini->mini_p_y + (data->mini->mini_p_x
			- data->mini->vertical_x)
		* tan(convert_ang_rad(data->mini->minimap_angle));
	vertical_wall_extension(data, xa, ya);
	return (0);
}
