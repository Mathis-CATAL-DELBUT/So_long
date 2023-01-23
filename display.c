/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:18:04 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/22 19:21:04 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mlx.h"
#include "include/mlx_int.h"
#include "libft/libft.h"
#include "so_long.h"

void	display_map(t_map *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	x = 0;
	y = 0;
	while (++i < data->len_line)
	{
		j = -1;
		x = 0;
		while (++j < data->len_column)
		{
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img_player, x, y);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img_floor, x, y);
			else if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img_wall, x, y);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img_coin, x, y);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img_exit, x, y);
			x += 64;
		}
		y += 64;
	}
}

void	img(t_map *data)
{
	int	w;

	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr, "items/mario.xpm",
			&w, &w);
	data->img_coin = mlx_xpm_file_to_image(data->mlx_ptr, "items/coin.xpm", &w,
			&w);
	data->img_wall = mlx_xpm_file_to_image(data->mlx_ptr, "items/wall.xpm", &w,
			&w);
	data->img_floor = mlx_xpm_file_to_image(data->mlx_ptr, "items/floor.xpm",
			&w, &w);
	data->img_exit = mlx_xpm_file_to_image(data->mlx_ptr, "items/exit.xpm", &w,
			&w);
}

int	handle_keypress(int keysym, t_map *data)
{
	static int	i = 0;

	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx_ptr);
	else if (keysym == XK_w && i++)
		move_up(data, i);
	else if (keysym == XK_a && i++)
		move_left(data, i);
	else if (keysym == XK_s && i++)
		move_down(data, i);
	else if (keysym == XK_d && i++)
		move_right(data, i);
	return (0);
}

int	init(t_map *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, (data->len_column - 1) * 64,
			data->len_line * 64, "So_long");
	if (data->win_ptr == NULL)
		return (free(data->win_ptr), 0);
	img(data);
	display_map(data);
	mlx_key_hook(data->win_ptr, handle_keypress, data);
	mlx_loop(data->mlx_ptr);
	return (free(data->mlx_ptr), 0);
}
