/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:55:16 by lpires-n          #+#    #+#             */
/*   Updated: 2022/07/01 07:08:53 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_to_char(t_node **list, char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		append_node_back(list, str[index]);
		index++;
	}
}

char	*pointer_to_hex(void *pointer)
{
	char				*string_number;
	unsigned long int	number;
	if (pointer == NULL)
		return ("(nil)");
	number = (unsigned long int)pointer;
	string_number = ft_itohex(number, 'x');
	return (ft_strjoin("0x", string_number));
}
