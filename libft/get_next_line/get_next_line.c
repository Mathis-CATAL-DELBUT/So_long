/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:02:07 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/15 10:24:44 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_read(int fd, k_list **reserve)
{
	char	*buf;
	int		lecture;

	lecture = 1;
	while (!nouvelle_ligne(*reserve) && lecture != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		lecture = read(fd, buf, BUFFER_SIZE);
		if ((*reserve == NULL && lecture == 0) || lecture == -1)
		{
			free(buf);
			return ;
		}
		buf[lecture] = '\0';
		ajt_reserve(reserve, buf, lecture);
		free(buf);
	}
}

void	ajt_reserve(k_list **reserve, char *buf, int lecture)
{
	int		i;
	k_list	*dernier;
	k_list	*nouveau_maillon;

	nouveau_maillon = malloc(sizeof(k_list));
	if (nouveau_maillon == NULL)
		return ;
	nouveau_maillon -> next = NULL;
	nouveau_maillon -> content = malloc(sizeof(char) * (lecture + 1));
	if (nouveau_maillon -> content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < lecture)
	{
		nouveau_maillon -> content[i] = buf[i];
		i++;
	}
	nouveau_maillon -> content[i] = '\0';
	if (*reserve == NULL)
	{
		*reserve = nouveau_maillon;
		return ;
	}
	dernier = dernier_maillon(*reserve);
	dernier -> next = nouveau_maillon;
}

void	ligne(k_list *reserve, char **line)
{
	int	i;
	int	j;

	if (reserve == NULL)
		return ;
	malloc_ligne(line, reserve);
	j = 0;
	while (reserve)
	{
		i = 0;
		while (reserve -> content[i])
		{
			if (reserve -> content[i] == '\n')
			{
				(*line)[j++] = reserve -> content[i];
				break ;
			}
			(*line)[j++] = reserve -> content[i++];
		}
		reserve = reserve -> next;
	}
	(*line)[j] = '\0';
}

void	nv_reserve(k_list **reserve)
{
	k_list	*last;
	k_list	*clean_reserve;
	int		i;
	int		j;

	clean_reserve = malloc(sizeof(k_list));
	if (reserve == NULL || clean_reserve == NULL)
		return ;
	clean_reserve -> next = NULL;
	last = dernier_maillon(*reserve);
	i = 0;
	while (last -> content[i] && last -> content[i] != '\n')
		i++;
	if (last -> content && last -> content[i] == '\n')
		i++;
	clean_reserve -> content = malloc(sizeof(char)
			* ((ft_strlen(last -> content) - i) + 1));
	if (clean_reserve -> content == NULL)
		return ;
	j = 0;
	while (last -> content[i])
		clean_reserve -> content[j++] = last -> content[i++];
	clean_reserve -> content[j] = '\0';
	free_reserve(*reserve);
	*reserve = clean_reserve;
}

char	*get_next_line(int fd)
{
	static k_list	*reserve = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	ft_read(fd, &reserve);
	if (reserve == NULL)
		return (NULL);
	ligne(reserve, &line);
	nv_reserve(&reserve);
	if (line[0] == '\0')
	{
		free_reserve(reserve);
		reserve = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
