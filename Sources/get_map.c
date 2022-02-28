/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:05:24 by misaev            #+#    #+#             */
/*   Updated: 2022/01/28 12:33:22 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

/* FREE 2D ARRAY */
void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab[i]);
	free(tab);
}

/* COUNT NUMBER OF TABLE IN 2D ARRAY*/
static int	get_map_len(int fd)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		i++;
		free(line);
	}
	free(line);
	close(fd);
	return (i);
}

/* FUNCTION THAT REDEEM MAP FILE CONTENT */
void	get_map_content(char *path, t_map *map)
{
	int		fd;
	int		i;
	int		tab_len;
	char	*line;

	line = NULL;
	i = 0;
	fd = open(path, O_RDONLY);
	tab_len = get_map_len(fd);
	fd = open(path, O_RDONLY);
	map->map_content = ft_calloc(sizeof(map->map_content), tab_len + 2);
	while (i <= tab_len)
	{
		get_next_line(fd, &line);
		map->map_content[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
}

/* temporary print tab [NEED TO BE DELETED] */
void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("[%s]\n", tab[i]);
		i++;
	}
}
