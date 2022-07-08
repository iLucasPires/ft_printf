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
// #include "libft/libft.h"
#include <stdlib.h>

static void	verify_type(char format, t_node **my_node, va_list list_arg)
{
	if (format == 's')
		add_string_node(my_node, va_arg(list_arg, char *));
	else if (format == 'i' || format == 'd')
		add_number_node(my_node, va_arg(list_arg, int), format);
	else if (format == 'x' || format == 'X')
		add_hex_node(my_node, va_arg(list_arg, int), format);
	else if (format == 'u')
		add_number_node(my_node, va_arg(list_arg, int), format);
	else if (format == 'p')
		add_void_node(my_node, va_arg(list_arg, void *));
	else if (format == 'c')
		add_char_node(my_node, va_arg(list_arg, int));
	else if (format == '%')
		add_char_node(my_node, '%');
}

static void	ft_add_node(t_node **my_node, const char *format, va_list list_arg)
{
	t_types	aux;

	aux.index = 0;
	aux.start = 0;
	while ((int)ft_strlen(format) >= aux.index)
	{
		if (format[aux.index] == '%' || format[aux.index] == '\0')
		{
			aux.len = aux.index - aux.start;
			aux.string = ft_substr(format, aux.start, aux.len);
			append_node_back(my_node, aux.string, aux.len);
			if (format[aux.index] != '\0')
			{
				aux.index = aux.index + 1;
				verify_type(format[aux.index], my_node, list_arg);
			}
			aux.start = aux.index + 1;
			free(aux.string);
		}
		aux.index = aux.index + 1;
	}
}

int	ft_printf(const char *format, ...)
{
	t_node	*my_node;
	va_list	list_args;

	my_node = NULL;
	va_start(list_args, format);
	ft_add_node(&my_node, format, list_args);
	va_end(list_args);
	return (printf_node(&my_node));
}
