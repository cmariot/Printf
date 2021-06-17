/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:55:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/17 21:30:08 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_flags 	*flags;
	unsigned int	i;

	flags = malloc(sizeof(t_flags));
	if (flags == NULL)
		return (-1);
	flags = ft_initialize_flags(flags);
	va_start(flags->args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			flags->total_lenght += ft_putchar(format[i]);
		else if (format[i] == '%')
		{
			//reset flags except total_lenght ? 
			i = ft_check_flags(format, flags, i++);
			ft_check_type(format, i, flags);

		}
		i++;
	}
	va_end(flags->args);
	free(flags);
	return (flags->total_lenght);
}

int 	main(void)
{
	int ret;

	ret = ft_printf("Fonction Printf\n");
	ret = ft_printf("Test d'affichage char : %c\n", 'c');
	ret = ft_printf("Test d'affichage str : %s\n", "str");
	ret = ft_printf("Test d'affichage unsigned int : %u\n", 123456789);
	ret = ft_printf("Test d'affichage int d : %d\n", 12345);
	ret = ft_printf("Test d'affichage int i : %i\n", 67890);
	ret = ft_printf("Test d'affichage 1464 en hexa : %x\n", 1464);
	ret = ft_printf("Test d'affichage 1464 en HEXA : %X\n", 1464);
	
	return (0);
}
