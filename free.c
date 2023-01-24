/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:16:20 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/23 16:00:22 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mlx.h"
#include "include/mlx_int.h"
#include "libft/libft.h"
#include "so_long.h"

void	free_mlx(t_map *data)
{
	if (data->img_player)
		mlx_destroy_image(data->mlx_ptr, data->img_player);
	if (data->img_coin)
		mlx_destroy_image(data->mlx_ptr, data->img_coin);
	if (data->img_exit)
		mlx_destroy_image(data->mlx_ptr, data->img_exit);
	if (data->img_wall)
		mlx_destroy_image(data->mlx_ptr, data->img_wall);
	if (data->img_floor)
		mlx_destroy_image(data->mlx_ptr, data->img_floor);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

char	**free_all_tab(char **tab, int index)
{
	while (index >= 0)
	{
		free(tab[index]);
		index--;
	}
	free(tab);
	return (NULL);
}
