/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:13:27 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/19 12:42:32 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"

/* ************************************************************************** */
/*          a           b                                                     */
/*  |..............x..........|                                               */
/*  O                         W                                               */
/*                                                                            */
/*  OW/(OW-Ox) = rb         600/(600-400) = 3                                 */
/*  OW/Ox      = ra         600/400       = 1,5                               */
/*  rb/ra      = r          3/1,5         = 2                                 */
/*  x = r * (OW / rb)       2 * (600 / 3) = 400                               */
/*                                                                            */
/* ************************************************************************** */
/*
static int	calculate_center(int ow, int x, float *rb)
{
	float	r;
	float	ra;
	float	fx;

	fx = 1.0 * x;
	*rb = ow / (ow - fx);
	ra = ow / fx;
	r = *rb / ra;
	return ((int)r * ow / *rb);
}
*/
/*
static int	get_color(int fractal, float x, float y, float cx, float cy)
{
	t_complex	z;
	t_complex	c;

	if (fractal == 1)
	{
		c = create((x - cx) / (w1.w / 3.0), -(y - cy) / (w1.h / 3.0));
		color = is_mande(c);
	}
	else if (fractal == 2)
	{
		color = is_julia(create((x - cx) / (w1.w / 3.0), -(y - cy) / (w1.h / 3.0)));
	}
	else
		color = BLACK;
	return (color);
}
static int	get_color(t_win w, t_complex c)
{
	if (!ft_strncmp(w.title, "Mandelbrot", 10))
		return (is_mande(c, w.z, w.palette));
	if (!ft_strncmp(w.title, "Julia", 5))
		return (is_julia(c, w.z, w.palette));
	if (!ft_strncmp(w.title, "Ship", 4))
		return (is_ship(w.z, c, w.palette));
	return (WHITE);
}
*/

void	draw_fractal(t_win w)
{
	if (!ft_strncmp(w.title, "Mandelbrot", 10))
		draw_mande(w);
	//if (!ft_strncmp(w.title, "Julia", 5))
	//	draw_julia(c, w.z, w.palette);
	//if (!ft_strncmp(w.title, "Ship", 4))
	//	draw_ship(w.z, c, w.palette);
	//return (WHITE);
/*	float		xo;
	float		yo;
	float		rbx;
	float		rby;
	float		cx;
	float		cy;
	float		color;
	t_complex	c;

	cx = calculate_center(w1.w, w1.md_x, &rbx);
	cy = calculate_center(w1.h, w1.md_y, &rby);
	//cx = 2.0 * (w1.w / 3.0);
	//cy = (w1.h / 2.0);
	yo = 0.0;
	while (yo <= w1.h)
	{
		xo = 0.0;
		while (xo <= w1.w)
		{
			c = create((xo - w1.w_0) * (w1.img.real / w1.w_0), 
						(yo - w1.h_0) * (w1.img.imag / w1.h_0));
			color = get_color(w1, c);
			win_pixel_put(w1, xo, yo, color);
			xo++;
		}
		yo++;
	}
	mlx_put_image_to_window(w1.mlx_ptr, w1.win_ptr, w1.img.img_ptr, 0, 0);
	*/
}

void	draw_square_2(t_win w1, t_point ul, t_point lr)
{
	int	i;

	if ((lr.x - ul.x) > w1.img.w || (lr.y - ul.y) > w1.img.h)
		return ;
	i = ul.x;
	while (i <= lr.x)
	{
		win_pixel_put(w1, i, ul.y, col_create(0, 0, i, ul.y));
		i++;
	}
	i = ul.x;
	while (i <= lr.x)
	{
		win_pixel_put(w1, i, lr.y, col_create(0, 0, i, lr.y));
		i++;
	}
	i = ul.y;
	while (i <= lr.y)
	{
		win_pixel_put(w1, ul.x, i, col_create(0, 0, i, ul.x));
		i++;
	}
	i = ul.y;
	while (i <= lr.y)
	{
		win_pixel_put(w1, lr.x, i, col_create(0, 0, i, lr.x));
		i++;
	}
}
