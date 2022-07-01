/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:26:02 by lpires-n          #+#    #+#             */
/*   Updated: 2022/07/01 06:47:17 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_count_hex_size(unsigned long int nb)
{
	size_t	counter;

	counter = 1;
	while (nb >= 16)
	{
		nb /= 16;
		counter++;
	}
	return (counter);
}

char	*ft_itohex(unsigned long int nb, char hex_type)
{
	char	*hexmap;
	char	*new_str;
	size_t	size_hex;

	if (hex_type == 'x')
		hexmap = ft_strdup("0123456789abcdef");
	else if (hex_type == 'X')
		hexmap = ft_strdup("0123456789ABCDEF");
	size_hex = ft_count_hex_size(nb);
	new_str = malloc(sizeof(char) * (size_hex + 1));
	new_str[size_hex] = '\0';
	while (size_hex--)
	{
		new_str[size_hex] = hexmap[nb % 16];
		nb = nb / 16;
	}
	free(hexmap);
	return (new_str);
}
