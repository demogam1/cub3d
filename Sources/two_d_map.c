/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_d_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:46:55 by misaev            #+#    #+#             */
/*   Updated: 2022/01/29 12:43:10 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

double	convert_ang_rad(double angle)
{
	return (angle * (PI / 180));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

static	void	get_player_pos(t_data *data, int i, int j)
{
	data->player_x = j * 32 + (32 / 2);
	data->player_y = i * 32 + (32 / 2);
	data->mini->mini_p_x = j * 16 + (16 / 2);
	data->mini->mini_p_y = i * 16 + (16 / 2);
	data->map->map[i][j] = '0';
}

void	ft_map_info(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == 'W' || map[i][j] == 'S' )
				get_player_pos(data, i, j);
			j++;
		}
		i++;
	}
}
