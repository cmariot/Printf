# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 18:57:32 by cmariot           #+#    #+#              #
#    Updated: 2021/06/18 15:47:38 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PROGRAM_NAME = libftprintf.a

COMPILER=gcc

COMPILER_FLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = includes

SRCS_DIR = srcs

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
	   srcs/ft_print_addr.c \
       srcs/ft_check_flags.c

SRCS_OBJS = ${SRCS:.c=.o}

LIBFT_NAME = libft/libft.a

LIBFT_DIR = libft

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

LIBFT_OBJS = ${LIBFT_SRCS:.c=.o}

REMOVE = rm -rf

.c.o:
				@${COMPILER} ${COMPILER_FLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES_DIR} -I ${LIBFT_DIR}

${NAME}:		compil_libft compil_srcs
				@printf "The program is ready to be execute.\n"

all: 			norme compil_libft compil_srcs exec

norme:
				@norminette | grep "Error"

compil_libft: 	${LIBFT_OBJS}
				@ar rc ${LIBFT_NAME} ${LIBFT_OBJS}
				@ranlib ${LIBFT_NAME}
				@printf "Libft is compilated\n"

compil_srcs:	${SRCS_OBJS}
				@${COMPILER} ${COMPILER_FLAGS} -o ${PROGRAM_NAME} \
					${SRCS_OBJS} -L ${LIBFT_DIR} -I ${INCLUDES_DIR} 
				@printf "Srcs are compilated\n"
			
exec:
				@./${PROGRAM_NAME}
clean:
				@${REMOVE} ${LIBFT_OBJS}
				@${REMOVE} ${SRCS_OBJS}
				@printf "The .o files have been deleted\n"

fclean:			clean
				@${REMOVE} ${LIBFT_NAME}
				@${REMOVE} ${PROGRAM_NAME}
				@printf "The binary file have been deleted\n"

re:				fclean all
