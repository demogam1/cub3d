/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:57:12 by misaev            #+#    #+#             */
/*   Updated: 2022/02/01 12:05:12 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

static int	check_texture_extension(char *path)
{
	int		i;
	int		j;
	int		len_ex;
	char	*ex;

	ex = ".xpm";
	len_ex = ft_strlen(ex);
	i = 0;
	j = 0;
	while (path[i] != '\0')
	{
		if (path[i] == ex[j])
		{
			while (ex[j] != '\0' && path[i] == ex[j])
			{
				j++;
				i++;
			}
			if (j == len_ex)
				return (1);
		}
		i++;
	}
	return (0);
}

static char	*separat_char_indication(char *map_dir
	, char *indication, char *content)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	while (indication[i] == content[i])
		i++;
	map_dir = ft_strdup(content + i);
	fd = open(map_dir, O_RDONLY);
	if (fd == -1)
	{
		printf("path of %s is not valid", content);
		free(map_dir);
		exit(1);
	}
	else if (check_texture_extension(map_dir) == 0)
	{
		printf("extension of %s texture is not valid", content);
		free(map_dir);
		exit(1);
	}
	return (map_dir);
}

static void	if_forest_for_t_c(t_map *map
	, char *indication, char *content, int j)
{
	if (j <= 3)
	{
		if (j == 0)
			map->no = separat_char_indication(map->no, indication, content);
		else if (j == 1)
			map->so = separat_char_indication(map->so, indication, content);
		else if (j == 2)
			map->we = separat_char_indication(map->we, indication, content);
		else
			map->ea = separat_char_indication(map->ea, indication, content);
	}
	else
	{
		if (j == 4 || j == 5)
			check_and_retriev_colors(map, content, j);
	}
}

void	retrieve_t_c_path(t_map *map)
{
	char	**texture;
	int		i;
	int		j;
	int		c;

	c = 0;
	j = 0;
	i = 0;
	texture = return_tab_texture();
	while (map->map_content[i])
	{
		j = 0;
		while (texture[j])
		{
			if (check_char_content(map->map_content[i], texture[j]) == 1)
				if_forest_for_t_c(map, texture[j], map->map_content[i], j);
			j++;
		}
		i++;
	}
	free_tab(texture);
}
