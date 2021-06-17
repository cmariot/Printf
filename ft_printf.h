/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:56:06 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/17 21:27:22 by cmariot          ###   ########.fr       */
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
	va_list args;		// Arg to print out
	int minus_flag;		// -
	int zero_flag;		// 0
	int dot_flag;		// .
	int star_flag;		// *
	int field_width;	// Largeur champ
	int type;		// Specificateur
	int total_lenght;	// Return value

} t_flags;

//	%[flags][champ][specificateur]

//Prend const char * en argument, revoie la longueur affichee. Peut prendre d'autres parametres, geres avec les va_args. 
int			ft_printf(const char *, ...);

//Initialiser toutes les variables de la structure sur 0.
t_flags 	*ft_initialize_flags(t_flags *flags);

//Ft_putchar classique, sauf qu'on revoie 1 dans already_print si reussite.
int		ft_putchar(int c);

//Lorsqu'on rencontre un %, on verifie quels flags sont presents entre le % et le specificateur, on rentre ces valeurs dans la structure. 
unsigned int	ft_check_flags(const char *format, t_flags *flags, unsigned int i);

//Verifie que la conversion est geree par notre fonction, si c'est le cas on renvoie un int en fonction du type, sinon on renvoie 0. 
int		ft_is_in_type_list(int c);

//Lorsqu'on est au niveau d'un specificateur de type on va verifier de quel type il s'agit pour l'envoyer dans la bonne fonction.
void	ft_check_type(const char *format, unsigned int i, t_flags *flags);

//Dans le cas d'un char a afficher
void	ft_print_char(t_flags *flags);
void	ft_print_str(t_flags *flags);
void	ft_print_unsigned_int(t_flags *flags);
void 	ft_print_integer(t_flags *flags);
void	ft_print_hexa(t_flags *flags);
void	ft_print_hexa_maj(t_flags *flags);

char	*ft_strdup(const char *s1);

#endif
