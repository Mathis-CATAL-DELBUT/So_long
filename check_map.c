/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:39:26 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/23 19:14:39 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

int	check_line_full_1(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_line_first_last_1(char *line, t_map *data)
{
	if (line[0] != '1' || line[data->len_column - 2] != '1')
		return (0);
	return (1);
}

int	check_p_e_c(char **map, t_map *data, int i, int e)
{
	int	j;
	int	p;
	int	c;

	p = 0;
	c = 0;
	while (++i < data->len_line - 1)
	{
		j = -1;
		while (++j < data->len_column)
		{
			if (map[i][j] == 'P')
			{
				p++;
				data->i_p = i;
				data->j_p = j;
			}
			else if (map[i][j] == 'E')
				e++;
			else if (map[i][j] == 'C')
				c++;
		}
	}
	put(data, e, c);
	return (p == 1 && e == 1 && c > 0);
}

int	check_len_line(char *line, t_map *data)
{
	int	i;

	i = 0;
	if (ft_strlen2(line) != (size_t)data->len_column - 1)
		return (0);
	while (line[i])
	{
		if (line[i] != 'P' && line[i] != 'C' && line[i] != 'E' && line[i] != '0'
			&& line[i] != '1' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_map *data)
{
	int	i;

	i = 0;
	if (check_line_full_1(data->map[0]) == 0
		|| check_line_full_1(data->map[data->len_line - 1]) == 0
		|| check_p_e_c(data->map, data, 0, 0) == 0)
	{
		data->good_map = 0;
		return (0);
	}
	while (i < data->len_line)
	{
		if (check_line_first_last_1(data->map[i], data) == 0)
		{
			data->good_map = 0;
			return (0);
		}
		i++;
	}
	data->good_map = 1;
	return (1);
}
