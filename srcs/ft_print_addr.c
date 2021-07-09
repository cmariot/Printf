/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:52:30 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/09 12:23:21 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_ulltohexa_len(unsigned long long n)
{
	unsigned long long	n_len;
	unsigned long long	diviseur;

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

char	*ft_ulltoa_hexa(unsigned long long n)
{
	char				*base;
	unsigned long long	diviseur;
	unsigned long long	result;
	char				*str;
	int					i;

	str = malloc(sizeof(char) * (ft_ulltohexa_len(n) + 1));
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
	unsigned long long	p;
	char				*str;
	char				*new_str;

	if (flags->star_for_field_width)
		ft_field_width_star(flags);
	if (flags->star_for_precision)
		ft_precision_star(flags);
	p = (unsigned long long)va_arg(flags->args, void *);
	str = ft_ulltoa_hexa(p);
	new_str = ft_strjoin("0x", str);
	ft_print(new_str, flags);
	free(new_str);
	free(str);
}
