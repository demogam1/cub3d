/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:36:46 by misaev            #+#    #+#             */
/*   Updated: 2022/02/01 12:08:59 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

static void	data_init(t_var *data)
{
	data->no = 0;
	data->so = 0;
	data->ea = 0;
	data->we = 0;
	data->c = 0;
}

static void	data_update(t_var *data, char *texture)
{
	if (!ft_strncmp(texture, "NO ", 3))
		data->no++;
	else if (!ft_strncmp(texture, "SO ", 3))
		data->so++;
	else if (!ft_strncmp(texture, "EA ", 3))
		data->ea++;
	else if (!ft_strncmp(texture, "WE ", 3))
		data->we++;
}

static	void	extension_return(t_var *data, char *texture)
{
	data_update(data, texture);
	data->c++;
}

static int	return_zero_extension(char **texture)
{	
	free_tab(texture);
	return (0);
}

int	check_mandatory_elements(char **tab, int i, int j)
{
	char	**texture;
	t_var	data;

	texture = return_tab_texture();
	data_init(&data);
	while (tab[i])
	{
		j = 0;
		while (texture[j])
		{
			if (check_char_content(tab[i], texture[j]) == 1)
			{
				extension_return(&data, texture[j]);
				break ;
			}
			else if (if_extension(i, j, texture, tab) == 1)
				print_error(texture, tab);
			else
				j++;
		}
		if (check_data_int(&data) == 1)
			return (extension_parsing_126(i, texture));
		i++;
	}
	return (return_zero_extension(texture));
}
