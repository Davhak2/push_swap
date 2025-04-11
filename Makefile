CC          = cc
CFLAGS      = -Wall -Wextra -Werror

NAME        = push_swap
NAME_BONUS  = checker
SRC_DIR     = src
SRC_BONUS_DIR = src_bonus
OBJ_DIR     = obj
OBJ_BONUS_DIR = obj_bonus
LIBFT_DIR   = libft
INC_DIR     = includes

SRC         = main.c validation.c utils.c utils2.c swap.c rotate.c reverse_rotate.c sort.c sort2.c
SRC_BONUS   = checker_main.c checker_validation.c checker_utils.c checker_utils2.c \
              checker_rotate.c checker_reverse_rotate.c checker_swap.c checker_execute.c
OBJ         = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJ_BONUS   = $(addprefix $(OBJ_BONUS_DIR)/,$(SRC_BONUS:.c=.o))
LIBFT       = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJ_BONUS_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	@mkdir -p $(OBJ_BONUS_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
