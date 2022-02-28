/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:58:40 by misaev            #+#    #+#             */
/*   Updated: 2022/02/01 12:05:43 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

static void	print_error_color(void)
{
	ft_putstr_fd(
		"The color range should not be superior than 255 or negative",
		STDERR_FILENO);
	exit(0);
}

static void	fill_map_c(t_map *map, char **tab)
{
	int	i;

	i = 0;
	map->c = malloc(sizeof(int) * 3);
	while (i <= 2)
	{
		map->c[i] = ft_atoi(tab[i]);
		if (map->c[i] <= 255 && map->c[i] >= 0)
			i++;
		else
			print_error_color();
	}
}

static void	fill_map_f(t_map *map, char **tab)
{
	int	i;

	i = 0;
	map->f = malloc(sizeof(int) * 3);
	while (i <= 2)
	{
		map->f[i] = ft_atoi(tab[i]);
		if (map->f[i] <= 255 && map->f[i] >= 0)
			i++;
		else
			print_error_color();
	}
}

void	check_and_retriev_colors(t_map *map, char *map_content, int j)
{
	char	**tab;
	int		i;

	tab = ft_split(map_content + 2, ',');
	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
	{
		printf("RGB argument must contain only 3 value !\n");
		exit(1);
	}
	if (j == 5)
		fill_map_c(map, tab);
	else if (j == 4)
		fill_map_f(map, tab);
	free_tab(tab);
}
