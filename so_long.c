/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:20:35 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/23 19:32:06 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "so_long.h"

int	main(int argc, char **argv, char **env)
{
	t_map	data;

	if (!*env)
		return (ft_printf("Error\nNo environement\n"), 0);
	if (argc != 2 || argv[1][ft_strlen(argv[1]) - 1] != 'r'
		|| argv[1][ft_strlen(argv[1]) - 2] != 'e' || argv[1][ft_strlen(argv[1])
		- 3] != 'b' || argv[1][ft_strlen(argv[1]) - 4] != '.')
		return (ft_printf("Error\nInvalid map\n"), 0);
	data.map = NULL;
	data.temp_map = NULL;
	data.len_line = 0;
	if (parsing(&data, argv[1]) == 0)
		return (0);
	temp_parsing(&data, argv[1]);
	if (!data.map || data.good_map == 0)
		return (free_all_tab(data.map, (data.len_line - 1)),
			free_all_tab(data.temp_map, (data.len_line - 1)), 0);
	if (valid_path(&data) == 0)
		return (free_all_tab(data.map, (data.len_line - 1)),
			free_all_tab(data.temp_map, (data.len_line - 1)), 0);
	init(&data);
	free_mlx(&data);
	free_all_tab(data.map, (data.len_line - 1));
	free_all_tab(data.temp_map, (data.len_line - 1));
}
