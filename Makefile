NAME = ft_printf

HEADER = includes

FLAGS = -Wall -Wextra -Ofast

LFT = libft
LFT_INC = $(LFT)/includes

ifdef DEBUG
FLAGS = -Wall -Werror -Wextra -g

else
FLAGS = -Wall -Werror -Wextra
endif

LIB = libft

SRC = srcs/ft_printf.c \
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

OBJ = $(SRC:%.c=obj/%.o)

all: prepare compile_lib compile_p $(NAME) exec

exec:
		@printf "\n\n\033[32mRun like this:\n \033[39m\n"

norm:
		@norminette $(SRC) $(HEADER)

$(NAME): $(OBJ)
		@gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(LFT_INC) -I $(HEADER) \
		-L $(LFT) -lft 
		@printf " => Ok.\n"

prepare:
		@mkdir -p obj/srcs

compile_lib:
		@make -C $(LFT)

compile_p:
		@echo "\033[31mCompiling $(NAME) wait...\033[39m"

obj/%.o: %.c $(HEADER)
		@gcc $(FLAGS) \
		-I $(HEADER) \
		-o $@ -c $<
		@printf "|"

clean:
		@/bin/rm -rf ./obj
		@make -C $(LFT) fclean
		@/bin/rm -rf $(OBJ)
		@echo "\033[41;39mRemoving Objects Wait...\033[49;39m"

fclean: clean
		@/bin/rm -f $(NAME)
		@echo "\033[41;39mRemoving Binary Wait...\033[49;39m\n"

re: fclean all
