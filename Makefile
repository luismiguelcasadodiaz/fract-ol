# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 13:07:33 by luicasad          #+#    #+#              #
#    Updated: 2024/01/30 13:28:25 by luicasad         ###   ########.fr        #
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

# ============================================================================ #
#                                 FOLDERS                                      #
# ============================================================================ #
UNAME := $(shell uname)
SRCDIR_FRACT		= ./src/fract/
SRCDIR_BONUS		= ./src/bonus/

ifeq ($(UNAME), Darwin)
	# mac
	SRCDIR_MLIBX		= ./src/minilibx_opengl_20191021/
else ifeq ($(UNAME), FreeBSD)
	# FreeBSD
	SRCDIR_MLIBX		= ./src/minilibx_opengl_20191021/
else
	#Linux and others...
	SRCDIR_MLIBX		= ./src/minilibx-linux/
endif

OBJDIR 			= ./obj/
INCDIR 			= ./inc/
LIBDIR			= ./lib/
REQUIRED_DIRS	= $(OBJDIR) $(INCDIR) $(LIBDIR)
vpath %.a $(LIBDIRh
# ============================================================================ #
#                               COMPILER SETUP                                 #
# ============================================================================ #
CC 				= cc
WRNFL			= -Wall -Wextra -Werror
DBGFL			= -g
CFLGS			= $(DBGFL) $(WRNFL) -c
HEADS			= -I$(INCDIR)
#LFLGS 			= -Wl,-v
LFLGS 			= 

INCLIB=$(INC)/../lib


#CFLAGS= -I$(INC) -O3 -I.. -g
CFLAGS= -I$(INC) -O3 -I../../inc -g

NAME= h
SRC = fenetre.c
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
