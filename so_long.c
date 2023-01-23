/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:38:03 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/22 18:42:26 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "so_long.h"

// int	start(t_data **data)
// {
// 	(*data) = malloc()
// }

int	main(int argc, char **argv)
{
	t_map	data;

	(void)argc;
	(void)argv;
	data.map = NULL;
	data.len_line = 0;
	parsing(&data);
	temp_parsing(&data);
	if (!data.map || data.good_map == 0)
		return (free_all_tab(data.map, --data.len_line),
			free_all_tab(data.temp_map, data.len_line), 0);
	if (valid_path(&data) == 0)
		return (free_all_tab(data.map, --data.len_line),
			free_all_tab(data.temp_map, data.len_line), 0);
	init(&data);
	free_all_tab(data.map, --data.len_line);
	free_all_tab(data.temp_map, data.len_line);
}
