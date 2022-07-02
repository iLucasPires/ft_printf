/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 06:58:03 by lpires-n          #+#    #+#             */
/*   Updated: 2022/07/01 07:04:38 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	append_node_back(t_node **list, int value)
{
	t_node	*aux;
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->value = value;
	node->next = NULL;
	if (!*list)
		*list = node;
	else
	{
		aux = *list;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = node;
	}
}

void	free_all(t_node **list)
{
	t_node	*aux;
	t_node	*to_free;

	aux = list[0];
	while (aux != NULL)
	{
		to_free = aux;
		aux = aux->next;
		free(to_free);
	}
}

int	counter_node(t_node *list)
{
	int	counter;

	counter = 0;
	while (list != NULL)
	{
		list = list->next;
		counter++;
	}
	return (counter);
}

void	printf_node(t_node **list)
{
	char	*string_node;
	t_node	*aux;
	int		size;
	int		index;

	index = 0;
	aux = list[0];
	size = counter_node(aux);
	string_node = malloc(sizeof(char *) * (size));
	while (aux != NULL)
	{
		string_node[index] = aux->value;
		aux = aux->next;
		index++;
	}
	string_node[index] = '\0';
	write(1, string_node, size);
	free(string_node);
}
