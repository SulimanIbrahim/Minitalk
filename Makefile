NAME = server
NAMEB = server_bonus

CNAME = client
CNAMEB = client_bonus

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

all: $(NAME)$(NAMEC)

$(NAME)$(NAMEC) : $(SOBJ) $(COBJ)
	$(MAKE)	-C ./ft_printf
	$(CC) -o $(NAME) $(SSRC) $(PRINTF)
	$(CC) -o $(CNAME) $(CSRC) $(PRINTF)

bonus: $(NAMEB)$(NAMECB)

$(NAMEB)$(NAMECB) : $(BCOBJ) $(BSOBJ)
	$(MAKE)	-C ./ft_printf
	$(CC) -o $(NAMEB) $(BSSRC) $(PRINTF)
	$(CC) -o $(CNAMEB) $(BCSRC) $(PRINTF)

clean:
	$(MAKE) clean -C ./ft_printf
	/bin/rm -f $(SOBJ) $(COBJ)
	/bin/rm -f $(BCOBJ) $(BSOBJ)
fclean: clean
	$(MAKE) fclean -C ./ft_printf
	/bin/rm -f $(NAME) $(NAMEB)
	/bin/rm -f $(CNAME) $(CNAMEB)

re: fclean all