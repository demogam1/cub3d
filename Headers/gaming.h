/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:50:49 by misaev            #+#    #+#             */
/*   Updated: 2022/02/01 12:16:13 by misaev           ###   ########.fr       */
/*                                                                            */
/* **************************************************************************\*/

#ifndef GAMING_H
# define GAMING_H

# include "cub.h"
# define NORTH 90
# define SOUTH 270
# define EAST 0
# define WEST 180
# define ESC 53
# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define W 13
# define S 1
# define A 0
# define D 2
# define PI 3.14159
# define PXL 32
# define SCREEN_H 1080
# define SCREEN_W 1920

typedef struct s_map	t_map;

typedef struct s_minimap
{
	double	mini_p_x;
	double	mini_p_y;
	double	desti_p_x;
	double	desti_p_y;
	double	nbr_steps;
	double	mini_delta_x;
	double	mini_delta_y;
	double	horizontal_x;
	double	horizontal_y;
	double	vertical_x;
	double	vertical_y;
	double	minimap_angle;
}	t_minimap;

typedef struct s_texture
{
	int		*addr;
	void	*txt_no;
	void	*txt_so;
	void	*txt_ea;
	void	*txt_we;
	int		bits_per_pixel;
	int		line_length;
	int		size_line;
	int		endian;
	int		img_w;
	int		img_h;
}	t_texture;

typedef struct s_wall
{
	double	Ay;
	double	Ax;
	double	Bx;
	double	By;
	int		max_x;
	int		max_y;
	int		nbr_line;
	double	mv_x;
	double	mv_y;
	double	mv_l_x;
	double	mv_l_y;
	double	mv_r_x;
	double	mv_r_y;
	double	length;
	double	x_correct;
	double	y_correct;
	double	distance_project_plan;
	double	actual_slice_height;
	double	distance_to_slice;
	double	correct_distance;
	double	draw_height;
	double	ay_left;
	double	ax_left;
	double	bx_left;
	double	by_left;
	double	y_2_left;
	double	x_2_left;
	double	delta_x_left;
	double	delta_y_left;
	double	ay_right;
	double	ax_right;
	double	bx_right;
	double	by_right;
	double	y_2_right;
	double	x_2_right;
	double	delta_x_right;
	double	delta_y_right;
}	t_wall;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			px_x;
	int			px_y;
	double		player_x;
	double		player_y;
	double		angle;
	double		save_angle;
	double		x_2;
	double		y_2;
	int			mure_vertical;
	int			texture_x;
	int			texture_y;
	double		draw;
	double		delta_x;
	double		delta_y;
	t_map		*map;
	t_wall		*wall;
	t_texture	*txture;	
	t_minimap	*mini;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		find_wall_a(t_data *data);
int		find_wall_b(t_data *data);
void	near_wall(t_data *data);
double	convert_ang_rad(double angle);
int		convert_rbg(t_data *data, int j);
void	draw_in_sec_img(t_data *data, int j);
int		deal_key_2(int keycode, t_data *data);
void	key_left(t_data *data);
void	key_right(t_data *data);
void	ft_get_haroun(t_data *data, t_map *map);
void	loop_extension_1(t_data *data);
void	loop_extension(t_data *data);
void	closest_wall_on_minimap(t_data *data);
int		vertical_wall(t_data *data);
int		horizontal_wall(t_data *data);
void	ft_draw_line_minimap(t_data *data);
void	draw_player(t_data *data);
void	draw_minimap(t_data *data);
void	get_minimap_info(t_data *data);
void	ft_left_ray(t_data *data);
void	ft_right_ray(t_data *data);
void	ft_draw_line_minimap(t_data *data);
int		find_wall_a_left(t_data *data);
int		find_wall_b_left(t_data *data);
int		check_the_limit_left(t_data *data, int i);

#endif

/**/