NAME = server
NAMESB = server_bonus

NAMEC = client
NAMECB = client_bonus

SSRC = server.c

CSRC = client.c

BSSRC = server_bonus.c

BCSRC = client_bonus.c

SOBJ = $(SSRC:%.c=%.o)
COBJ = $(CSRC:%.c=%.o)
BCOBJ = $(BCSRC:%.c=%.o)
BSOBJ = $(BSSRC:%.c=%.o)
PRINTF = ./ft_printf/printf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf
all: $(NAME)$(NAMEC)

$(NAME)$(NAMEC) : $(SOBJ) $(COBJ)
	$(MAKE)	-C ./ft_printf
	$(CC) -o $(NAME) $(SSRC) $(PRINTF)
	$(CC) -o $(NAMEC) $(CSRC) $(PRINTF)

bonus: $(NAMESB)$(NAMECB)

$(NAMESB)$(NAMECB) : $(BCOBJ) $(BSOBJ)
	$(MAKE)	-C ./ft_printf
	$(CC) -o $(NAMESB) $(BSSRC) $(PRINTF)
	$(CC) -o $(NAMECB) $(BCSRC) $(PRINTF)

clean:
	$(MAKE) clean -C ./ft_printf
	$(RM) $(SOBJ) $(COBJ)
	$(RM) $(BCOBJ) $(BSOBJ)
fclean: clean
	$(MAKE) fclean -C ./ft_printf
	$(RM) $(NAME) $(NAMESB)
	$(RM) $(NAMEC) $(NAMECB)

re: fclean all