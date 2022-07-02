/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 06:59:11 by lpires-n          #+#    #+#             */
/*   Updated: 2022/07/01 06:59:47 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_cont_digits(unsigned int nb, int base)
{
	int	counter;

	counter = 0;
	while (nb / base > 0)
	{
		counter++;
		nb = nb / base;
	}
	return (counter);
}

char	*ft_uitoa(unsigned int nb)
{
	char	*number_string;
	int		number_len;

	if (nb == 0)
		return (NULL);
	number_len = ft_cont_digits(nb, 10);
	number_string = malloc(sizeof(char) * (number_len + 1));
	if (!number_string)
		return (NULL);
	while (nb)
	{
		number_string[--number_len] = '0' + (nb % 10);
		nb = nb / 10;
	}
	return (number_string);
}

char	*ft_itohex(unsigned long int nb, char type)
{
	char	*hexmap;
	char	*new_str;
	size_t	size_hex;

	if (type == 'x')
		hexmap = ft_strdup("0123456789abcdef");
	else if (type == 'X')
		hexmap = ft_strdup("0123456789ABCDEF");
	size_hex = ft_cont_digits(nb, 10);
	new_str = (char *)malloc(sizeof(char) * (size_hex + 1));
	new_str[size_hex] = '\0';
	while (size_hex--)
	{
		new_str[size_hex] = hexmap[nb % 16];
		nb = nb / 16;
	}
	free(hexmap);
	return (new_str);
}
