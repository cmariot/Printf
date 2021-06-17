/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:17:19 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/17 13:59:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

char *ft_str_tolower(char *str)
{
	
	while (*str)
	{
		*str = ft_tolower((int)*str);
		str++;
	}
	return (str);
}

int	main(void)
{
	char *str = "ToTo";
	str = ft_str_tolower(str);
	printf("%s\n", str);	
	return (0);
}
