/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:39:28 by mcatal-d          #+#    #+#             */
/*   Updated: 2022/11/10 10:38:44 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nouveau;

	nouveau = (t_list *)malloc(sizeof(t_list));
	if (!nouveau)
		return (0);
	nouveau -> content = content;
	nouveau -> next = NULL;
	return (nouveau);
}
