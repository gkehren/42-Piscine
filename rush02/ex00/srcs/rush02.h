/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:42:59 by gkehren           #+#    #+#             */
/*   Updated: 2022/02/20 17:55:10 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define SDICO 41
# define BUF 32

typedef unsigned int	t_uint;
typedef struct s_dico_elem
{
	unsigned int	value;
	char			*str_val;
}	t_dico_elem;

// dico_reader.c

int				ft_count_line(char *file, int *size);
void			write_file_in_tab(char *file, int nb_char, char **all_file);
int				is_in_dico(char *str_number, t_dico_elem *dico_ref, int count);
t_dico_elem		*ft_complete_dico_new(char **split, t_dico_elem *dico_ref);
t_dico_elem		*ft_parse_new_dico(char *input_dico, t_dico_elem *dico_ref);
void			ft_complete_dico(t_dico_elem **dico, char **split);
t_dico_elem		*ft_parse_dico(char *input_dico);
t_dico_elem		ft_put_elem(char *value, char *word);

// ft_print_my_number.c & ft_print_my_number2.c

int				ft_check_number(char *str, int *minus);
int				ft_intlen(unsigned int number);
int				ft_is_in_dico(unsigned int number, t_dico_elem *dico);
unsigned int	ft_power(unsigned int nb, unsigned int power);
void			ft_putdico(unsigned int number, t_dico_elem *dico);
void			cut_nb(t_uint number, t_uint len, t_dico_elem *dico,
					int *trigr);
void			ft_print_my_number(t_dico_elem *dico, char *number);

// ft_atoi.c

long int		ft_atoi(char *str);
int				ft_is_numeric(char str);
int				ft_result(int minus, int result);

// ft_split.c

char			**ft_split(char *str);
int				ft_is_charset(char c);
int				ft_count_letter(char *str, int *position);
char			*ft_putword(char *str, int *position);
int				ft_count_word(char *str);

//print number
void			ft_print_my_number(t_dico_elem *dico, char *number);

//putstr
int				display_error(void);
void			ft_putstr(char *str);

// strdup
char			*ft_strdup(char *src);

#endif
