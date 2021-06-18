# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 18:57:32 by cmariot           #+#    #+#              #
#    Updated: 2021/06/18 09:28:31 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM_NAME = libftprintf.a

COMPILER = gcc

COMPILER_FLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = includes

LIBFT_DIR = libft

TMP_OBJ_DIR = obj

SRCS = ./srcs/ft_printf.c \
       ./srcs/ft_initialize_flags.c \
       ./srcs/ft_check_type.c \
       ./srcs/ft_is_in_flags_list.c \
       ./srcs/ft_is_in_type_list.c \
       ./srcs/ft_putchar.c \
       ./srcs/ft_print_char.c \
       ./srcs/ft_print_str.c \
       ./srcs/ft_print_integer.c \
       ./srcs/ft_print_unsigned_int.c \
       ./srcs/ft_print_hexa.c \
       ./srcs/ft_print_hexa_maj.c \
       ./srcs/ft_check_flags.c

OBJS = ${SRCS:.c=.o}

RM = rm -rf

.c.o:
		@${COMPILER} ${COMPILER_FLAGS} -o ${PROGRAM_NAME} -I ${INCLUDES_DIR} -c $< -o ${<:.c=.o}

all: 		prepare \
		compile_libft \
		compile_srcs \
		exec

$(NAME):	${OBJS}
		@ar rc ${PROGRAM_NAME} ${OBJS}

prepare:
		@mkdir ${TMP_OBJ_DIR}
		@printf "Dossier temporaire cree.\n"


compile_libft:
		@make -C $(LIBFT_DIR)
		@printf "Libft compilation OK.\n"

$(NAME):	${OBJS}
		@ar rc ${PROGRAM_NAME} ${OBJS}

compile_srcs:	${NAME}
		@printf "Srcs compilation OK.\n"

exec:
		@./ft_printf
		@printf "Execution OK.\n"

norme:
		norminette ${SRCS} ${INCLUDES_DIR}
		@printf "Norme.\n"

clean:
		@${RM} ${OBJS}
		@${RM} ${TMP_OBJ_DIR}
		@make -C $(LIBFT_DIR) clean
		@printf "Clean OK.\n"

fclean:		clean
		@${RM} ${PROGRAM_NAME}
		@make -C $(LIBFT_DIR) fclean
		@printf "FClean OK.\n"

re:		fclean all
