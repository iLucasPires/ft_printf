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

static int	ft_cont_digits(unsigned int nbr)
{
	int	counter;

	counter = 0;
	while (nbr)
	{
		counter++;
		nbr = nbr / 10;
	}
	return (counter);
}

char	*ft_uitoa(unsigned int nbr)
{
	char	*number_string;
	int		number_len;

	if (nbr == 0)
		return (NULL);
	number_len = ft_cont_digits(nbr);
	number_string = malloc(sizeof(char) * (number_len + 1));
	if (!number_string)
		return (NULL);
	while (nbr)
	{
		number_string[--number_len] = '0' + (nbr % 10);
		nbr = nbr / 10;
	}
	return (number_string);
}
