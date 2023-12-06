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


LIBFTBF = ./ft_printf/printf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)$(NAMEC)

$(NAME)$(NAMEC) : $(SOBJ) $(COBJ)
	$(MAKE)	-C ./ft_printf
	$(CC) -o $(NAME) $(SSRC) $(LIBFTBF)
	$(CC) -o $(CNAME) $(CSRC) $(LIBFTBF)

bonus: $(NAMEB)$(NAMECB)

$(NAMEB)$(NAMECB) : $(BCOBJ)
	$(MAKE)	-C ./ft_printf
	$(CC) -o $(NAMEB) $(BSSRC) $(LIBFTBF)
	$(CC) -o $(CNAMEB) $(BCSRC) $(LIBFTBF)

clean:
	$(MAKE) clean -C ./ft_printf
	/bin/rm -f $(SOBJ) $(COBJ)
	/bin/rm -f $(BCOBJ)

fclean: clean
	$(MAKE) fclean -C ./ft_printf
	/bin/rm -f $(NAME) $(NAMEB)
	/bin/rm -f $(CNAME) $(CNAMEB)

re: fclean all