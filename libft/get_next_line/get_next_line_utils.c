/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:01:39 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/13 17:09:08 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	nouvelle_ligne(k_list *reserve)
{
	int		i;
	k_list	*current;

	if (reserve == NULL)
		return (0);
	current = dernier_maillon(reserve);
	i = 0;
	while (current -> content[i])
	{
		if (current -> content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

k_list	*dernier_maillon(k_list *reserve)
{
	k_list	*current;

	current = reserve;
	while (current && current -> next)
		current = current -> next;
	return (current);
}

void	malloc_ligne(char **line, k_list *reserve)
{
	int	i;
	int	len;

	len = 0;
	while (reserve)
	{
		i = 0;
		while (reserve -> content[i])
		{
			if (reserve -> content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		reserve = reserve -> next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	if (*line == NULL)
		return ;
}

void	free_reserve(k_list *reserve)
{
	k_list	*current;
	k_list	*next;

	current = reserve;
	while (current)
	{
		free(current -> content);
		next = current -> next;
		free(current);
		current = next;
	}
}
