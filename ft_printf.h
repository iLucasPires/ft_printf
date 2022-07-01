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
	char			value;
	struct s_node	*next;
}					t_node;

typedef struct s_types
{
	int				integer;
	int				index;
	char			character;
	char			*string;
	char			*number_string;
}					t_types;

void				ft_printf(const char *format, ...);
void				printf_node(t_node **list);
char				*ft_itohex(unsigned long int nb, char hex_type);
char				*pointer_to_hex(void *pointer);
char				*ft_uitoa(unsigned int nbr);
void				string_to_char(t_node **list, char *str);
void				append_node_front(t_node **list, int value);
void				append_node_back(t_node **list, int value);
void				show_node(t_node **list);
void				delete_front(t_node **list);
void				delete_end(t_node **list);
void				free_all(t_node **list);
unsigned long int	ft_ptoi(void *pointer);

#endif