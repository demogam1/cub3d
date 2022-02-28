/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key_2_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:42:01 by misaev            #+#    #+#             */
/*   Updated: 2022/02/01 11:13:05 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

void	key_left(t_data *data)
{
	data->angle += 5;
	data->mini->minimap_angle += 5;
	if (data->angle + 60 > 360)
		data->angle -= 360;
	if (data->mini->minimap_angle > 360)
		data->mini->minimap_angle -= 360;
}

void	key_right(t_data *data)
{
	data->angle -= 5;
	data->mini->minimap_angle -= 5;
	if (data->angle + 60 < 0)
		data->angle += 360;
	if (data->mini->minimap_angle < 0)
		data->mini->minimap_angle += 360;
}
