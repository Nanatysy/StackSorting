NAME_P = push_swap

NAME_C = checker

NAME_B = checker_bonus

LIBFT = libft.a

SRC_PUSH_SWAP = ./push_swap_dir/bubble_sort.c \
                ./push_swap_dir/call_sort.c \
                ./push_swap_dir/check_stack.c \
                ./push_swap_dir/choose_sort.c \
                ./push_swap_dir/copy_stack.c \
                ./push_swap_dir/five_sort.c \
                ./push_swap_dir/int_array_sort.c \
                ./push_swap_dir/main.c \
                ./push_swap_dir/quick_sort.c \
                ./push_swap_dir/quick_sort_second.c \
                ./push_swap_dir/selection_sort.c \
                ./push_swap_dir/shaker_sort.c \
                ./push_swap_dir/sort_three.c \
                ./check/instructions_check.c \
                ./check/instructions_exec.c \
                ./check/output.c \
                ./check/sort_func.c \
                ./utils/arg_collection.c \
                ./utils/args_error_check.c \
                ./utils/get_next_line.c \
                ./utils/list_func.c \
                ./utils/list_func_extra.c

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

SRC_CHECKER =   ./check/instructions_check.c \
                ./check/instructions_exec.c \
                ./check/output.c \
                ./check/sort_func.c \
                ./check/main.c \
                ./utils/arg_collection.c \
                ./utils/args_error_check.c \
                ./utils/get_next_line.c \
                ./utils/list_func.c \
                ./utils/list_func_extra.c

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

SRC_CHECKER_BONUS = ./check/instructions_check.c \
                    ./check/instructions_exec.c \
                    ./check/output.c \
                    ./check/sort_func.c \
                    ./check/bonus_extra.c \
                    ./check/bonus.c \
                    ./check/args_flags.c \
                    ./utils/arg_collection.c \
                    ./utils/args_error_check.c \
                    ./utils/get_next_line.c \
                    ./utils/list_func.c \
                    ./utils/list_func_extra.c

OBJ_CHECKER_BONUS = $(SRC_CHECKER_BONUS:.c=.o)

FLAG = -Wall -Werror -Wextra

all: $(NAME_P) $(NAME_C)

$(NAME_P): $(OBJ_PUSH_SWAP) $(LIBFT) push_swap.h
	gcc $(FLAG)  $(OBJ_PUSH_SWAP) $(LIBFT) -o $(NAME_P)

$(NAME_C): $(OBJ_CHECKER) $(LIBFT) push_swap.h
	gcc $(FLAG) $(OBJ_CHECKER) $(LIBFT) -o $(NAME_C)

%.o: %.c push_swap.h
	gcc $(FLAG) -c $< -o $@

$(LIBFT):
	make bonus -C ./libft
	cp ./libft/libft.a .

bonus: $(NAME_B)

$(NAME_B): $(OBJ_CHECKER_BONUS) $(LIBFT) push_swap.h
	gcc $(FLAG) $(LIBFT) $(OBJ_CHECKER_BONUS) -o $(NAME_B)

clean:
	rm -rf $(OBJ_PUSH_SWAP)
	rm -rf $(OBJ_CHECKER)
	rm -rf $(OBJ_CHECKER_BONUS)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME_P)
	rm -rf $(NAME_C)
	rm -rf $(NAME_B)
	rm -rf $(LIBFT)
	make fclean -C ./libft

re: fclean all