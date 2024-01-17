INC=/usr/include


INCLIB=$(INC)/../lib

UNAME := $(shell uname)

#CFLAGS= -I$(INC) -O3 -I.. -g
CFLAGS= -I$(INC) -O3 -I../../inc -g

NAME	= 	fenetre
SRC 	= 	fenetre.c \
			../win/win_h_key_press.c \
			../win/win_h_key_relea.c \
			../win/win_h_not_event.c

OBJ = $(SRC:%.c=%.o)

LFLAGS = -L../../lib -lmlx -L$(INCLIB) -lXext -lX11 -lm

ifeq ($(UNAME), Darwin)
	# mac
	CC = clang
else ifeq ($(UNAME), FreeBSD)
	# FreeBSD
	CC = clang
else
	#Linux and others...
	CC	= gcc
	LFLAGS += -lbsd
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)


%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		:\n	$(SRC)\n"
	@printf "OBJ		:\n	$(OBJ)\n"

clean:
	rm -f $(NAME) $(OBJ) *~ core *.core

re: clean all
