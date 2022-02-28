/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_extension_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:49:40 by misaev            #+#    #+#             */
/*   Updated: 2022/01/29 14:01:39 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

static	void	ft_draw_line_minimap_extension(t_data *data, int i
	, double x, double y)
{
	while (i < data->mini->nbr_steps)
	{
		if (x > 1920 || y > 1080)
			break ;
		my_mlx_pixel_put(data, x, y, 0x0FFFFFFF);
		x = x + data->mini->mini_delta_x;
		y = y + data->mini->mini_delta_y;
		i++;
	}
}

void	ft_draw_line_minimap(t_data *data)
{
	double	x;
	double	y;
	int		i;

	i = 0;
	y = data->mini->mini_p_y;
	x = data->mini->mini_p_x;
	data->mini->nbr_steps = 0;
	if (fabs(data->mini->desti_p_x - data->mini->mini_p_x)
		>= fabs(data->mini->desti_p_y - data->mini->mini_p_y))
		data->mini->nbr_steps = fabs(data->mini->mini_p_x
				- data->mini->desti_p_x);
	else
		data->mini->nbr_steps = fabs(data->mini->mini_p_y
				- data->mini->desti_p_y);
	data->mini->mini_delta_x = (data->mini->desti_p_x
			- data->mini->mini_p_x) / data->mini->nbr_steps;
	data->mini->mini_delta_y = (data->mini->desti_p_y
			- data->mini->mini_p_y) / data->mini->nbr_steps;
	ft_draw_line_minimap_extension(data, i, x, y);
}
