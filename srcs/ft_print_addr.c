/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:52:30 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/07 16:55:33 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_uitohexa_len2(unsigned int n)
{
	unsigned int	n_len;
	unsigned int	diviseur;

	n_len = 0;
	diviseur = 1;
	while ((n / diviseur) >= 16)
		diviseur = diviseur * 16;
	while (diviseur > 0)
	{
		n_len++;
		diviseur = diviseur / 16;
	}
	return (n_len);
}

char	*ft_uitoa_hexa2(unsigned int n)
{
	char			*base;
	unsigned int	diviseur;
	unsigned int	result;
	char			*str;
	int				i;

	str = malloc(sizeof(char) * (ft_uitohexa_len2(n) + 1));
	if (!str)
		return (NULL);
	base = "0123456789abcdef";
	diviseur = 1;
	while ((n / diviseur) >= 16)
		diviseur = diviseur * 16;
	i = 0;
	while (diviseur > 0)
	{
		result = (n / diviseur) % 16;
		str[i++] = base[result];
		diviseur = diviseur / 16;
	}
	str[i] = '\0';
	return (str);
}

void	ft_print_addr(t_flags *flags)
{
	unsigned int	p;
	char			*str;
	char			*new_str;

	if (flags->star_for_field_width)
		ft_field_width_star(flags);
	if (flags->star_for_precision)
		ft_precision_star(flags);
	p = va_arg(flags->args, unsigned int);
	str = ft_uitoa_hexa2(p);
	new_str = ft_strjoin("0x1", str);
	ft_treat_integer(new_str, flags);
	free(new_str);
	free(str);
}
