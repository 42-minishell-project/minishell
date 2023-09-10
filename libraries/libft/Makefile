# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 15:55:10 by yeohong           #+#    #+#              #
#    Updated: 2023/09/10 15:55:13 by yeohong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

LIBFT_DIR =		libft
LIBFT_BASE =	\
				ft_atoi_itoa.c \
				ft_calloc.c \
				ft_chr.c \
				ft_cmp.c \
				ft_io.c \
				ft_is.c \
				ft_mem.c \
				ft_split.c \
				ft_str_l.c \
				ft_str.c \
				ft_str2.c
LIBFT_SRCS =	$(addprefix $(LIBFT_DIR)/, $(LIBFT_BASE))
LIBFT_OBJS =	$(LIBFT_SRCS:.c=.o)

PRINTF_DIR =	ft_printf
PRINTF_BASE =	\
				ft_printf.c \
				format/format_parser.c \
				format/format_print.c \
				utils/num_utils.c \
				utils/pad_utils.c \
				utils/print_utils.c \
				f_types/f_types.c \
				f_types/func_char_str.c \
				f_types/func_dec_int_uint.c \
				f_types/func_hex.c \
				f_types/func_ptr.c \
				f_types/func_invalid_percent.c
PRINTF_SRCS =	$(addprefix $(PRINTF_DIR)/, $(PRINTF_BASE))
PRINTF_OBJS =	$(PRINTF_SRCS:.c=.o)

READLINE_DIR =	ft_readline
READLINE_BASE =	ft_readline.c
READLINE_SRCS =	$(addprefix $(READLINE_DIR)/, $(READLINE_BASE))
READLINE_OBJS =	$(READLINE_SRCS:.c=.o)

INCLUDES =	\
			$(LIBFT_DIR) \
			$(PRINTF_DIR) \
			$(READLINE_DIR)
INC_FLAGS =	$(addprefix -I , $(INCLUDES))

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $^ -o $@

$(NAME): $(LIBFT_OBJS) $(PRINTF_OBJS) $(READLINE_OBJS)
	ar rcs $@ $^

clean:
	rm -f $(LIBFT_OBJS) $(PRINTF_OBJS) $(READLINE_OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
