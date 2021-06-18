/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_flags_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:58:07 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/18 16:59:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_in_flags_list(int c)
{
	if (c == '-')
		return (1);
	else if (c == '0')
		return (2);
	else if (c == '.')
		return (3);
	else if (c == '*')
		return (4);
	else
		return (0);
}
