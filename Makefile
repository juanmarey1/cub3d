NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -rf

INCLUDE_DIR = include
LIBFT_DIR = libft
MLX_DIR = mlx

INCLUDE = -I $(INCLUDE_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)
LIBRARY = -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

SOURCES_DIR = sources/
SOURCES = cub3d.c error.c map_parse.c is_map_valid.c check_rows.c raycasting.c raycast_case_1.c raycast_case_2.c raycast_case_3.c raycast_case_4.c run_game.c ft_move_player.c assets.c get_ass_pixel.c get_repeated_pixel.c
SOURCES_WITH_DIR = $(addprefix $(SOURCES_DIR), $(SOURCES))
OBJS = $(SOURCES_WITH_DIR:.c=.o)

# SOURCES = prueba_texturas.c
# OBJS = $(SOURCES:.c=.o)

%.o:%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(OBJS) created!"

all: $(NAME)

$(NAME): $(OBJS) maker
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LIBRARY) -o $(NAME)
	@echo "$(NAME) created!"

maker:
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@$(RM) $(OBJS)
	@echo "$(OBJS) removed!"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "$(NAME) removed!"

re: fclean all

run: all clean

.PHONY: all clean fclean re run maker
