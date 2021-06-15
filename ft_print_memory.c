/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:34:03 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/15 10:55:45 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_check_base(char *base)
{
	int	base_len;
	int	j;

	base_len = 0;
	while (base[base_len] != '\0')
	{
		if (base[base_len] == '+' || base[base_len] == '-')
			return (0);
		j = base_len + 1;
		while (base[j] != '\0')
		{
			if (base[base_len] == base[j])
				return (0);
			j++;
		}
		base_len++;
	}
	if (base_len <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			diviseur;
	int			result;
	int			base_len;
	long int	long_nb;

	if (ft_check_base(base) == 0)
		return ;
	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	long_nb = nbr + 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		long_nb = -(long_nb);
	}
	diviseur = 1;
	while ((long_nb / diviseur) >= base_len)
		diviseur = diviseur * base_len;
	while (diviseur > 0)
	{
		result = (long_nb / diviseur) % base_len;
		ft_putchar(base[result]);
		diviseur = diviseur / base_len;
	}
}

int	main(void)
{
	int a;

	a = 123;
	ft_putnbr_base(a, "0123456789ABCDEF");	
	return (0);
}
