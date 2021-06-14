/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:56:06 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/14 13:44:42 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *, ...);
int	ft_simple_printing(const char * fornat, va_list va_obj);
int	ft_character_printing(const char *format);
int	ft_putchar_ret(int c);
int	ft_percent_percent(const char *format);
int	ft_percent_char(const char *format, char c);
int	ft_putstr_ret(const char *format);

#endif
