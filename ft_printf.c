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

static void	verify_type(int format, t_node **my_node, va_list test)
{
	if (format == 's')
		add_string_node(my_node, va_arg(test, char *));
	else if (format == 'c')
		append_node_back(my_node, va_arg(test, int));
	else if (format == 'i' || format == 'd')
		add_number_node(my_node, va_arg(test, int), format);
	else if (format == 'x' || format == 'X')
		add_hex_node(my_node, va_arg(test, int), format);
	else if (format == 'u')
		add_number_node(my_node, va_arg(test, int), format);
	else if (format == 'p')
		add_void_node(my_node, va_arg(test, void *));
}

void	ft_printf(const char *format, ...)
{
	t_node	*my_node;
	va_list	list_args;
	int		index;

	index = 0;
	my_node = NULL;
	va_start(list_args, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			if (format[index] == '%')
				append_node_back(&my_node, format[index]);
			verify_type(format[index], &my_node, list_args);
		}
		else if (format[index] != '%')
			append_node_back(&my_node, format[index]);
		index++;
	}
	printf_node(&my_node);
	free_all(&my_node);
	va_end(list_args);
}
