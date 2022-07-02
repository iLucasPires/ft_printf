#include "ft_printf.h"

void	add_string_node(t_node **list, char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		append_node_back(list, str[index]);
		index++;
	}
}

void	add_number_node(t_node **list, int number, char type)
{
	char	*number_string;

	if (type == 'i' || type == 'd')
		number_string = ft_itoa(number);
	if (type == 'u')
		number_string = ft_uitoa(number);
	add_string_node(list, number_string);
	free(number_string);
}

void	add_void_node(t_node **list, void *pointer)
{
	char				*hex_string;
	char				*aux;
	unsigned long int	number;

	number = (unsigned long int)pointer;
	aux = ft_itohex(number, 'x');
	hex_string = ft_strjoin("0x", aux);
	add_string_node(list, hex_string);
	free(hex_string);
	free(aux);
}

void	add_hex_node(t_node **list, int number, char type)
{
	char	*hex_string;

	hex_string = ft_itohex(number, type);
	add_string_node(list, hex_string);
	free(hex_string);
}
