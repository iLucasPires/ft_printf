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

static void	verify_type(int format, t_node **my_node, va_list *test)
{
	if (format == 's')
		string_to_char(my_node, va_arg(*test, char *));
	else if (format == 'c')
		append_node_back(my_node, va_arg(*test, int));
	else if (format == 'i' || format == 'd')
		string_to_char(my_node, ft_itoa(va_arg(*test, int)));
	else if (format == 'u')
		string_to_char(my_node, ft_uitoa(va_arg(*test, int)));
	else if (format == 'x' || format == 'X')
		string_to_char(my_node, ft_itohex(va_arg(*test, int), format));
	else if (format == 'p')
		string_to_char(my_node, pointer_to_hex(va_arg(*test, void *)));
}

void	ft_printf(const char *format, ...)
{
	t_node	*my_node;
	va_list	list_format;
	int		index;

	index = 0;
	my_node = NULL;
	va_start(list_format, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			if (format[index] == '%')
				append_node_back(&my_node, format[index]);
			verify_type(format[index], &my_node, &list_format);
		}
		else
			append_node_back(&my_node, format[index]);
		index++;
	}
	printf_node(&my_node);
	free_all(&my_node);
	va_end(list_format);
}
