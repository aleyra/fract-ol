.PHONY: all clean fclean re

# Name of file
NAME		=	fractol

# Name directory
PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	objs
PATH_LOG	=	logs
PATH_LIBFT	=	libft
PATH_LIBG	=	minilibx

# List of sources
SRCS_DISP	=	
SRCS		=	$(addprefix $(PATH_SRC)/display/, $(SRCS_DISP)) \
				$(addprefix $(PATH_SRC)/, )  main.c #add files à la racine

OBJS		=	$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS:.c=.o)))
INCS		=	$(PATH_INC)/minirt.h
LIBFT		=	-L $(PATH_LIBFT)
LIBMLX		=	 $(PATH_LIBG)/libmlx.dylib

# Commands of compilation
COMP		=	clang
COMP_FLAG	=	-Wall -Wextra -Werror -Imlx
COMP_ADD	=	-I $(PATH_LIBFT)/includes -I $(PATH_LIBG) -I $(PATH_INC)

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
	 $(MAKE) -C $(PATH_LIBFT)
	 $(MAKE) -C $(PATH_LIBG)


libmlx.dylib:
	ln -sf $(LIBMLX) .

$(NAME): 	$(OBJS) libmlx.dylib #sur Mac
	ln -sf $(LIBMLX) .
	$(COMP) $(OBJS) $(LIBFT) $(LIBMLX) -l ft -o $(NAME)

$(PATH_OBJ)/%.o : $(PATH_SRC)/*/%.c  $(INCS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@
	@ echo "$(_INFO) Compilation of $*"

$(PATH_OBJ)/%.o : $(PATH_SRC)/%.c  $(INCS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@
	@ echo "$(_INFO) Compilation of $*"

clean:
	@ $(RM) -rf $(PATH_OBJ)
	@ echo "$(_INFO) Deleted files and directory"
	 $(MAKE) -C $(PATH_LIBFT) clean
	 $(MAKE) -C $(PATH_LIBG) clean

fclean: clean
	@ $(RM) -rf $(NAME)
	 $(MAKE) -C $(PATH_LIBFT) fclean

re: fclean all