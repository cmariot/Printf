# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 18:57:32 by cmariot           #+#    #+#              #
#    Updated: 2021/07/28 17:57:32 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PROGRAM_NAME = libftprintf.a

COMPILER = gcc

COMPILER_FLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = includes

SRCS_DIR = srcs

SRCS = srcs/ft_printf.c \
       srcs/ft_flags.c \
       srcs/ft_type.c \
	   srcs/ft_star_flag.c \
	   srcs/ft_space_and_precision.c \
	   srcs/ft_print_char.c \
       srcs/ft_print_str.c \
       srcs/ft_print_integer.c \
       srcs/ft_print_unsigned_int.c \
       srcs/ft_print_hexa.c \
       srcs/ft_print_upper_hexa.c \
       srcs/ft_print_addr.c \
	   srcs/ft_print_percent.c \
	   srcs/ft_set_flags.c

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

MAIN = main.c

EXECUTABLE_NAME = ft_printf

.c.o:
				@${COMPILER} ${COMPILER_FLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES_DIR} -I ${LIBFT_DIR}

${NAME}:		compil_srcs

all: 			compil_srcs

bonus:			compil_srcs
				@printf "\x1b[32mYou can now use the flags \"-0.#+ and space\"\x1b[0m\n"

norme:
				@norminette ./srcs ./includes ./libft
				@printf "\x1b[32mThe norm is checked in this directory and all subdirectories.\x1b[0m\n"

compil_libft:
				@cd libft && make libft.a

compil_srcs:	compil_libft ${SRCS_OBJS}
				@ar rc ${PROGRAM_NAME} ${SRCS_OBJS} ${LIBFT_OBJS}
				@printf "\x1b[32mlibftprintf.a is ready.\x1b[0m\n"
			
test:			compil_srcs
				@${COMPILER} ${COMPILER_FLAGS} ${MAIN} ${PROGRAM_NAME} -o ${EXECUTABLE_NAME} -I ${INCLUDES_DIR} -I ${LIBFT_DIR}
				@./${EXECUTABLE_NAME}

leaks:			compil_srcs
				@${COMPILER} ${COMPILER_FLAGS} ${MAIN} ${PROGRAM_NAME} -o ${EXECUTABLE_NAME} -I ${INCLUDES_DIR} -I ${LIBFT_DIR}
				@leaks -atExit -- ./${EXECUTABLE_NAME}

clean:
				@cd libft && make clean
				@${REMOVE} ${SRCS_OBJS}
				@printf "\x1b[32mThe object files have been deleted\x1b[0m\n"

fclean:			clean
				@cd libft && make fclean
				@${REMOVE} ${PROGRAM_NAME}
				@${REMOVE} ${EXECUTABLE_NAME}
				@printf "\x1b[32mThe binary files have been deleted\x1b[0m\n"

re:				fclean all

.PHONY:			clean fclean
