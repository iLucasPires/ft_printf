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

void	add_number_node(t_node **list, long int number, char type)
{
	t_types	aux;

	if (type == 'i' || type == 'd')
		aux.string = ft_itoa(number);
	else if (type == 'u')
		aux.string = ft_uitoa(number);
	aux.len = ft_strlen(aux.string);
	append_node_back(list, aux.string, aux.len);
	free(aux.string);
}

void	add_char_node(t_node **list, char character)
{
	t_types	aux;

	aux.string = malloc(sizeof(char) + 1);
	aux.string[0] = character;
	aux.string[1] = '\0';
	aux.len = 1;
	append_node_back(list, aux.string, aux.len);
	free(aux.string);
}

void	add_void_node(t_node **list, void *pointer)
{
	t_types	aux;
	size_t	number;

	if (pointer == NULL)
		append_node_back(list, "(nil)", 5);
	else
	{
		number = (size_t)pointer;
		aux.aux = ft_itop(number);
		aux.string = ft_strjoin("0x", aux.aux);
		aux.len = ft_strlen(aux.string);
		append_node_back(list, aux.string, aux.len);
		free(aux.string);
		free(aux.aux);
	}
}

void	add_hex_node(t_node **list, size_t number, char type)
{
	t_types	aux;

	aux.string = ft_itohex(number, type);
	aux.len = ft_strlen(aux.string);
	append_node_back(list, aux.string, aux.len);
	free(aux.string);
}

void	add_string_node(t_node **list, char *string)
{
	int	size;

	if (string == NULL)
		append_node_back(list, "(null)", 6);
	else
	{
		size = ft_strlen(string);
		append_node_back(list, string, size);
	}
}
