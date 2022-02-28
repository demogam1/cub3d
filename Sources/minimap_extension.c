/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:49:40 by misaev            #+#    #+#             */
/*   Updated: 2022/01/29 13:58:35 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

void	closest_wall_on_minimap(t_data *data)
{
	double	a;
	double	b;

	a = sqrt(pow(data->mini->mini_p_x - data->mini->horizontal_x, 2)
			+ pow(data->mini->mini_p_y - data->mini->horizontal_y, 2));
	b = sqrt(pow(data->mini->mini_p_x - data->mini->vertical_x, 2)
			+ pow(data->mini->mini_p_y - data->mini->vertical_y, 2));
	if (a < b)
	{
		data->mini->desti_p_x = data->mini->horizontal_x;
		data->mini->desti_p_y = data->mini->horizontal_y;
	}
	else
	{
		data->mini->desti_p_x = data->mini->vertical_x;
		data->mini->desti_p_y = data->mini->vertical_y;
	}
}

void	draw_pixels(t_data *data, int c)
{
	int	x;
	int	y;

	y = data->px_y;
	while (y < data->px_y + 16)
	{
		x = data->px_x;
		while (x < data->px_x + 16)
		{	
			if (c == 1)
				my_mlx_pixel_put(data, x, y, 0x0000FF00);
			else if (c == 2)
				my_mlx_pixel_put(data, x, y, convert_rbg(data, 1));
			x++;
		}
		if (c == 1)
			my_mlx_pixel_put(data, x, y, 0x0000FF00);
		else if (c == 2)
			my_mlx_pixel_put(data, x, y, convert_rbg(data, 1));
		y++;
	}
}

void	draw_player(t_data *data)
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	i;

	start_x = (int) data->mini->mini_p_x - (16 / 10);
	start_y = (int) data->mini->mini_p_y - (16 / 10);
	end_x = (int) data->mini->mini_p_x + (16 / 10);
	end_y = (int) data->mini->mini_p_y + (16 / 10);
	while (start_y <= end_y)
	{	
		i = start_x;
		while (i <= end_x)
		{
			my_mlx_pixel_put(data, i, start_y, 0x00728840);
			i++;
		}
		start_y++;
	}
}

void	draw_minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		data->px_x = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == 'N' || data->map->map[i][j] == 'E'
				|| data->map->map[i][j] == 'W' || data->map->map[i][j] == 'S' )
				draw_pixels(data, 2);
			if (data->map->map[i][j] == '1')
				draw_pixels(data, 1);
			else if (data->map->map[i][j] == '0')
				draw_pixels(data, 2);
			data->px_x += 16;
			j++;
		}
		data->px_y += 16;
		i++;
	}
}

void	get_minimap_info(t_data *data)
{
	vertical_wall(data);
	horizontal_wall(data);
	closest_wall_on_minimap(data);
}
