# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 18:08:17 by luicasad          #+#    #+#              #
#    Updated: 2024/02/12 13:05:07 by luicasad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
MAKEFLAGS += rR
# ============================================================================ #
#                                 COLORS                                       #
# ============================================================================ #
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m
BLACK		=	\033[0;99m
ORANGE		=	\033[38;5;209m
BROWN		=	\033[38;2;184;143;29m
DARK_GRAY	=	\033[38;5;234m
MID_GRAY	=	\033[38;5;245m
DARK_GREEN	=	\033[38;2;75;179;82m
DARK_YELLOW	=	\033[38;5;143m
# ============================================================================ #
#                                 TARGETS                                      #
# ============================================================================ #
NAME = libftcomplex.a
# ============================================================================ #
#                                 FOLDERS                                      #
# ============================================================================ #
#OBJDIR		= ../../obj/
INCDIR		= ../../inc/
LIBDIR		= ../../lib/
OBJDIR		= 
vpath %.a $(LIBDIR)
# ============================================================================ #
#                               COMPILER SETUP                                 #
# ============================================================================ #
CC 			= 	cc
CFLAGS 		= 	-g3 -Wall -Wextra -Werror
#CFLAGS 		= 	-g3 -Wall -Wextra -Werror -fsanitize=address
HEADS		=	-I$(INCDIR)
LFLGS		=
#LFLGS		=	-fsanitize=address
# From 4.4.3 The Function wildcard gnu make manual....
# Althought wildcard exparnds automaticaly in rules
# I use the wildcard function to expand wildcards in variables. 
# SRCS = $(wildcard *.c)
#
# This technique is forbidden according to 42 Norm point III.11
#
# So I must explicitly enumerate files for the project.

HEADER		=	ft_complex.h
SRCS 		= 	ft_complex.c \
				add_subs.c \
				mult_div.c

# Generate a list of object files by replacing .c with .o

_OBJS:=$(SRCS:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(_OBJS))
 
# The default goal is the first target of the first rule in the first makefile.
# This is the reason for writtting this rule the first one

all: $(NAME)
#includes all dependencies files.
#READ GNU make  manual 4.14 Generating Prerequisites Automatically.
include $(SRCS:.c=.d)

$(NAME): $(OBJS)
	@echo "$(ORANGE)FT_COMPLEX ======= GATHERING ALL OBJECTS =====================$(DEF_COLOR)"
	ar rcs $(LIBDIR)$(NAME) $?

# For each c file create its object file.
#$(OBJS): $(SRCS) Makefile $(INCDIR)$(HEADER)

%.o: %.c Makefile $(INCDIR)$(HEADER)
	@echo "$(ORANGE)FT_COMPLEX ======= COMPILING ALL OBJECTS =====================$(DEF_COLOR)"
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADS)

#for each c file create its dependency file
#READ GNU make  manual 4.14 Generating Prerequisites Automatically.
#READ GNU gcc manuel 3.13 Options controlling the preprocessor.
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) $(HEADS) -MM $< > $@.$$$$ ; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$


# removes all generated object files
clean:
	@echo "$(ORANGE)FT_COMPLEX ======= REMOVING ALL OBJECTS ======================$(DEF_COLOR)"
	rm -f $(OBJS)
	rm -f *.d

# removes target file and all generated object files
fclean: clean
	@echo "$(ORANGE)FT_COMPLEX ======= REMOVING TARGET ==========================$(DEF_COLOR)"
	rm -f $(LIBDIR)$(NAME)

# rebuild all after removing all
re: fclean all
	@echo "$(ORANGE)FT_COMPLEX ======== REBUILDING ===============================$(DEF_COLOR)"
norma: $(SRCS)
	@echo "$(ORANGE)FT_COMPLEX ======= CHECKING NORME ===========================$(DEF_COLOR)"
	norminette  $(SRCS)


.PHONY: all clean fclean re

