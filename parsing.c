/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:46:12 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/22 18:42:38 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "so_long.h"

char	**free_all_tab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

void	first_call_gnl(t_map *data)
{
	int		fd;
	char	*res;

	fd = open("map/premiere.ber", O_RDONLY);
	res = get_next_line(fd);
	if (!res)
	{
		data->len_column = 0;
		return ;
	}
	data->len_column = ft_strlen(res);
	data->len_line = 1;
	free(res);
	res = get_next_line(fd);
	while (res)
	{
		free(res);
		data->len_line++;
		res = get_next_line(fd);
	}
	free(res);
	close(fd);
}

int	second_call_gnl(t_map *data, char **map, int line, int i)
{
	char	*res;
	int		good_len;
	int		j;

	j = 0;
	good_len = 1;
	while (j < data->len_line)
	{
		map[j] = malloc(sizeof(char) * data->len_column + 1);
		if (!map[j])
			return (free_all_tab(map, j), 0);
		map[j][data->len_column] = 0;
		res = get_next_line(line);
		if (check_len_line(res, data) == 0)
			good_len = 0;
		ft_strlcpy(map[j], res, data->len_column);
		free(res);
		j++;
	}
	if (i == 1)
		data->map = map;
	else
		data->temp_map = map;
	return (good_len);
}

void	parsing(t_map *data)
{
	char	**map;
	int		good_len;
	int		line;
	char	*res;

	first_call_gnl(data);
	if (data->len_column <= 2)
		return ;
	map = malloc(sizeof(char *) * data->len_line);
	if (!map)
		return ;
	line = open("map/premiere.ber", O_RDONLY);
	good_len = second_call_gnl(data, map, line, 1);
	res = get_next_line(line);
	free(res);
	close(line);
	if (good_len == 1 && check_map(data))
		data->good_map = 1;
	else
		data->good_map = 0;
}

void	temp_parsing(t_map *data)
{
	char	**temp_map;
	int		line;
	char	*res;

	first_call_gnl(data);
	if (data->len_column <= 2)
		return ;
	temp_map = malloc(sizeof(char *) * data->len_line);
	if (!temp_map)
		return ;
	line = open("map/premiere.ber", O_RDONLY);
	second_call_gnl(data, temp_map, line, 2);
	res = get_next_line(line);
	free(res);
	close(line);
}
