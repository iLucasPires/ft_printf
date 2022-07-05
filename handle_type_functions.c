#include "ft_printf.h"

void	add_number_node(t_node **list, int number, char type)
{
	char	*number_string;

	if (type == 'i' || type == 'd')
		number_string = ft_itoa(number);
	if (type == 'u')
		number_string = ft_uitoa(number);
	append_node_back(list, number_string);
	free(number_string);
}

void	add_char_node(t_node **list, char character)
{
	char	*char_string;

	char_string = malloc(sizeof(char) + 1);
	char_string[0] = character;
	char_string[1] = '\0';
	append_node_back(list, char_string);
	free(char_string);
}

void	add_void_node(t_node **list, void *pointer)
{
	char				*hex_string;
	char				*aux;
	unsigned long int	number;

	number = (unsigned long int)pointer;
	aux = ft_itohex(number, 'x');
	hex_string = ft_strjoin("0x", aux);
	append_node_back(list, hex_string);
	free(hex_string);
	free(aux);
}

void	add_hex_node(t_node **list, int number, char type)
{
	char	*hex_string;

	hex_string = ft_itohex(number, type);
	append_node_back(list, hex_string);
	free(hex_string);
}
