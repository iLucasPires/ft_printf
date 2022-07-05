/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:33:01 by lpires-n          #+#    #+#             */
/*   Updated: 2022/07/01 07:10:01 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	char			*value;
	struct s_node	*next;
}					t_node;

typedef struct s_types
{
	int				integer;
	int				index;
	int				start;
	char			character;
	char			*string;
	char			*number_string;
}					t_types;

int					ft_printf(const char *format, ...);
void				printf_node(t_node **list);
char				*ft_itohex(unsigned long int nb, char type);
char				*pointer_to_hex(void *pointer);
char				*ft_uitoa(unsigned int nbr);
int					counter_node(t_node *list);

void				append_node_back(t_node **list, char *value);
void				free_all(t_node **list);
unsigned long int	ft_ptoi(void *pointer);

// handle types
void				add_string_node(t_node **list, char *str);
void				add_number_node(t_node **list, int number, char type);
void				add_void_node(t_node **list, void *pointer);
void				add_hex_node(t_node **list, int number, char type);
void				add_char_node(t_node **list, char character);
#endif