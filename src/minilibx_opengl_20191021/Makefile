#
#
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

LIBDIR		= ../../lib/
vpath %.a $(LIBDIR)
#OBJDIR		= ../../obj/
#vpath %.o $(LIBDIR)
NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJS=$(OBJ1:.m=.o)

#OBJS	= $(addprefix $(OBJDIR), $(OBJ))

#CFLAGS+=-g -Wall -Werror -Wextra
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(NOM):	$(OBJS)
	ar rcs $(LIBDIR)$(NOM) $(OBJS)
	ranlib $(LIBDIR)$(NOM)

%.o: %.c Makefile 
	@echo "$(BLUE)MLIBX ========== COMPILING *.c OBJECTS ====================$(DEF_COLOR)"
	$(CC) $(CFLAGS)  -c $< -o $@ $(HEADS)

%.o: %.m Makefile 
	@echo "$(BLUE)MLIBX ========== COMPILING *.m OBJECTS ====================$(DEF_COLOR)"
	$(CC) $(CFLAGS)  -c $< -o $@ $(HEADS)
clean:
	@echo "$(BLUE)MLIBX ========== CLEANING  *.o OBJECTS ====================$(DEF_COLOR)"
	rm -f $(OBJS)
	rm -f *~
	rm -f mlx_app

fclean: clean
	@echo "$(BLUE)MLIBX ========== CLEANING  *.a OBJECTS ====================$(DEF_COLOR)"
	rm -f $(NOM) 
re: fclean all

norma:
	norminette 
