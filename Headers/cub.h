/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:30:25 by misaev            #+#    #+#             */
/*   Updated: 2022/02/01 11:59:58 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define E_C "\e[0m"
# define B_R "\e[41m"
# define B_W "\e[1;97m"
# define BUFFER_SIZE 10
# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "gaming.h"

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
	char	**map_content;
	char	**map;
	int		index_map;
}	t_map;

typedef struct s_var
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	c;
}	t_var;

int		check_map_file(char *path);
void	get_map_content(char *path, t_map *map);
int		get_next_line(int fd, char **line);
void	print_tab(char **tab);
int		check_mandatory_elements(char **tab, int i, int j);
char	**return_tab_texture(void);
void	free_tab(char **tab);
void	print_error(char **texture, char **tab);
int		extension_parsing_126(int i, char **texture);
int		check_char_content(char *str, char *srch);
void	check_and_retriev_colors(t_map *map, char *map_content, int j);
void	retrieve_t_c_path(t_map *map);
void	get_map(t_map *map);
void	check_map(t_map *map);
void	check_map_walls(t_map *map);
void	check_map_walls_extension_1(t_map *map);
int		check_data_int(t_var *data);
int		if_extension(int i, int j, char **texture, char **tab);
void	check_player(t_map *map);
void	redeem_height_width(t_data *data);
void	ft_map_info(char **map, t_data *data);
int		ft_close(void);

#endif
