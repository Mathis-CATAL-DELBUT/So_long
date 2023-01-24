/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:18:04 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/23 19:43:04 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mlx.h"
#include "include/mlx_int.h"
#include "libft/libft.h"
#include "so_long.h"

void	display_map_2(t_map *data, int i, int j)
{
	if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_player, data->x, data->y);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_floor, data->x, data->y);
	else if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_wall, data->x, data->y);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_coin, data->x, data->y);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_exit, data->x, data->y);
}

void	display_map(t_map *data)
{
	int	i;
	int	j;

	i = -1;
	data->x = 0;
	data->y = 0;
	while (++i < data->len_line)
	{
		j = -1;
		data->x = 0;
		while (++j < data->len_column)
		{
			display_map_2(data, i, j);
			data->x += 64;
		}
		data->y += 64;
	}
}

int	img(t_map *data)
{
	int	w;

	data->img_player = NULL;
	data->img_coin = NULL;
	data->img_floor = NULL;
	data->img_wall = NULL;
	data->img_exit = NULL;
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr, "i/p.xpm", &w, &w);
	if (!data->img_player)
		return (0);
	data->img_coin = mlx_xpm_file_to_image(data->mlx_ptr, "i/c.xpm", &w, &w);
	if (!data->img_coin)
		return (0);
	data->img_wall = mlx_xpm_file_to_image(data->mlx_ptr, "i/w.xpm", &w, &w);
	if (!data->img_wall)
		return (0);
	data->img_floor = mlx_xpm_file_to_image(data->mlx_ptr, "i/f.xpm", &w, &w);
	if (!data->img_floor)
		return (0);
	data->img_exit = mlx_xpm_file_to_image(data->mlx_ptr, "i/e.xpm", &w, &w);
	if (!data->img_exit)
		return (0);
	return (1);
}

int	handle_keypress(int keysym, t_map *data)
{
	static int	i = 0;

	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx_ptr);
	else if (keysym == XK_w)
		i += move_up(data, i);
	else if (keysym == XK_a)
		i += move_left(data, i);
	else if (keysym == XK_s)
		i += move_down(data, i);
	else if (keysym == XK_d)
		i += move_right(data, i);
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
	if (img(data) == 0)
		return (0);
	display_map(data);
	mlx_key_hook(data->win_ptr, handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, mlx_loop_end, data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
	return (0);
}
