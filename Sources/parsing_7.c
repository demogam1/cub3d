/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_7.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:15:56 by misaev            #+#    #+#             */
/*   Updated: 2022/01/06 11:05:23 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

static int	check_extension(char *path)
{
	int		i;
	int		j;
	int		len_ex;
	char	*ex;

	ex = ".cub";
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

static void	error_file_print(char *error_str)
{
	printf(B_W"%s\n"E_C, error_str);
	exit(1);
}

int	check_map_file(char *path)
{
	if (open(path, O_DIRECTORY) != -1)
		error_file_print("You are trying to open a directory");
	else if (open(path, O_RDONLY) > 0)
	{
		if (check_extension(path) == 1)
			return (open(path, O_RDONLY));
		else
			error_file_print("Wrong extension !");
	}
	else
		error_file_print("Wrong path or fils does not exist !");
	return (open(path, O_RDONLY));
}

void	check_player(t_map *map)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'E'
				|| map->map[i][j] == 'W' || map->map[i][j] == 'S')
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
	{
		printf(B_R"Player position not indicated or duplicated !"E_C);
		printf(B_W" \nThe map should contain "B_R
			"ONLY ONE"E_C B_W" of this letters --> N,E,W,S\n"E_C);
		exit(1);
	}
}

void	redeem_height_width(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
			j++;
		if (j > data->wall->max_x)
			data->wall->max_x = j;
		i++;
		if (i > data->wall->max_y)
			data->wall->max_y = i;
	}
}
