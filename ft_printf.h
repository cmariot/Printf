/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:56:06 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/17 15:27:55 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags
{
	int already_print;
	int width;
	int minus;
	int zero;
	int dot;
	int star;
	int type;

} t_flags;

//%[flags][champ][specificateur]

//Prend const char * en argument, revoie la longueur affichee. Peut prendre d'autres parametres, geres avec les va_args. Si le char n'est pas un % on l'affiche.
int		ft_printf(const char *, ...);

//Verifie que la conversion est geree par notre fonction, si c'est le cas on renvoie un int en fonction du type, sinon on renvoie 0. 
int		ft_is_in_type_list(int c);

//Verifie que le flag est gere par notre fonction, si c'est le cas on revoie un int en fonction du flag, sinon 0. 
int		ft_is_in_flags_list(int c);

//Traitement, si is_in_flag et is_in_type prend *format (char), la structure et le prochain va_arg ; Renvoie un int correspondant a la longueur qui a ete print. 
//int		ft_treatment(int c, t_flags flags, va_list args);

//
//int		ft_treat_width(int width, int minus, int has_zero);

//...

//Ft_putchar classique, sauf qu'on revoie 1 dans already_print si reussite.
int		ft_putchar(int c);

//int		ft_treat_pointer(unsigned long long pointer, t_flags flags);

//char 	*ft_ull_base(unsigned long long ull, int base);

//Convertit un unigned int n en chaine de caracteres. 
char	*ft_u_itoa(unsigned int n);

//Convertit une chaine de charactere en une nouvelle chaine de character, mais en minuscule
char	*ft_str_tolower(char *str);

//t_flags	ft_flag_minus(t_flags flags);

//t_flags	ft_flag_width(va_list args, t_flags flags);

//t_flags	ft_flag_digit(char c, t_flags flags);

char	*ft_strdup(const char *s1);

#endif
