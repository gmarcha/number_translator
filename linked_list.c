/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:50:58 by gamarcha          #+#    #+#             */
/*   Updated: 2021/03/28 14:08:22 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void				ft_free_list(t_list *begin_list)
{
	t_list			*node;

	if (!begin_list)
		return ;
	while (begin_list)
	{
		node = begin_list;
		begin_list = begin_list->next;
		free(node->data);
		free(node);
	}
}

void				ft_print_list(t_list *begin_list)
{
	if (!begin_list)
		return ;
	while (begin_list)
	{
		if (!begin_list->next)
			if (ft_strcmp(begin_list->data, ", ") == 0)
			{
				write(1, "\n", 1);
				return ;
			}
		ft_putstr((char *)begin_list->data);
		begin_list = begin_list->next;
	}
	write(1, "\n", 1);
}

t_list				*ft_create_element(void *data)
{
	t_list			*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (0);
	node->next = 0;
	node->data = ft_strdup((char *)data);
	return (node);
}

t_list				*ft_list_push_back(t_list **begin_list, void *data)
{
	t_list			*node;

	if (!*begin_list)
	{
		if (!(*begin_list = ft_create_element(data)))
			return (0);
	}
	else
	{
		node = *begin_list;
		while (node->next)
			node = node->next;
		if (!(node->next = ft_create_element(data)))
			return (0);
	}
	return (*begin_list);
}

void				ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list			*node;
	t_list			*curr;

	node = *begin_list1;
	*begin_list1 = begin_list2;
	curr = *begin_list1;
	while (curr->next)
		curr = curr->next;
	curr->next = node;
}
