# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 18:57:32 by cmariot           #+#    #+#              #
#    Updated: 2021/06/18 11:37:58 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM_NAME = libftprintf.a

COMPILER=gcc

COMPILER_FLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = includes

SRCS_OBJS = ${SRCS:%.c=obj/%.o}

SRCS = srcs/ft_printf.c \
       srcs/ft_initialize_flags.c \
       srcs/ft_check_type.c \
       srcs/ft_is_in_flags_list.c \
       srcs/ft_is_in_type_list.c \
       srcs/ft_putchar.c \
       srcs/ft_print_char.c \
       srcs/ft_print_str.c \
       srcs/ft_print_integer.c \
       srcs/ft_print_unsigned_int.c \
       srcs/ft_print_hexa.c \
       srcs/ft_print_hexa_maj.c \
       srcs/ft_check_flags.c

LIBFT_DIR = libft

LIBFT_OBJS = ${LIBFT_SRCS:%.c=obj/%.o}

LIBFT_SRCS = libft/ft_atoi.c \
	     libft/ft_bzero.c \
	     libft/ft_calloc.c \
	     libft/ft_isalnum.c \
	     libft/ft_isalpha.c \
	     libft/ft_isascii.c \
	     libft/ft_isdigit.c \
	     libft/ft_isprint.c \
	     libft/ft_itoa.c \
	     libft/ft_lstadd_back.c \
	     libft/ft_lstadd_front.c \
	     libft/ft_lstclear.c \
	     libft/ft_lstdelone.c \
	     libft/ft_lstiter.c \
	     libft/ft_lstlast.c \
	     libft/ft_lstmap.c \
	     libft/ft_lstnew.c \
	     libft/ft_lstsize.c \
	     libft/ft_memccpy.c \
	     libft/ft_memchr.c \
	     libft/ft_memcmp.c \
	     libft/ft_memcpy.c \
	     libft/ft_memmove.c \
	     libft/ft_memset.c \
	     libft/ft_putchar_fd.c \
	     libft/ft_putendl_fd.c \
	     libft/ft_putnbr_fd.c \
	     libft/ft_putstr_fd.c \
	     libft/ft_split.c \
	     libft/ft_strchr.c \
	     libft/ft_strdup.c \
	     libft/ft_strjoin.c \
	     libft/ft_strlcat.c \
	     libft/ft_strlcpy.c \
	     libft/ft_strlen.c \
	     libft/ft_strmapi.c \
	     libft/ft_strncmp.c \
	     libft/ft_strnstr.c \
	     libft/ft_strrchr.c \
	     libft/ft_strtrim.c \
	     libft/ft_substr.c \
	     libft/ft_tolower.c \
	     libft/ft_toupper.c

REMOVE = rm -rf


all: 				verif_code_source \
				compilation \
				assemblage \
				eddition_de_liens \
				execution

verif_code_source:	
				norminette | grep "Error"

norme:				verif_code_source

compilation:
				${COMPILER} ${COMPILER_FLAGS} -c ${SRCS} ${LIBTF_SRCS} -I ${INCLUDES_DIR} -I ${LIBFT_DIR}




$(PROGRAM_NAME):	${OBJS}
			${COMPILER} ${COMPILER_FLAGS} -o ${PROGRAM_NAME} ${OBJS} -I ${INCLUDES_DIR} -I ${LIBFT_DIR}
			ar rc ${PROGRAM_NAME} ${OBJS}

		


clean:
			${REMOVE} ${OBJS}
			${REMOVE} ${TMP_OBJ_DIR}
			make -C $(LIBFT_DIR) clean

fclean:			clean
			${REMOVE} ${PROGRAM_NAME}
			make -C $(LIBFT_DIR) fclean

re:			fclean all
