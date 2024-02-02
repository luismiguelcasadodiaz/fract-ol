# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 13:07:33 by luicasad          #+#    #+#              #
#    Updated: 2024/02/02 20:09:39 by luicasad         ###   ########.fr        #
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

FRACT 			= fractol
BONUS 			= fractol_bonus
TESTS			= fenetre

# ============================================================================ #
#                                 FOLDERS                                      #
# ============================================================================ #
OPSYS := $(shell uname)
SRCDIR_FRACT		= ./src/fract/
SRCDIR_BONUS		= ./src/bonus/
SRCDIR_TESTS		= ./src/tests/

ifeq ($(OPSYS), Darwin)
	# mac
	SRCDIR_MLIBX		= ./src/minilibx_opengl_20191021/
else ifeq ($(OPSYS), FreeBSD)
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
vpath %.a $(LIBDIR)
# ============================================================================ #
#                               COMPILER SETUP                                 #
# ============================================================================ #
CC 				= cc
WRNFL			= -Wall -Wextra -Werror
DBGFL			= -g
CFLGS			= $(DBGFL) $(WRNFL) -c
HEADS			= -I$(INCDIR)
#LFLGS 			= -Wl,-v
FRAMEWORKS		= -framework OpenGL -framework AppKit 
#INCLIB=$(INC)/../lib


#CFLAGS= -I$(INC) -O3 -I.. -g
#CFLAGS= -I$(INC) -O3 -I../../inc -g

#NAME= h
#SRC = fenetre.c
#OBJ = $(SRC:%.c=%.o)


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

# ============================================================================ #
#                              LIBRARIES SETUP                                 #
# ============================================================================ #
NAMELIBMLIBX 		= libmlx.a
PATH_MLIBX 		= $(addprefix $(SRCDIR_MLIBX), $(NAMELIBPRINTF))
LOADLIBMLIBX 		= mlx 
#NAMELIBFT 		= libft.a
#PATH_LIBFT 		= $(addprefix $(SRCDIR_LIBFT), $(NAMELIBFT))
#LOADLIBFT 		= ftj
#NAMELIBPSS 		= libpss.a
#PATH_STACK 		= $(addprefix $(SRCDIR_STACK), $(NAMELIBPSS))
#LOADLIBSS 		= pss

#NAMELIBARGPA 		= libargpar.a
#PATH_ARGPA 		= $(addprefix $(SRCDIR_ARGPA), $(NAMELIBARGPA))
kLOADLIBARGPA 		= argpar

#MYLIBS			= $(NAMELIBPRINTF) $(NAMELIBFT) $(NAMELIBPSS) $(NAMELIBARGPA)
MYLIBS			= $(NAMELIBMLIBX)
#LLIBS 			= -L$(LIBDIR) -l$(LOADLIBARGPA) -l$(LOADLIBSS) -l$(LOADLIBPRINTF) -l$(LOADLIBFT) 
LLIBS 			= -L$(LIBDIR) -l$(LOADLIBMLIBX)
# ============================================================================ #
#                                 SOURCES                                      #
# ============================================================================ #

HEADER_FRA	=	fractol.h
SRCS_FRACT	= 	fractol.c

HEADER_BON	=	fractol_bonus.h
SRCS_BONUS	 =	fractol_bonus.c

HEADER_TES	=	fenetre.h
SRCS_TESTS	=	fenetre.c

FILE_FRACT = $(addprefix $(SRCDIR_FRACT), $(SRCS_FRACT))
FILE_BONUS = $(addprefix $(SRCDIR_BONUS), $(SRCS_BONUS))
FILE_TESTS = $(addprefix $(SRCDIR_TESTS), $(SRCS_TESTS))

OBJS_FRACT = $(addprefix $(OBJDIR), $(SRCS_FRACT:.c=.o))
OBJS_BONUS = $(addprefix $(OBJDIR), $(SRCS_BONUS:.c=.o))
OBJS_TESTS = $(addprefix $(OBJDIR), $(SRCS_TESTS:.c=.o))

DEPE_FRACT = $(addprefix $(OBJDIR), $(SRCS_FRACT:.c=.d))
DEPE_BONUS = $(addprefix $(OBJDIR), $(SRCS_BONUS:.c=.d))
DEPE_TESTS = $(addprefix $(OBJDIR), $(SRCS_TESTS:.c=.d))

$(info fract source files $(SRCS_FRACT))
$(info fract source paths $(FILE_FRACT))
$(info fract object patha $(OBJS_FRACT))

$(info bonus source files $(SRCS_BONUS))
$(info bonus source paths $(FILE_BONUS))
$(info bonus object patha $(OBJS_BONUS))

$(info tests source files $(SRCS_TESTS))
$(info tests source paths $(FILE_TESTS))
$(info tests object patha $(OBJS_TESTS))
# ============================================================================ #
#                                 RULES                                        #
# ============================================================================ #
all: makedirs makelibs $(FRACT)
-include $(DEPE_FRACT)

bonus: makedirs makelibs $(BONUS)
-include $(DEPE_BONUS)

tests: makedirs makelibs $(TESTS)
-include $(DEPE_TESTS)

# .......................... directories creation ............................ #

makedirs:
	$(shell for d in $(REQUIRED_DIRS); \
 				do \
 					[[ -d $$d ]] || mkdir -p $$d; \
 				done)


# .......................... library construction ............................ #
makelibs: $(MYLIBS) 

$(NAMELIBMLIBX): makelibmlibx $(LIBDIR) 

makelibmlibx: 
	$(MAKE) -C $(SRCDIR_MLIBX)


# ....................... dependencies construction .......................... #
#for each c file create its dependency file 
#READ GNU make  manual 4.14 Generating Prerequisites Automatically.
#READ GNU gcc manuel 3.13 Options controlling the preprocessor.
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) $(HEADS) -MM $< > $@.$$$$ ; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
    rm -f $@.$$$$

# .......................... targets construction ............................ #
$(FRACT): Makefile  $(OBJS_FRACT) -l$(LOADLIBMLIBX) 
	@echo "$(GREEN)========== GATHERING FRACTOL OBJECTS =============$(DEF_COLOR)"
	$(CC) $(LFLGS) $(OBJS_FRACT) -o $@ $(LLIBS) $(FRAMEWORKS)

$(BONUS): Makefile $(OBJS_BONUS) -l$(LOADLIBMLIBX)
	@echo "$(ORANGE)======= GATHERING FRACTOL BONUS OBJECTS ============$(DEF_COLOR)"
	$(CC) $(LFLGS) $(OBJS_BONUS) -o $@ $(LLIBS) $(FRAMEWORKS)

$(TESTS): Makefile $(OBJS_TESTS) -l$(LOADLIBMLIBX)
	@echo "$(MAGENTA)========== GATHERING TESTS OBJECTS ===============$(DEF_COLOR)"
	$(CC) $(LFLGS) $(OBJS_TESTS) -o $@ $(LLIBS) $(FRAMEWORKS)

# .......................... objects construction ............................ #
$(OBJDIR)%.o: $(SRCDIR_FRACT)%.c $(INCDIR)$(HEADER_FRA)
	@echo "$(GREEN)========== COMPILING FRACTOL FILES ===============$(DEF_COLOR)"
	$(CC) $(CFLGS) $< -o $@ $(HEADS)  

$(OBJDIR)%.o: $(SRCDIR_BONUS)%.c $(INCDIR)$(HEADER_BON)
	@echo "$(ORANGE)========== COMPILING FRACTOL BONUS FILES ===============$(DEF_COLOR)"
	$(CC) $(CFLGS) $< -o $@ $(HEADS)  

$(OBJDIR)%.o: $(SRCDIR_TESTS)%.c $(INCDIR)$(HEADER_TES)
	@echo "$(MAGENTA)========== COMPILING TESTS FILES ===============$(DEF_COLOR)"
	$(info source files $(SRCS_TESTS))
	$(info source paths $(FILE_TESTS))
	$(info object patha $(OBJS_TESTS))
	$(CC) $(CFLGS) $< -o $@ $(HEADS)  


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
	rm -f $(NAME) $(OBJ)
	rm -rf $(OBJDIR)


fclean: clean
	rm $(FRACT)
	rm $(BONUS)
	rm $(TESTS)
	rmdir $(OBJDIR)
	rmdir $(LIBDIR)

re: fclean all


norma:
	$(MAKE) -C $(SRCDIR_MLIBX)  norma
	@echo "$(GREEN)============ CHECKING NORME $(FRACT) ==============$(DEF_COLOR)"
	norminette $(SRCDIR_FRACT) 
	@echo "$(ORANGE)========== CHECKING NORME $(BONUS) ==============$(DEF_COLOR)"
	norminette $(SRCDIR_BONUS)
	@echo "$(MAGENTA)========== CHECKING NORME $(TESTS) ==============$(DEF_COLOR)"
	norminette $(SRCDIR_TESTS)
	norminette $(INCDIR)
