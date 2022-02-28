/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:16:42 by misaev            #+#    #+#             */
/*   Updated: 2022/02/01 12:06:23 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

int	check_data_int(t_var *data)
{
	if (data->c == 6 && data->ea == 1 && data->we == 1
		&& data->so == 1 && data->no == 1)
		return (1);
	else
		return (0);
}

int	if_extension(int i, int j, char **texture, char **tab)
{
	if (check_char_content(tab[i], texture[j]) == 0
		&& j == 5 && ft_strcmp(tab[i], ""))
		return (1);
	else
		return (0);
}

static void	print_zero_wall_error(t_map *map, int i, int j)
{
	printf(B_R"Error ! the map is not closed by walls"E_C);
	printf(B_W"\nline %d --> [%s] --> character %d\n"E_C, i, map->map[i], j);
	exit(1);
}

static void	zero_extension(t_map *map, int i, int j)
{
	if (map->map[i][j - 1] != '0' && map->map[i][j - 1] != '1'
		&& map->map[i][j - 1] != 'E' && map->map[i][j - 1] != 'N'
			&& map->map[i][j - 1] != 'S' && map->map[i][j - 1] != 'W')
		print_zero_wall_error(map, i, j);
	else if (map->map[i][j + 1] != '0' && map->map[i][j + 1] != '1'
		&& map->map[i][j + 1] != 'N' && map->map[i][j + 1] != 'W'
			&& map->map[i][j + 1] != 'E' && map->map[i][j + 1] != 'S')
		print_zero_wall_error(map, i, j);
	else if (map->map[i + 1][j] != '0' && map->map[i + 1][j] != '1'
		&& map->map[i + 1][j] != 'N' && map->map[i + 1][j] != 'E'
			&& map->map[i + 1][j] != 'W' && map->map[i + 1][j] != 'S')
		print_zero_wall_error(map, i, j);
	else if (map->map[i - 1][j] != '0' && map->map[i - 1][j] != '1'
		&& map->map[i - 1][j] != 'N' && map->map[i - 1][j] != 'E'
			&& map->map[i - 1][j] != 'W' && map->map[i - 1][j] != 'S')
		print_zero_wall_error(map, i, j);
}

void	check_map_walls_extension_1(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0')
				zero_extension(map, i, j);
			j++;
		}
		i++;
	}
}
