/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_type_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 10:06:04 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/17 12:17:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_in_type_list(int c)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (2);
	else if	(c == 'p')
		return (3);
	else if	(c == 'd')
		return (4);
	else if	(c == 'i')
		return (5);
	else if	(c == 'u')
		return (6);
	else if	(c == 'x')
		return (7);
	else if	(c == 'X')
		return (8);
	else if	(c == '%')
		return (9);
	else
		return (0);
}
