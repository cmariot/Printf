/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_and_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:12:52 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/28 18:08:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_space_before(t_flags *flags, int len, char *str)
{
	char	c;
	int		i;

	c = ' ';
	if (flags->zero && ((!flags->dot) || (flags->precision < 0)))
		c = ft_c_is_zero(flags, str);
	i = 0;
	if (flags->plus && ft_isdigit(*str))
		len++;
	if (flags->field_width > flags->precision)
	{
		if (flags->dot && !flags->precision)
			if (flags->field_width > len)
				if (flags->minus_printed)
					len--;
		if (flags->precision >= len)
			ft_print_fw(flags, str, i, c);
		else if (flags->field_width > len)
			while (flags->field_width-- - len)
				flags->total_print += ft_putchar(c);
		if (flags->precision >= len || flags->field_width > len)
			flags->blank = 0;
	}
	flags->field_width = 0;
}

void	ft_space_after(t_flags *flags, int len)
{
	int		i;
	char	c;

	c = ' ';
	i = 0;
	if (flags->field_width > flags->precision)
	{
		if (flags->dot && (flags->field_width > len) && !flags->precision)
			while (flags->field_width-- - len)
				flags->total_print += ft_putchar(c);
		else if (flags->precision > len)
		{
			if (flags->minus_printed)
				i++;
			while ((flags->field_width - flags->precision) - i++)
				flags->total_print += ft_putchar(c);
		}
		else if (flags->field_width > len)
		{
			if (flags->minus_printed)
				len++;
			while (flags->field_width-- - len)
				flags->total_print += ft_putchar(c);
		}
	}
}

int	ft_len_of_print(char *str, t_flags *flags)
{
	int	len;

	len = ft_strlen(str);
	if (flags->dot)
	{
		if (flags->precision)
		{
			if (flags->precision > len)
			{
				while (flags->precision - len)
					len++;
				if (*str == '-')
					len--;
			}
		}
		else if (!flags->precision && !flags->hashtag)
			while (*str++ == '0')
				len--;
	}
	if (flags->hashtag && flags->precision >= len)
		len += 2;
	if (flags->blank && flags->field_width > len)
		len += 1;
	return (len);
}

int	ft_print_minus(t_flags *flags)
{
	if (!flags->minus_printed)
		flags->total_print += ft_putchar('-');
	flags->minus_printed = 1;
	return (1);
}

void	ft_print_precision(t_flags *flags, char **str, int initial_len)
{
	int	i;

	i = 0;
	if (flags->hashtag)
		initial_len -= ft_print_0x(flags, &str);
	if (flags->precision >= initial_len)
	{
		if (flags->pointer)
			initial_len -= ft_print_0x(flags, &str);
		if (**str == '-')
			initial_len -= ft_print_minus(flags);
		while (flags->precision - initial_len - i++)
			flags->total_print += ft_putchar('0');
	}
	else if (flags->precision == 0)
	{
		if (flags->pointer)
			ft_print_0x(flags, &str);
		while (**str == '0')
			(*str)++;
	}
}
