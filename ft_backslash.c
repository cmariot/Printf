/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backslash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 21:55:42 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/11 23:20:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_backslash_pourcent(const char *format)
{
	if (*format == 0x5C)
	{
		printf("OK");
		if (*format++ == 0x25)
		{
			printf("OK");
			printf("%c", 0x25);
			return (1);
		}
		return (1);
	}
	return (0);
}
