/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_flags_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 10:55:21 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/17 14:23:08 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_in_flags_list(int c)
{
	if (c == '-')
		return (1);
	else if	(c == '0')
		return (2);
	else if (c == '.')
		return (3);
	else if	(c == '*')
		return (4);
	else
		return (0);
}
