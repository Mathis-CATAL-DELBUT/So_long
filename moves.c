/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:02:08 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/22 19:09:59 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "so_long.h"
#include "include/mlx.h"
#include "include/mlx_int.h"

void	move_right(t_map *data, int i)
{
	check_p_e_c(data->map, data, 0);
	if (data->map[data->i_p][data->j_p + 1] == 'E' && data->temp_c == 0)
	{
		data->map[data->i_p][data->j_p] = '0';
		display_map (data);
		ft_printf ("Moves: %d\n", i);
		mlx_loop_end (data->mlx_ptr);
	}
	if (data->map[data->i_p][data->j_p + 1] != '1'
		&& data->map[data->i_p][data->j_p + 1] != 'E')
	{
		data->map[data->i_p][data->j_p + 1] = 'P';
		data->map[data->i_p][data->j_p] = '0';
		data->j_p++;
		display_map (data);
		ft_printf ("Moves: %d\n", i);
	}
}

void	move_left(t_map *data, int i)
{
	check_p_e_c (data->map, data, 0);
	if (data->map[data->i_p][data->j_p - 1] == 'E' && data->temp_c == 0)
	{
		data->map[data->i_p][data->j_p] = '0';
		display_map (data);
		ft_printf ("Moves: %d\n", i);
		mlx_loop_end (data->mlx_ptr);
	}
	if (data->map[data->i_p][data->j_p - 1] != '1'
		&& data->map[data->i_p][data->j_p - 1] != 'E')
	{
		data->map[data->i_p][data->j_p - 1] = 'P';
		data->map[data->i_p][data->j_p] = '0';
		data->j_p--;
		display_map (data);
		ft_printf ("Moves: %d\n", i);
	}
}

void	move_up(t_map *data, int i)
{
	check_p_e_c(data->map, data, 0);
	if (data->map[data->i_p - 1][data->j_p] == 'E' && data->temp_c == 0)
	{
		data->map[data->i_p][data->j_p] = '0';
		display_map(data);
		ft_printf("Moves: %d\n", i);
		mlx_loop_end(data->mlx_ptr);
	}
	if (data->map[data->i_p - 1][data->j_p] != '1'
		&& data->map[data->i_p - 1][data->j_p] != 'E')
	{
		data->map[data->i_p - 1][data->j_p] = 'P';
		data->map[data->i_p][data->j_p] = '0';
		data->i_p--;
		display_map (data);
		ft_printf ("Moves: %d\n", i);
	}
}

void	move_down(t_map *data, int i)
{
	check_p_e_c(data->map, data, 0);
	if (data->map[data->i_p + 1][data->j_p] == 'E' && data->temp_c == 0)
	{
		data->map[data->i_p][data->j_p] = '0';
		display_map(data);
		ft_printf("Moves: %d\n", i);
		mlx_loop_end(data->mlx_ptr);
	}
	if (data->map[data->i_p + 1][data->j_p] != '1'
		&& data->map[data->i_p + 1][data->j_p] != 'E')
	{
		data->map[data->i_p + 1][data->j_p] = 'P';
		data->map[data->i_p][data->j_p] = '0';
		data->i_p++;
		display_map(data);
		ft_printf("Moves: %d\n", i);
	}
}
