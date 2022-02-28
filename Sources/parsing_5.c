/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 08:50:23 by misaev            #+#    #+#             */
/*   Updated: 2021/12/20 11:06:26 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

static int	check_if_only_walls(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static void	print_walls_error(t_map *map, int i, int j)
{
	printf("Error ! The map is not surrounded by walls\n");
	printf("line %i --> " B_R " %s' "E_C
		" --> [%c]\n", i, map->map[i], map->map[i][j]);
	exit(0);
}

static void	check_map_walls_extension(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (j == 0)
			{
				if (map->map[i][j] != '1' && map->map[i][j] != ' ')
					print_walls_error(map, i, j);
			}
			else if (map->map[i][j + 1] == '\0')
			{
				if (map->map[i][j] != '1' && map->map[i][j] != ' ')
					print_walls_error(map, i, j);
			}
			j++;
		}
		i++;
	}
}

static void	print_error_walls_extension(t_map *map, int i)
{
	printf(B_W" Error !\nThe map is not surrounded by walls\n"E_C);
	printf(B_W" line %d --> "E_C B_R" %s\n"E_C, i, map->map[i]);
	exit(0);
}

void	check_map_walls(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (i == 0)
		{
			if (check_if_only_walls(map->map[i]) == 0)
				print_error_walls_extension(map, i);
		}
		else if (map->map[i + 1] == NULL)
		{
			if (check_if_only_walls(map->map[i]) == 0)
				print_error_walls_extension(map, i);
		}
		i++;
	}
	check_map_walls_extension(map);
	check_map_walls_extension_1(map);
}
