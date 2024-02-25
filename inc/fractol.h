/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:47:24 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/26 00:47:03 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MLX_ERROR 1
# define INITIAL_ZOOM 1
# define ZOOM_FACTOR 1.05
# define MAX_ITERATIONS 5
# define WINDOW_W 900
# define WINDOW_H 600
# define ASPECT_RATIO_1_H 4
# define ASPECT_RATIO_1_V 3

# define ASPECT_RATIO_2_H 16
# define ASPECT_RATIO_2_V 9

# define ASPECT_RATIO_3_H 21
# define ASPECT_RATIO_3_V 9

# define BLACK 0x00000000
# define RED   0x00FF0000
# define GREEN 0x0000FF00
# define BLUE  0x000000FF
# define WHITE 0x00FFFFFF

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17
# include "ft_complex.h"
# include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

t_point	point_init(void);
t_point	point_set(int x, int y);

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*  real : real axis width. From -2 to 2. starts with 2 * COMPLEX_REAL_MAX    */
/*  imag : imag axis height. From -i to i. starts with 2 * COMPLEX_IMAG_MAX   */
/*  r_x  :ratio horizontal real_width / horizontal _width                     */
/*  r_y  :ratio horizontal imag_width / vertical _width                       */
/*                                                                            */
/* ************************************************************************** */
typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_point	size;
	t_point	lu;
	t_point	rd;
	int		x_0;
	int		y_0;
	float	real;
	float	imag;
	float 	r_x;
	float 	r_y;
	t_complex	z;
}	t_img;

/* ************************************************************************** */
/* w : windows width in pixels                                                */
/* h : windows height in pixels                                               */
/* md_x : x coordinate of last mousedown event                                */
/* md_y : y coordinate of last mousedown event                                */
/* mu_x : x coordinate of last mouseup event                                  */
/* mu_y : y coordinate of last mouseup event                                  */
/* mm_x : x coordinate of last mousemove event                                */
/* mm_y : y coordinate of last mousemove event                                */
/* zoom : zoom level [1..MAX_ITERATIONS]                                      */
/* shift_x : horizontal shift requested by LEFT or RIGHT ARROWS               */
/* shitf_y : vertical shifht requested by UP or DOWN ARROWS                   */
/* palete : RGB integer to multiply by number of iterations.                  */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	char		*title;
	t_point		size;
	t_point		lu;
	t_point		rd;
	t_point		md;
	t_point		mu;
	t_point		mm;
	int			zoom;
	float		scale;
	t_point		shift;
	int			palette;
	int			iteractions;
}				t_win;
t_win	win_init(char *title, char *real_txt, char *imag_txt);
int		win_h_key_down(int keysym, t_win *data);
int		win_h_key_up(int keysym, t_win *data);
int		win_h_mouse_down(int button, int x, int y, t_win *data);
int		win_h_mouse_up(int button, int x, int y, t_win *data);
int		win_h_mouse_move(int x, int y, t_win *data);
int		win_h_not_event(t_win *data);
int		win_h_expose(t_win *data);
int		win_h_destroy(t_win *data);
void	win_pixel_put(t_win w, int x, int y, int color);
void	draw_fractal(t_win w);
void	draw_square_2(t_win w, t_point upper_left, t_point lower_right);

int		col_create(int transp, int red, int green, int blue);
int		col_get_t(int color);
int		col_get_r(int color);
int		col_get_g(int color);
int		col_get_b(int color);

void	draw_mande(t_win w);
void	draw_julia(t_win w);
void	draw_ship(t_win w);
void	draw_white(t_win w);
void	show_usage(void);
void	show_data(t_win w);
#endif
