
CC =		cc
# CFLAGS =	-Wall -Wextra -Werror
# CFLAGS =	-Wall -Wextra
CFLAGS =	-Wall -Wextra -fsanitize=address

NAME =	minishell

LIB_DIR =	libraries
LIB_NAMES =	libft
LIBS = 		$(foreach LIB,$(LIB_NAMES),$(LIB_DIR)/$(LIB)/$(LIB).a)
LIB_FLAGS =	$(addprefix -L$(LIB_DIR)/, $(LIB_NAMES)) \
			$(addprefix -l, $(subst lib,,$(LIB_NAMES))) \
			-lreadline

LINKING_FLAGS = -lreadline -L/opt/homebrew/opt/readline/lib
COMFILE_FLAGS = -I/opt/homebrew/opt/readline/include

INCLUDES =	includes \
			libraries
INC_FLAGS =	$(addprefix -I, $(INCLUDES))


SRCS_DIR =	sources
BUILD_DIR =	build

SRCS =	\
		main.c \
		cursor.c \
		parser/parser.c \
		parser/cursor.c \
		parser/cursor2.c \
		parser/heredoc.c \
		env/env.c \
		env/env_utils.c \
		env/env_node.c \
		env/env_init.c \
		env/state.c \
		command/command.c \
		command/execute.c \
		command/exec_single.c \
		command/exec_pipe.c \
		command/exec_utils.c \
		command/open_io.c \
		command/redirect.c \
		utils/str_array.c \
		utils/chr_array.c \
		utils/io_array.c \
		utils/cmd_array.c \
		utils/error.c \
		utils/utils.c \
		utils/builtin_error.c \
		utils/signal_utils.c \
		builtin/builtin.c \
		builtin/cd.c \
		builtin/echo.c \
		builtin/env_.c \
		builtin/exit.c \
		builtin/exit_func.c \
		builtin/export.c \
		builtin/pwd.c \
		builtin/unset.c	\

OBJS =	$(addprefix $(BUILD_DIR)/, $(notdir $(SRCS:.c=.o)))


all: $(NAME)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@ $(COMFILE_FLAGS)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/*/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@ $(COMFILE_FLAGS)

$(LIB_DIR)/%.a:
	$(MAKE) all -C $(dir $@)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIB_FLAGS) $(LINKING_FLAGS)

clean:
	$(foreach LIB,$(LIBS),$(MAKE) fclean -C $(dir $(LIB)))
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
