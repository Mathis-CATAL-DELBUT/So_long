/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:17:47 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/22 19:22:57 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "so_long.h"

int	up_down(t_map *data, int i, int j, int modify)
{
	if (data->temp_map[i - 1][j] != '1' && data->temp_map[i - 1][j] != 'X')
	{
		if (data->temp_map[i - 1][j] == 'E')
			data->temp_map[i - 1][j] = '1';
		else
			data->temp_map[i - 1][j] = 'X';
		modify++;
	}
	if (data->temp_map[i + 1][j] != '1' && data->temp_map[i + 1][j] != 'X')
	{
		if (data->temp_map[i + 1][j] == 'E')
			data->temp_map[i + 1][j] = '1';
		else
			data->temp_map[i + 1][j] = 'X';
		modify++;
	}
	return (modify);
}

int	change(t_map *data, int i, int j, int modify)
{
	modify = up_down(data, i, j, modify);
	if (data->temp_map[i][j + 1] != '1' && data->temp_map[i][j + 1] != 'X')
	{
		if (data->temp_map[i][j + 1] == 'E')
			data->temp_map[i][j + 1] = '1';
		else
			data->temp_map[i][j + 1] = 'X';
		modify++;
	}
	if (data->temp_map[i][j - 1] != '1' && data->temp_map[i][j - 1] != 'X')
	{
		if (data->temp_map[i][j - 1] == 'E')
			data->temp_map[i][j - 1] = '1';
		else
			data->temp_map[i][j - 1] = 'X';
		modify++;
	}
	return (modify);
}

int	coordinates(t_map *data, char **map, int modify)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->len_line)
	{
		j = -1;
		while (++j < data->len_column)
		{
			if (map[i][j] == 'P' || map[i][j] == 'X')
				modify = change(data, i, j, modify);
		}
	}
	return (modify);
}

int	valid_path(t_map *data)
{
	int	modify;

	data->c = 0;
	data->p = 0;
	data->e = 0;
	modify = 1;
	while (modify > 0)
	{
		modify = 0;
		modify = coordinates(data, data->temp_map, modify);
	}
	check_p_e_c(data->temp_map, data, 0);
	if (data->c != 0 || data->e != 0)
	{
		data->good_map = 0;
		return (ft_printf("Tous les items ne sont pas accessibles\n"), 0);
	}
	return (1);
}
