NAMEC	= client
NAMES	= server

SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.c)

SRCC = $(patsubst %.c, $(SRC_DIR)/%.c, client.c)
SRCS = $(patsubst %.c, $(SRC_DIR)/%.c, server.c)

OBJ_DIR	= obj

OBJC = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCC))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

CC		= gcc
HEADER	= $(wildcard includes/*.h)
INCLUDE	= -Iincludes -Ift_printf
CFLAGS	= -Wall -Wextra -Werror $(INCLUDE)
MK		= mkdir -p

# test :
# 	@echo $(INCLUDE)

all: ft_printf $(OBJ_DIR) $(NAMEC) $(NAMES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	$(MK) $(OBJ_DIR)

$(NAMES): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $< -Lft_printf -lftprintf

$(NAMEC): $(OBJC) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $< -Lft_printf -lftprintf


ft_printf:
	@make -C ft_printf

clean:
	rm -f $(OBJC)
	rm -f $(OBJS)
	make -C ft_printf clean
	
fclean: clean
	rm -f $(NAMEC) $(NAMES)
	@rm -rf ft_printf/libftprintf.a
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all bonus ft_printf clean fclean re