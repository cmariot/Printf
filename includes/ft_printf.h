/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 23:26:23 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/30 21:35:47 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define INT_MIN	-2147483648
# define INT_MAX	2147483647

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_flags
{
	va_list	args;
	int		minus;
	int		zero;
	int		star_for_field_width;
	int		field_width;
	int		dot;
	int		star_for_precision;
	int		precision;
	int		total_print;
}	t_flags;

/* This functiun works like the printf function. */
int				ft_printf(const char *format, ...);
/* All the struct variables are set to 0. */
t_flags			*ft_initialize_flags(t_flags *flags);
/* Reset the struct variables to zero. */
t_flags			*ft_reset_struct(t_flags *flags);
/* Print a char and return 1. */
int				ft_putchar(int c);
/* When we see a '%' we check the flags and put data in the structure. */
unsigned int	ft_chck_flgs(const char *frmt, t_flags *flgs, unsigned int i);
/* We check if the specifier is correct */
int				ft_is_in_type_list(int c);
/* We call the right function for the specifier */
void			ft_chck_type(const char *frmt, unsigned int i, t_flags *flgs);
/* If %c print a char */
void			ft_print_char(t_flags *flags);
/* If %s print a str */
void			ft_print_str(t_flags *flags);
/* If %u print a unsigned int */
void			ft_print_unsigned_int(t_flags *flags);
/* If %d or %i print an integer */
void			ft_print_integer(t_flags *flags);
/* If %x convert an unsigned int to hexa (0123456789abcdef) */
void			ft_print_hexa(t_flags *flags);
/* If %X convert an unsigned int to hexa (0123456789ABCDEF) */
void			ft_print_hexa_maj(t_flags *flags);
/* If %p print the memory */
void			ft_print_addr(t_flags *flags);
/* If there is a flag that specifies a field width */
void			ft_print_space(t_flags *flags, int len);
/* If there is a star flag we take a va_arg as field width */
void			ft_field_width_star(t_flags *flags);
/* If there is a star flag after the dot flag the va_arg is for the precision */
void			ft_precision_star(t_flags *flags);

#endif
