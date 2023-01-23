/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:44:47 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/22 19:19:06 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>

typedef struct m_list
{
	int		len_line;
	int		len_column;
	int		good_map;
	char	**map;
	char	**temp_map;

	int		e;
	int		c;
	int		temp_c;
	int		p;

	void	*img_player;
	void	*img_floor;
	void	*img_wall;
	void	*img_coin;
	void	*img_exit;

	int		i_p;
	int		j_p;

	void	*mlx_ptr;
	void	*win_ptr;
}			t_map;

char		**free_all_tab(char **tab, int i);
void		first_call_gnl(t_map *data);
int			second_call_gnl(t_map *data, char **map, int line, int i);
void		parsing(t_map *data);
void		temp_parsing(t_map *data);

int			check_line_full_1(char *line);
int			check_line_first_last_1(char *line, t_map *data);
int			check_p_e_c(char **map, t_map *data, int i);
int			check_map(t_map *data);
int			check_len_line(char *line, t_map *data);

int			change(t_map *data, int i, int j, int modify);
int			coordinates(t_map *data, char **map, int modify);
int			valid_path(t_map *data);

int			handle_keypress(int keysym, t_map *data);
int			init(t_map *data);
void		display_map(t_map *data);

void		move_right(t_map *data, int i);
void		move_left(t_map *data, int i);
void		move_up(t_map *data, int i);
void		move_down(t_map *data, int i);

#endif