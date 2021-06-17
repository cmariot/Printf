/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:32:19 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/17 19:58:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		src_len;
	char	*src;
	char	*cpy;
	int		i;

	src = (char *)s1;
	src_len = ft_strlen(src);
	cpy = malloc(sizeof(char) * (src_len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static unsigned int	int_len(unsigned int n)
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

static char	*ft_u_itoa(unsigned int n)
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

void	ft_print_unsigned_int(t_flags *flags)
{
	unsigned int u;
	char *str;

	u = va_arg(flags->args, unsigned int);
	str = ft_u_itoa(u);
	while (*str)
	{
		flags->total_lenght += ft_putchar(*str++);
	}

}
