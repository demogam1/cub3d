/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:23:31 by misaev            #+#    #+#             */
/*   Updated: 2022/01/28 16:44:57 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

static char	*cpy_char(char *dest, char *src, int max)
{
	int	i;

	dest = malloc(sizeof(char) * max + 1);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (i < max)
	{
		while (i < max)
		{
			dest[i] = ' ';
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

void	get_map(t_map *map)
{
	int	i;
	int	j;
	int	max;

	j = 0;
	i = map->index_map + 1;
	max = ft_strlen(map->map_content[i]);
	while (map->map_content[i])
	{	
		if (ft_strlen(map->map_content[i]) > (size_t)max)
			max = ft_strlen(map->map_content[i]);
		i++;
	}
	map->map = malloc(sizeof(char *) * i);
	i = map->index_map + 1;
	while (!ft_strcmp(map->map_content[i], ""))
		i++;
	while (map->map_content[i])
	{
		map->map[j] = cpy_char(map->map[j], map->map_content[i], max);
		i++;
		j++;
	}
	map->map[j] = NULL;
	free_tab(map->map_content);
}

static int	check_map_symbol(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' ' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

void	check_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (check_map_symbol(map->map[i]) == 1)
			i++;
		else
		{
			printf("Error ! line %d --> "B_R" '%s'"E_C
				" contains forbidden characters\n", i, map->map[i]);
			exit(0);
		}
	}
	check_map_walls(map);
}
