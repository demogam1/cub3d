/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:42:51 by misaev            #+#    #+#             */
/*   Updated: 2022/02/01 12:02:26 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

int	loop(void *meta)
{
	t_data	*data;

	data = meta;
	data->wall->nbr_line = 1920;
	data->save_angle = data->angle;
	data->mini->minimap_angle = data->angle;
	data->angle = data->angle - 30;
	ft_map_info(data->map->map, data);
	while (data->wall->nbr_line > 0)
	{
		loop_extension_1(data);
		if (data->angle == data->save_angle)
		{
			data->wall->mv_x = data->delta_x;
			data->wall->mv_y = data->delta_y;
			data->wall->x_correct = data->x_2;
			data->wall->y_correct = data->y_2;
		}
		data->angle += 0.03125;
		draw_in_sec_img(data, data->wall->nbr_line);
		data->wall->nbr_line--;
	}
	loop_extension(data);
	return (0);
}

static	void	init_wall_info(t_wall *wall, t_data *data)
{
	t_minimap	*mini;

	mini = ft_calloc(1, sizeof(t_minimap));
	data->mini = mini;
	wall->Ax = 0;
	wall->Ay = 0;
	wall->Bx = 0;
	wall->By = 0;
	wall->max_y = 0;
	wall->max_x = 0;
	wall->nbr_line = 0;
	wall->mv_x = 0;
	wall->mv_y = 0;
	data->txture->txt_no = mlx_xpm_file_to_image(data->mlx, data->map->no,
			&data->txture->img_w, &data->txture->img_h);
	data->txture->txt_ea = mlx_xpm_file_to_image(data->mlx, data->map->ea,
			&data->txture->img_w, &data->txture->img_h);
	data->txture->txt_we = mlx_xpm_file_to_image(data->mlx, data->map->we,
			&data->txture->img_w, &data->txture->img_h);
	data->txture->txt_so = mlx_xpm_file_to_image(data->mlx, data->map->so,
			&data->txture->img_w, &data->txture->img_h);
}

static	void	init_window(t_map *map, t_data *data,
	t_wall *wall, t_texture *txture)
{
	data->player_x = 0;
	data->player_y = 0;
	data->x_2 = 0;
	data->y_2 = 0;
	data->delta_x = 0;
	data->delta_y = 0;
	data->angle = 0;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "cub3d");
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->wall = 0;
	data->save_angle = 0;
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->map = map;
	data->txture = txture;
	init_wall_info(wall, data);
	data->wall = wall;
	redeem_height_width(data);
	ft_get_haroun(data, map);
	mlx_loop_hook(data->mlx, loop, (void *)data);
	mlx_loop(data->mlx);
}

static	void	extension(t_map *map, t_data *data,
	t_wall *wall, t_texture *txture)
{
	get_map(map);
	check_map(map);
	check_player(map);
	init_window(map, data, wall, txture);
}

int	main(int ac, char **arg)
{
	t_map		*map;
	t_data		*data;
	t_wall		*wall;
	t_texture	*txture;

	if (ac != 2)
	{
		ft_putstr_fd("numbers of arguments are not valid", STDERR_FILENO);
		exit(1);
	}
	map = ft_calloc(1, sizeof(t_map));
	data = ft_calloc(1, sizeof(t_data));
	wall = ft_calloc(1, sizeof(t_wall));
	txture = ft_calloc(1, sizeof(t_texture));
	check_map_file(arg[1]);
	get_map_content(arg[1], map);
	if (check_mandatory_elements(map->map_content, 0, 0) > 0)
	{
		retrieve_t_c_path(map);
		map->index_map = check_mandatory_elements(map->map_content, 0, 0);
	}
	extension(map, data, wall, txture);
	return (0);
}
