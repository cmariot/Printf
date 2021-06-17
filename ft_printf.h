/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:56:06 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/17 09:39:16 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags
{
	int already_print;
	int type;
	int width;
	int minus;
	int zero;
	int dot;
	int star;
} t_flags

int	ft_printf(const char *, ...);
int	ft_is_in_type_list(int c);
int	ft_is_in_flags_list(int c);
int	ft_treatment(int c, t_flags flags, va_list args);
int	ft_treat_width(int width, int minus, int has_zero);
//...
int	ft_putchar(int c);
int	ft_treat_pointer(unsigned long long pointer, t_flags flags);
char 	*ft_ull_base(unsigned long long ull, int base);
char	*ft_u_itoa(unsigned int n);
char	*ft_str_tolower(char *str);
t_flags	ft_flag_minus(t_flags flags);
t_flags	ft_flag_width(va_list args, t_flags flags);
t_flags	ft_flag_digit(char c, t_flags flags);

/*
int	ft_simple_printing(const char * fornat, va_list va_obj);
int	ft_character_printing(const char *format);
int	ft_putchar_ret(int c);
int	ft_percent_percent(const char *format);
int	ft_percent_char(const char *format, char c);
int	ft_putstr_ret(const char *format);
int	ft_putnbr_ret(int nb);
char *ft_itoa(int nb);*/

#endif
