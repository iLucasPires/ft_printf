/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:30:34 by lpires-n          #+#    #+#             */
/*   Updated: 2022/07/01 07:10:31 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

static void	verify_type(char format, t_node **my_node, va_list test)
{
	if (format == 's')
		append_node_back(my_node, va_arg(test, char *));
	else if (format == 'i' || format == 'd')
		add_number_node(my_node, va_arg(test, int), format);
	else if (format == 'x' || format == 'X')
		add_hex_node(my_node, va_arg(test, int), format);
	else if (format == 'u')
		add_number_node(my_node, va_arg(test, int), format);
	else if (format == 'p')
		add_void_node(my_node, va_arg(test, void *));
	else if (format == 'c')
		add_char_node(my_node, va_arg(test, int));
}

int	ft_printf(const char *format, ...)
{
	t_node	*my_node;
	va_list	list_args;
	t_types	aux;

	aux.index = 0;
	aux.start = 0;
	my_node = NULL;
	va_start(list_args, format);
	while ((int)ft_strlen(format) > aux.index)
	{
		aux.index++;
		if (format[aux.index] == '%' || format[aux.index] == '\0')
		{
			aux.string = ft_substr(format, aux.start, aux.index - aux.start);
			append_node_back(&my_node, aux.string);
			aux.index = aux.index + 1;
			verify_type(format[aux.index], &my_node, list_args);
			if (format[aux.index] == '%')
				add_char_node(&my_node, '%');
			aux.start = aux.index + 1;
			free(aux.string);
		}
	}
	printf_node(&my_node);
	free_all(&my_node);
	va_end(list_args);
	return (0);
}
