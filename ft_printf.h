/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:56:06 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/11 18:11:10 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *, ...);
int	ft_putchar_ret(int c);
int	ft_pourcent_char(const char *format, char c);

#endif
