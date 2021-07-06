/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:23:50 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/06 17:39:17 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_space_before_integer(t_flags *flags, int len, char *str)
{
	char	c;
	int		i;

	if (flags->zero && !flags->minus && !flags->precision)
	{
		c = '0';
		if (*str == '-')
		{
			flags->total_print += ft_putchar('-');
			flags->minus_printed = 1;
		}
	}
	else
		c = ' ';
	i = 0;
	if (flags->field_width > flags->precision)
	{
		if (flags->precision > len)
		{
			if (*str == '-')
				i++;
			while ((flags->field_width - flags->precision) - i++)
				flags->total_print += write(1, &c, 1);
		}
		else if (flags->field_width > len)
		{
			while (flags->field_width-- - len)
				flags->total_print += write(1, &c, 1);
		}
	}
	flags->field_width = 0;
	return ;
}

void	ft_space_after_integer(t_flags *flags, int len)
{
	int		i;
	char	c;

	c = ' ';
	i = 0;
	if (flags->field_width > flags->precision)
	{
		if (flags->precision > len)
		{
			if (flags->minus_printed)
				i++;
			while ((flags->field_width - flags->precision) - i++)
				flags->total_print += write(1, &c, 1);
		}
		else if (flags->field_width > len)
			while (flags->field_width-- - len)
				flags->total_print += write(1, &c, 1);
	}
	return ;
}


int		ft_printf_integer_len(char *str, t_flags *flags)
{
	int len;

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
	}
	return (len);
}

void	ft_treat_integer(char *str, t_flags *flags)
{
	int initial_len;
	int	final_len;
	int	i;

	//Calculer len, si precision et les autres cas.
	initial_len = ft_strlen(str);
	final_len = ft_printf_integer_len(str, flags);
	//Afficher FW si on a pas de flag -
	if (flags->field_width && !flags->minus)
		ft_space_before_integer(flags, final_len, str);
	//Afficher les 0 en cas de flags dot, precision
	if (flags->dot)
	{
		i = 0;
	//	printf("precision = %d\n", flags->precision); 
	//	printf("initial_len = %d\n", initial_len); 
	//	printf("final_len = %d\n", final_len); 
		if (flags->precision >= initial_len)
		{
			if (*str == '-')
			{
				if (!flags->minus_printed)
					flags->total_print += ft_putchar('-');
				initial_len--;
				flags->minus_printed = 1;
			}
			while (flags->precision - initial_len - i++)
				flags->total_print += ft_putchar('0');
		}
		else if (flags->precision == 0)
		{
			while (*str == '0')
			{
				final_len--;
				str++;
			}
		}
	}
	// Afficher les char
	if (flags->minus_printed)
		str++;
	while (*str)
		flags->total_print += ft_putchar(*str++);
	// Afficher les espaces en cas de FW et flag - 
	if (flags->field_width && flags->minus)
		ft_space_after_integer(flags, initial_len);
	// Remise a zero des flags
	flags->minus = 0;
	flags->zero = 0;
	flags->minus_printed = 0;
	flags->field_width = 0;
}

void	ft_print_integer(t_flags *flags)
{
	int		d;
	char	*str;

	if (flags->star_for_field_width)
		ft_field_width_star(flags);
	if (flags->star_for_precision)
		ft_precision_star(flags);
	d = va_arg(flags->args, int);
	str = ft_itoa(d);
	ft_treat_integer(str, flags);
	free(str);
}
