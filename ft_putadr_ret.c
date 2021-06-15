/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:33:59 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/15 12:10:18 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putadr_ret(void *ptr)
{
	int ret;

	ret = 0;
	write(1, ptr, sizeof(void *));
	return (ret);
}

int	main(void)
{
	int a;
	void *ptr_a;

	a = 42;
	ptr_a = &a;
	ft_putadr_ret(ptr_a);
	printf("sizeof(void *) = %lu\n", sizeof(void *));
	return (0);
}
