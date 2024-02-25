/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_mouse_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:32:45 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/26 00:50:44 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include "keys_ubuntu.h"
/*
static void	calculate_shift_x(int x, t_win *w)
{
	int			ix;
	int			a;

	ix = x + w->img.lu_x;
	if (ix < w->img.x_0)
	{
		a = (int)(( w->img.x_0 - ix) * w->scale);
		w->shift_x +=  a;
		w->img.lu_x += a;
		w->img.rd_x += a;
	}
	if (ix >= w->img.x_0)
	{
	 	a = (int)((ix - w->img.x_0) * w->scale);
		w->shift_x -= a;
		w->img.lu_x -= a;
		w->img.rd_x -= a;
	}
}

static void	calculate_shift_y(int y, t_win *w)
{
	int			iy;
	int			a;

	iy = -y + w->img.lu_y;
	if (iy < w->img.y_0)
	{   a = (int)((w->img.y_0 - iy) * w->scale);
		w->shift_y += a;
		w->img.lu_y += a;
		w->img.rd_y += a;
	}
	if (iy >= w->img.y_0)
	{   a = (int)((iy - w->img.y_0) * w->scale);
		w->shift_y -= a;
		w->img.lu_y -= a;
		w->img.rd_y -= a;
	}
}

static void calculate_shift(int x, int y, t_win *w)
{
	calculate_shift_x(x, w);
	calculate_shift_y(y, w);
	//w->shift_x += (w->mm_x - x);
	//w->shift_y += (w->mm_y - y);
}
*/
static void	calculate_shift(int x, int y, t_win *w)
{	
	int	a;

	if (x > w->mm.x)
	{
		a = (x - w->mm.x) / w->scale;
		w->shift.x += a;
		w->img.lu.x += a;
		w->img.rd.x += a;
	}
	else
	{
		a = (w->mm.x - x) / w->scale;
		w->shift.x -= a;
		w->img.lu.x -= a;
		w->img.rd.x -= a;
	}
	if (y > w->mm.y)
	{
		a = (y - w->mm.y) / w->scale;
		w->shift.y += a;
		w->img.lu.y += a;
		w->img.rd.y += a;
	}
	else
	{	
		a = (w->mm.y - y) / w->scale;
		w->shift.y -= a;
		w->img.lu.y -= a;
		w->img.rd.y -= a;
	}
}

int	win_h_mouse_down(int button, int x, int y, t_win *w)
{
	//if ((button == MOUSE_SCROLL_DOWN) && (w->zoom < w->iteractions))
	if ((button == MOUSE_SCROLL_DOWN))
	{
		w->zoom++;
		w->scale *= ZOOM_FACTOR;
		calculate_shift(x, y, w);
		draw_fractal(*w);
	}
	//else if ((button == MOUSE_SCROLL_UP) && (w->zoom > INITIAL_ZOOM))
	else if ((button == MOUSE_SCROLL_UP))
	{
		w->zoom--;
		w->scale *= (1 / ZOOM_FACTOR);
		calculate_shift(x, y, w);
		draw_fractal(*w);
	}
	else if (button == MOUSE_BUTTON_LEFT)
	{
		draw_fractal(*w);
	}
	ft_printf("dowm (%d, %d) button %d zoom %d \n", x, y, button, w->zoom);
	return (0);
}
