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

static int	ft_cont_digits(size_t number, int base)
{
	int	counter;

	counter = 1;
	if (number == 0)
		return (1);
	while (number / base > 0)
	{
		counter++;
		number = number / base;
	}
	return (counter);
}

char	*ft_uitoa(unsigned int number)
{
	t_types	aux;

	aux.len = ft_cont_digits(number, 10);
	aux.string = malloc(sizeof(char) * (aux.len + 1));
	if (!aux.string)
		return (NULL);
	aux.string[aux.len] = '\0';
	while (aux.len)
	{
		aux.string[--aux.len] = '0' + (number % 10);
		number = number / 10;
	}
	return (aux.string);
}

char	*ft_itohex(unsigned int number, char type)
{
	t_types	aux;

	if (type == 'x')
		aux.aux = ft_strdup("0123456789abcdef");
	else if (type == 'X')
		aux.aux = ft_strdup("0123456789ABCDEF");
	aux.len = ft_cont_digits(number, 16);
	aux.string = malloc(sizeof(char) * (aux.len + 1));
	aux.string[aux.len] = '\0';
	while (aux.len--)
	{
		aux.string[aux.len] = aux.aux[number % 16];
		number /= 16;
	}
	free(aux.aux);
	return (aux.string);
}

char	*ft_itop(size_t number)
{
	t_types	aux;

	aux.aux = ft_strdup("0123456789abcdef");
	aux.len = ft_cont_digits(number, 16);
	aux.string = malloc(sizeof(char) * (aux.len + 1));
	aux.string[aux.len] = '\0';
	while (aux.len--)
	{
		aux.string[aux.len] = aux.aux[number % 16];
		number /= 16;
	}
	free(aux.aux);
	return (aux.string);
}
