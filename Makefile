# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 18:57:32 by cmariot           #+#    #+#              #
#    Updated: 2021/06/18 10:20:37 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM_NAME = libftprintf.a

COMPILER = gcc

COMPILER_FLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = includes

LIBFT_DIR = libft

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

OBJS = ${SRCS:.c=.o} ${LIBFT_SRCS:.c=.o}

REMOVE = rm -rf

.c.o:
		${COMPILER} ${COMPILER_FLAGS} -o ${PROGRAM_NAME} ${OBJS} -I ${INCLUDES_DIR}

all: 		compile_libft \
		compile_srcs \
		exec

$(NAME):	${OBJS}
		ar rc ${PROGRAM_NAME} ${OBJS}

compile_libft:
		make -C $(LIBFT_DIR)
		printf "Libft compilation OK.\n"

$(NAME):	${OBJS}
		ar rc ${PROGRAM_NAME} ${OBJS}

compile_srcs:	${NAME}
		printf "Srcs compilation OK.\n"

exec:
		
		printf "Execution OK.\n"

norme:
		norminette ${SRCS} ${INCLUDES_DIR}
		printf "Norme.\n"

clean:
		${REMOVE} ${OBJS}
		${REMOVE} ${TMP_OBJ_DIR}
		make -C $(LIBFT_DIR) clean
		printf "Clean OK.\n"

fclean:		clean
		${REMOVE} ${PROGRAM_NAME}
		make -C $(LIBFT_DIR) fclean
		printf "FClean OK.\n"

re:		fclean all
