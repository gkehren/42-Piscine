/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:04:22 by afelten           #+#    #+#             */
/*   Updated: 2022/02/13 14:56:47 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

typedef unsigned short	t_ushort;
typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;

// mem.c

void		ft_memcpy(void *src, void *dst, t_uint n);

// bits.c

t_uint		ft_count_ones(t_ushort x);
t_ushort	ft_first_bits(t_uint n);
t_ushort	ft_bit(t_uint n);
int			ft_bit_is_one(t_ushort x, t_uint n);
void		ft_set_bit(t_ushort *x, t_uint n, int one);

// board_edges.c

t_ushort	ft_board_up(t_ushort *board, t_uint n, t_uint x, t_uint y);
t_ushort	ft_board_left(t_ushort *board, t_uint n, t_uint x, t_uint y);
t_ushort	ft_board_down(t_ushort *board, t_uint n, t_uint x, t_uint y);
t_ushort	ft_board_right(t_ushort *board, t_uint n, t_uint x, t_uint y);

// board_tiles.c

t_ushort	*ft_board_tile(t_ushort *board, t_uint n, t_uint x, t_uint y);
t_uchar		ft_tile_value(t_ushort tile);

// ft_parse_input.c

int			ft_get_len_input(char *input);
int			ft_initialize_tab(char *input, t_uint n, t_ushort *tab);
t_ushort	*ft_parse_input(char *input, t_uint *n);

// print_board.c

void		ft_putchar(char c);
void		ft_print_board(t_ushort *board, t_uint n);

// resolve.c

int			ft_resolve(t_ushort *board, t_uint n);

// resolve_place.c

void		ft_place(t_ushort *board, t_uint n, t_uint x, t_uint y);
int			ft_place_singles(t_ushort *board, t_uint n);
int			ft_place_alones(t_ushort *board, t_uint n);

// resolve_init.c

void		ft_init_tile_with(
				t_ushort *tile,
				t_ushort number,
				t_uint distance,
				t_uint n);
void		ft_init_tile(t_ushort *board, t_uint n, t_uint x, t_uint y);
void		ft_resolve_init(t_ushort *board, t_uint n);

// check_board.c

int			ft_check_board(t_ushort *board, t_uint n);

// backtrack.c

int			ft_backtrack_pos(t_ushort *board, t_uint n, t_uint *x, t_uint *y);
int			ft_backtrack(t_ushort *board, t_uint n, t_uint x, t_uint y);

#endif
