/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 13:29:53 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/30 14:49:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	main(void)
{
	int		ret;
//	ret = ft_printf("Fonction Printf\n");
//	ret = ft_printf("Test d'affichage char : %c\n", 'c');
//	ret = ft_printf("Test d'affichage str : %s\n", "str");
//	ret = ft_printf("Test d'affichage unsigned int : %u\n", 123456789);
//	ret = ft_printf("Test d'affichage int d : %d\n", 12345);
//	ret = ft_printf("Test d'affichage int i : %i\n", 67890);
//	ret = ft_printf("Test d'affichage 1464 en hexa : %x\n", 1464);
//	ret = ft_printf("Test d'affichage 1464 en HEXA : %X\n", 1464);
//	ret = ft_printf("Test d'affichage de l'adresse d'une variable : %p\n", &ret);
//	ret = ft_printf("Test d'affichage %% : %%\n");

//	ft_printf("Retour = %i\n", ft_printf("\nTest valeur de retour\n"));
//	ft_printf("Retour = %i\n", ft_printf("Test valeur de retour %d\n", 25));
//	ft_printf("Retour = %i\n", ft_printf("Test valeur de retour %s\n", "25"));

//	ft_printf("Test sur les char\n");
//	ft_printf("%c", '0'); //OK
//	ft_printf(" %c ", '0'); //OK 
//	ft_printf("10%c", '0'); // OK
//	ft_printf(".%10c.", '0'); //OK
//	ft_printf("-10%c", '0'); // OK
//	ft_printf("%-10c", '0'); // OK
//	ft_printf("%-10c", '0'); // OK
//	ft_printf("%*c", 1, '0');
//	ft_printf("%*c", 0, '0');
//	ft_printf("%*c", 2, '0');
//	ft_printf("%*c", -2, '0');
//	ft_printf("%*c", 0, '0');
//	ft_printf("%*c", 10, '0');
//	ft_printf("%*c", -10, '0');
//	ft_printf(".%*c.%*c.\n", -10, '0', 10, '1');
//	ft_printf("*%c%*c", '0', 10, '1');
//	ft_printf("%*c%c*", -10, '0', '1');
//	ft_printf("%-10c*",'0');
//	ft_printf("%-10c%*c%c*",'0', 10, '1', '2');
//	ft_printf("%c%c%c*",'0', '1', '2');
//	ft_printf("%-c%-c%c*", 1, '0', 0);
//	ft_printf("%c", '0' - 256);
//	ft_printf("%c", '0' + 256);
//	ft_printf("%c", 0);
//	ft_printf("0%c", 0);
//	ft_printf("%c", -129);
//	ft_printf("%c", 128);
//	ft_printf("%-*c", 10, '1');
//	ft_printf(" -%*c* -%-*c* ", -2, 0, 2, 0);
//	ft_printf(" -%-*c* -%-*c* ", 2, 0, -2, 0);
//	ft_printf(" -%*c* -%-*c* ", -1, 0, 1, 0);
//	ft_printf(" -%-*c* -%-*c* ", 2, 0, -2, 0);
//	ft_printf(" -%-2c* -%2c* ", 0, 0);

	
//	ft_printf("Test sur les char *\n");
//	ret = ft_printf(". %*.s %.1s .", 10, "123", "4567");
//	printf("ret1 = %d\n", ret);
//	ft_putchar_fd('\n', 1);
//	ret = printf(". 123 4567 .");
//	printf("ret2 = %d\n", ret);
//	ret = ft_printf("%x\n", 15);
//	printf("%x\n", 15);
//	ft_printf(".%5x.\n", 15);
//	printf(".%5x.\n", 15);
//	ft_printf(".%-5x.\n", 15);
//	printf(".%-5x.\n", 15);
//	ft_printf("%d\n", 0);
//	ret = ft_printf(".%.i.\n", 0);
//	printf(".%.i.\n", 0);
//	ret = ft_printf(".%-.2i.\n", 0);
//	printf(".%-.2i.\n", 1);
//	ret = ft_printf(".%*s.\n", 10, "abcd");
//	ret = ft_printf(".%*s.\n", 1, "abcd");
//	ret = ft_printf(".%*.2s.\n", 10, "abcd");
//	ret = ft_printf(".%*.s.%.1s.\n", 10, "123", "4567");
//	ret = ft_printf(".%10.4s.%.4s.\n", "123", "4567");
//	ret = ft_printf(".%-10.6s.\n", "123");
//	ft_printf(".%*.5s.%*.5s.\n", 10, "123", -10, "4567");
//	printf(".%*.5s.%*.5s.\n", 10, "123", -10, "4567");
//	ft_printf(".%*.5s.%*.5s.\n", -10, "123", -10, "4567");
//	printf(".%*.5s.%*.5s.\n", -10, "123", -10, "4567");
//	ret = ft_printf(".%*.5s.%*.5s.\n", -10, "123", 10, "4567");
//	ret = ft_printf(".%10.s.%1.s.\n", "123", "4567");
//	ret = ft_printf(".%3.3s.%3.3s.\n", "123", "4567");
//	ret = ft_printf(".%4.3s.%-4.3s.\n", "123", "4567");
//	ret = printf(".%4.3s.%-4.3s.\n", "123", "4567");
//	ret = ft_printf(" %-3.s ", NULL);
//	ret = ft_printf(" %-3.s ", NULL);

//	ret = ft_printf(".%.*s.\n", -2, "123");
//	ret = printf(".%.*s.\n", -2, "123");

	ret = ft_printf("Test d'affichage sur les integer\n");
//	ret = ft_printf("%d\n", 0);
//	ret = ft_printf(".%-.2i.\n", 1);
	ret = ft_printf(".%-3.2i.%10.42i.\n", 1, -1);
	ret = printf(".%-3.2i.%10.42i.\n", 1, -1);







	return (0);
}
