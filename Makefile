.PHONY: all clean fclean re
LINUX		=	0

# Name of file
NAME		=	fractol

# Name directory
PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	objs
PATH_LOG	=	logs

# Libraries

override LIBFT_DIR	:= libft
override LIBFT		:= libft.a
ifeq ($(LINUX),0)
override MINILIBX_DIR	:= minilibx-macos
override MINILIBX		:= libmlx.dylib
else
override MINILIBX_DIR	:= minilibx-linux
override MINILIBX		:= libmlx.a
endif

# List of sources
SRCS_DISP	=	color.c ft_exit.c interact.c my_mlx_pixel_put.c print_thgs.c
SRCS_FRACT	=	fern_set.c fractal.c julia_set.c mandelbrot_set.c
SRCS_MANA_S	=	init_color.c init_struct.c
SRCS_TOOLS	=	tools.c
SRCS		=	$(addprefix $(PATH_SRC)/display/, $(SRCS_DISP)) \
				$(addprefix $(PATH_SRC)/fractal/, $(SRCS_FRACT)) \
				$(addprefix $(PATH_SRC)/mana_struct/, $(SRCS_MANA_S)) \
				$(addprefix $(PATH_SRC)/tools/, $(SRCS_TOOLS)) \
				$(addprefix $(PATH_SRC)/, )  main.c #add files à la racine

OBJS		=	$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS:.c=.o)))
INCS		=	$(PATH_INC)/fractol.h

LIBRARIES	:= -lpthread
ifeq ($(LINUX),1)
LIBRARIES	+= -lm -lXext -lX11
endif

# Commands of compilation
COMP		=	clang
COMP_FLAG	=	-Wall -Wextra -Werror -Imlx
COMP_ADD	=	-I$(PATH_INC) -I$(LIBFT_DIR)/$(PATH_INC) -I$(MINILIBX_DIR)

# Others Command
RM			=	/bin/rm

# Color Code and template code
_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:	init $(NAME)
	 echo "$(_SUCCESS) Compilation done"

init:
	 $(shell mkdir -p $(PATH_OBJ))
	 $(MAKE) -C $(LIBFT_DIR)
	ln -sf $(LIBFT_DIR)/$(LIBFT)
	$(MAKE) -C $(MINILIBX_DIR)
	ln -sf $(MINILIBX_DIR)/$(MINILIBX)

bonus :	all

$(NAME): 	$(OBJS) $(LIBFT) $(MINILIBX)
			$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) $(LIBFT) -o $(NAME) $(LIBRARIES)

$(PATH_OBJ)/%.o : $(PATH_SRC)/*/%.c  $(INCS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@
	@ echo "$(_INFO) Compilation of $*"

$(PATH_OBJ)/%.o : $(PATH_SRC)/%.c  $(INCS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@
	@ echo "$(_INFO) Compilation of $*"

clean:
	@ $(RM) -rf $(PATH_OBJ)
	@ echo "$(_INFO) Deleted files and directory"
	 $(MAKE) -C $(LIBFT_DIR) clean
	 $(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	@ $(RM) -rf $(NAME)
	@ $(RM) $(LIBFT)
	 $(MAKE) -C $(LIBFT_DIR) fclean
	@ $(RM) $(MINILIBX)

re: fclean all
