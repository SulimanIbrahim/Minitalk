NAMEC = client
NAMES = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT = ../Libft-42/libft.a
SRC_S= server.c
SRC_C = client.c\

SRCS = ft_itoa.c\
		ft_atoi.c

OBJ_S= $(SRC_S:%.c=%.o)
OBJ_C= $(SRC_C:%.c=%.o)
OBJ= $(SRCS:%.c=%.o)
all : $(NAMEC) $(NAMES)
$(NAMEC) $(NAMES) : $(OBJ_S) $(OBJ_C) $(OBJ)
	@make all -C ./Libft-42
	$(CC) $(CFLAGS) $(OBJ_S) ../Libft-42/libft.a -o server
	$(CC) $(CFLAGS) $(OBJ_C) ../Libft-42/libft.a -o client

clean : $(RM) 
	$(OBJ_C) $(OBJ_S)

fclean : $(RM) 
	$(OBJ_C) $(OBJ_S) 
	$(NAMEC) $(NAMES)

re : fclean all