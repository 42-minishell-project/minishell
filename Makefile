
CC =		gcc
# CFLAGS =	-Wall -Wextra -Werror
# CFLAGS =	-Wall -Wextra
CFLAGS =	-Wall -Wextra -fsanitize=address

NAME =	test

LIB_DIR =	libraries
LIB_NAMES =	libft
LIBS = 		$(foreach LIB,$(LIB_NAMES),$(LIB_DIR)/$(LIB)/$(LIB).a)
LIB_FLAGS =	$(addprefix -L$(LIB_DIR)/, $(LIB_NAMES)) \
			$(addprefix -l, $(subst lib,,$(LIB_NAMES))) \
			-lreadline


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
		env/env.c \
		env/env_utils.c \
		env/env_utils2.c \
		command/command.c \
		command/execute.c \
		command/env_path.c \
		command/find_exe.c \
		command/open_io.c \
		utils/str_array.c \
		utils/chr_array.c \
		utils/io_array.c \
		utils/cmd_array.c \
		utils/error.c \
		utils/utils.c \
		builtin/builtin.c \
		builtin/cd.c \
		builtin/echo.c \
		builtin/env_.c \
		builtin/exit.c \
		builtin/export.c \
		builtin/pwd.c \
		builtin/unset.c

OBJS =	$(addprefix $(BUILD_DIR)/, $(notdir $(SRCS:.c=.o)))


all: $(NAME)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRCS_DIR)/**/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

echo:
	@echo $(SRCS)
	@echo $(OBJS)

$(LIB_DIR)/%.a:
	$(MAKE) all -C $(dir $@)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIB_FLAGS)

clean:
	$(foreach LIB,$(LIBS),$(MAKE) fclean -C $(dir $(LIB)))
	rm -f $(OBJS)
	rmdir $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
