/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:47:24 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/13 13:19:58 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MLX_ERROR 1
# define MAX_ITERATIONS 65
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

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17
# include "ft_complex.h"


typedef struct s_point
{
	int	x;
	int y;
}	t_point;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
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
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	char	*title;
	int		w;
	int		h;
	int		md_x;
	int		md_y;
	int		mu_x;
	int		mu_y;
	int		mm_x;
	int		mm_y;
	int		zoom;
}				t_win;
t_win	*win_init(char *title, int wide, int height);
t_win	win_init_2(char *title, int wide, int height);
int		win_h_key_down(int keysym, t_win *data);
int		win_h_key_up(int keysym, t_win *data);
int		win_h_mouse_down(int button, int x , int y, t_win *data);
int		win_h_mouse_up(int button, int x , int y, t_win *data);
int		win_h_mouse_move(int x , int y, t_win *data);
int		win_h_not_event(t_win *data);
int		win_h_destroy(t_win *data);
void	win_pixel_put(t_win w, int x, int y, int color);
void	draw_fractal(t_win w);
void	draw_square_2(t_win w, t_point upper_left, t_point lower_right);

int		col_create(int transp, int red, int green, int blue);
int		col_get_t(int color);
int		col_get_r(int color);
int		col_get_g(int color);
int		col_get_b(int color);

int		is_mande(t_complex c);
int		is_julia(t_complex z, t_complex c);
#endif
