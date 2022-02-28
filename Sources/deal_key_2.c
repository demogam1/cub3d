/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:42:01 by misaev            #+#    #+#             */
/*   Updated: 2022/02/01 11:14:44 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

static	void	key_d(t_data *data)
{
	int	i;
	int	j;

	i = data->player_x + data->wall->delta_x_left;
	j = data->player_y + data->wall->delta_y_left;
	if (data->map->map[j / 32][i / 32] != '1')
	{
		data->player_x = data->player_x + data->wall->delta_x_left;
		data->player_y = data->player_y + data->wall->delta_y_left;
		data->mini->mini_p_x = data->mini->mini_p_x
			+ data->wall->delta_x_left * 0.500;
		data->mini->mini_p_y = data->mini->mini_p_y
			+ data->wall->delta_y_left * 0.500;
	}
}

static	void	key_a(t_data *data)
{
	int	i;
	int	j;

	i = data->player_x - data->wall->delta_x_left;
	j = data->player_y - data->wall->delta_y_left;
	if (data->map->map[j / 32][i / 32] != '1')
	{
		data->player_x = data->player_x - data->wall->delta_x_left;
		data->player_y = data->player_y - data->wall->delta_y_left;
		data->mini->mini_p_x = data->mini->mini_p_x
			- data->wall->delta_x_left * 0.500;
		data->mini->mini_p_y = data->mini->mini_p_y
			- data->wall->delta_y_left * 0.500;
	}
}

static	void	key_w(t_data *data)
{
	int	i;
	int	j;

	i = data->player_x + data->wall->mv_x * 2.2000;
	j = data->player_y + data->wall->mv_y * 2.2000;
	if (data->map->map[j / 32][i / 32] != '1')
	{			
		data->player_x = data->player_x + data->wall->mv_x * 2.2000;
		data->player_y = data->player_y + data->wall->mv_y * 2.2000;
		data->mini->mini_p_x = data->mini->mini_p_x
			+ data->mini->mini_delta_x * 1.1000;
		data->mini->mini_p_y = data->mini->mini_p_y
			+ data->mini->mini_delta_y * 1.1000;
	}
}

static	void	key_s(t_data *data)
{
	int	i;
	int	j;

	i = data->player_x - data->wall->mv_x * 2.2000;
	j = data->player_y - data->wall->mv_y * 2.2000;
	if (data->map->map[j / 32][i / 32] != '1')
	{
		data->player_x = data->player_x - data->wall->mv_x * 2.2000;
		data->player_y = data->player_y - data->wall->mv_y * 2.2000;
		data->mini->mini_p_x = data->mini->mini_p_x
			- data->mini->mini_delta_x * 1.1000;
		data->mini->mini_p_y = data->mini->mini_p_y
			- data->mini->mini_delta_y * 1.1000;
	}
}

int	deal_key_2(int keycode, t_data *data)
{
	if (keycode == D)
		key_d(data);
	if (keycode == A)
		key_a(data);
	if (keycode == ESC)
		exit(0);
	if (keycode == RIGHT_KEY)
		key_right(data);
	if (keycode == LEFT_KEY)
		key_left(data);
	if (keycode == W)
		key_w(data);
	if (keycode == S)
		key_s(data);
	return (0);
}
