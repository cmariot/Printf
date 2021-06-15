# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 18:57:32 by cmariot           #+#    #+#              #
#    Updated: 2021/06/15 14:51:37 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=gcc
CCFLAGS=-Wall -Wextra -Werror

SRCS = ft_printf.c \
	   ft_character_printing.c \
	   ft_percent_char.c \
	   ft_putchar_ret.c \
	   ft_putstr_ret.c \
	   ft_putnbr_ret.c \
	   ./LibftPrintf/ft_atoi.c \
       ./LibftPrintf/ft_bzero.c \
	   ./LibftPrintf/ft_calloc.c \
       ./LibftPrintf/ft_itoa.c \
       ./LibftPrintf/ft_isalnum.c \
       ./LibftPrintf/ft_isalpha.c \
       ./LibftPrintf/ft_isascii.c \
       ./LibftPrintf/ft_isdigit.c \
       ./LibftPrintf/ft_isprint.c \
       ./LibftPrintf/ft_memccpy.c \
       ./LibftPrintf/ft_memchr.c \
       ./LibftPrintf/ft_memcmp.c \
       ./LibftPrintf/ft_memcpy.c \
       ./LibftPrintf/ft_memmove.c \
       ./LibftPrintf/ft_memset.c \
       ./LibftPrintf/ft_putchar_fd.c \
       ./LibftPrintf/ft_putendl_fd.c \
       ./LibftPrintf/ft_putnbr_fd.c \
       ./LibftPrintf/ft_putstr_fd.c \
       ./LibftPrintf/ft_split.c \
       ./LibftPrintf/ft_strchr.c \
       ./LibftPrintf/ft_strdup.c \
       ./LibftPrintf/ft_strjoin.c \
       ./LibftPrintf/ft_strlcat.c \
       ./LibftPrintf/ft_strlcpy.c \
       ./LibftPrintf/ft_strlen.c \
       ./LibftPrintf/ft_strmapi.c \
       ./LibftPrintf/ft_strncmp.c \
       ./LibftPrintf/ft_strnstr.c \
       ./LibftPrintf/ft_strrchr.c \
       ./LibftPrintf/ft_strtrim.c \
       ./LibftPrintf/ft_substr.c \
       ./LibftPrintf/ft_tolower.c \
       ./LibftPrintf/ft_toupper.c \
	   ./LibftPrintf/ft_lstadd_back.c \
	   ./LibftPrintf/ft_lstadd_front.c \
	   ./LibftPrintf/ft_lstclear.c \
	   ./LibftPrintf/ft_lstdelone.c \
	   ./LibftPrintf/ft_lstiter.c \
	   ./LibftPrintf/ft_lstlast.c \
	   ./LibftPrintf/ft_lstmap.c \
	   ./LibftPrintf/ft_lstnew.c \
	   ./LibftPrintf/ft_lstsize.c \


BONUS_SRCS =

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

RM = rm -rf

.c.o:
		${CC} ${CCFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
	ar rc ${NAME} ${OBJS}

bonus: 		${OBJS} ${BONUS_OBJS}
	ar rc ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
		${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
		${RM} ${NAME}

re:			fclean all
