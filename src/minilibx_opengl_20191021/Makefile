#
#

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
	rm -f $(OBJS)
	rm -f *~
	rm -f mlx_app

fclean: clean
	rm -f $(NOM) 
re: fclean all

norma:
	norminette 
