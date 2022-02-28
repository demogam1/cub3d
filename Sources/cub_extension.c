/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:42:51 by misaev            #+#    #+#             */
/*   Updated: 2022/02/01 12:07:58 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

void	ft_get_haroun(t_data *data, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N')
				data->angle = NORTH;
			else if (map->map[i][j] == 'E')
				data->angle = EAST;
			else if (map->map[i][j] == 'W')
				data->angle = WEST;
			else if (map->map[i][j] == 'S')
				data->angle = SOUTH;
			j++;
		}
		i++;
	}
}

int	convert_rbg(t_data *data, int j)
{
	if (j == 1)
		return (0 << 24 | data->map->f[0] << 16
			| data->map->f[1] << 8 | data->map->f[2]);
	else
		return (0 << 24 | data->map->c[0] << 16
			| data->map->c[1] << 8 | data->map->c[2]);
}

int	ft_close(void)
{
	exit(0);
}

void	loop_extension_1(t_data *data)
{
	get_minimap_info(data);
	find_wall_a(data);
	find_wall_b(data);
	near_wall(data);
}

void	loop_extension(t_data *data)
{
	data->px_x = 0;
	data->px_y = 0;
	ft_left_ray(data);
	draw_minimap(data);
	draw_player(data);
	ft_draw_line_minimap(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	data->angle = data->save_angle;
	mlx_hook(data->mlx_win, 2, 0, deal_key_2, data);
	mlx_hook(data->mlx_win, 17, 0, ft_close, data);
}
