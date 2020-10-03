# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/05 21:22:26 by rpunet            #+#    #+#              #
#    Updated: 2020/10/03 23:40:03 by rpunet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CFLAGS		= -Wall -Wextra -Werror
CC			= gcc
NORME		= norminette -R CheckForbiddenSourceHeader
HDIR		= -I ./includes
SRCS		= ft_isblank.c ft_strcmp.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcpy.c ft_strclr.c ft_strnew.c
SRCS2		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
SRCS3		= ft_max.c ft_min.c ft_pow.c ft_strnew.c ft_count_digit.c ft_sort_int.c ft_swap.c
SRCSPRINT	= ft_printf.c ft_tracker.c flags.c ft_print_int.c ft_print_char.c ft_print_str.c ft_print_ptr.c ft_print_udec_int.c ft_print_hex.c ft_printf_utils.c
SRCSGNL		= get_next_line.c
PRINTDIR	= ./ft_printf
OBJS		= $(SRCS:.c=.o)
OBJSBONUS	= $(SRCSBONUS:.c=.o)
OBJS3		= $(SRCS3:.c=.o)
OBJSPRINT	= $(SRCSPRINT:.c=.o)
OBJSGNL		= $(SRCSGNL:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS) $(HDIR)
	ar rcs $(NAME) $(OBJS)
	@echo "\033[0;32m ---- libft.a done! ---- \033[0m"

norme: $(NORME) $(SRCS) $(SRCSBONUS) $(SRCS3) $(addprefix ./ft_printf/, $(SRCSPRINT)) $(addprefix ./get_next_line/,$(SRCSGNL))

clean:
	rm -f $(OBJS) $(OBJSBONUS) $(OBJS3) $(OBJSPRINT) $(OBJSGNL)
	@echo "\033[0;31m ---- objects removed! ---- \033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[0;31m ---- all cleared! ---- \033[0m"

re: fclean all

bonus:
	$(CC) $(CFLAGS) -c $(SRCS) $(SRCSSBONUS) $(HDIR)
	ar rcs $(NAME) $(OBJS) $(OBJSBONUS)
	@echo "\033[0;32m ---- libftBONUS.a done! ---- \033[0m"

plus:
	$(CC) $(CFLAGS) -c $(SRCS) $(SRCSBONUS) $(SRCS3) $(addprefix ./ft_printf/, $(SRCSPRINT)) $(addprefix ./get_next_line/, $(SRCSGNL)) $(HDIR)
	ar rcs $(NAME) $(OBJS) $(OBJSBONUS) $(OBJS3) $(OBJSPRINT) $(OBJSGNL)
	@echo "\033[0;34mLibftPLUS library built\033[0m"

.PHONY: all clean fclean re bonus plus
