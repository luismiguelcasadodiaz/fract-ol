# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 13:07:33 by luicasad          #+#    #+#              #
#    Updated: 2024/01/30 13:13:54 by luicasad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
#                                 COLORS                                       #
# ============================================================================ #
DEF_COLOR		=	\033[0;39m
GRAY			=	\033[0;90m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
BLUE			=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN			=	\033[0;96m
WHITE			=	\033[0;97m
BLACK			=	\033[0;99m
ORANGE			=	\033[38;5;209m
BROWN			=	\033[38;2;184;143;29m
DARK_GRAY		=	\033[38;5;234m
MID_GRAY		=	\033[38;5;245m
DARK_GREEN		=	\033[38;2;75;179;82m
DARK_YELLOW		=	\033[38;5;143m
# ============================================================================ #
#                                 TARGETS                                      #
# ============================================================================ #

NAME 			= fractol
BONUS 			= fractol_bonus

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
	CC = cc
else ifeq ($(UNAME), FreeBSD)
	# FreeBSD
	CC = cc
else
	#Linux and others...
	CC	= cc
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
