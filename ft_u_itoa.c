/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:44:28 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/17 12:08:44 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	int_len(unsigned int n)
{
	int	n_len;

	n_len = 0;
	while (n != 0)
	{
		n = n / 10;
		n_len++;
	}
	return (n_len);
}

char	*ft_u_itoa(unsigned int n)
{
	unsigned int	n_len;
	char			*nombre;

	if (n == 0)
		return (ft_strdup("0"));
	n_len = int_len(n);
	nombre = malloc(sizeof(char) * (n_len));
	if (nombre == NULL)
		return (NULL);
	nombre[n_len] = '\0';
	while (n != 0)
	{
		nombre[n_len - 1] = '0' + n % 10;
		n = n / 10;
		n_len--;
	}
	return (nombre);
}
