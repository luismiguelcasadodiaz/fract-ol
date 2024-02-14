/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:13:27 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/14 17:57:56 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

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
*/

void	draw_fractal(t_win w1)
{
	float	x;
	float	y;
	float	rbx;
	float	rby;
	float cx;
	float cy;
	float color;
	t_complex	z;
	t_complex	c;

	cx = calculate_center(w1.w, w1.md_x, &rbx);
	cy = calculate_center(w1.h, w1.md_y, &rby);
	z = create(w1.md_x / w1.w, w1.md_y / w1.h);
	z = create(0, 0);
	//cx = 2.0 * (w1.w / 3.0);
	//cy = (w1.h / 2.0);
	y = 0.0;
	while (y <= w1.h)
	{
		x = 0.0;
		while (x <= w1.w)
		{
		    c = create(((x / w1.zoom) - cx) / (w1.w / rbx), -((y / w1.zoom) - cy) / (w1.h / rby));
			color = is_mande(z, c, w1.palette);
			//color = is_julia(z, c, w1.palette);
			win_pixel_put(w1, x, y, color); 
			//win_pixel_put(w1, x, (w1.h - y) , color); 
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(w1.mlx_ptr, w1.win_ptr, w1.img.img_ptr, 0, 0);
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
