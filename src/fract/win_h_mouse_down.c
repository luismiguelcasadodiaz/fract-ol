/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_h_mouse_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:32:45 by luicasad          #+#    #+#             */
/*   Updated: 2024/02/22 11:11:26 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include "keys_mac.h"
static void	calculate_shift_x(int x, t_win *w)
{
	int			ix;
	int			a;

	ix = x + w->img.lu_x;
	if (ix < w->img.x_0)
	{
		a = w->img.x_0 - ix;
		w->shift_x +=  a;
		w->img.lu_x += a;
		w->img.rd_x += a;
	}
	if (ix >= w->img.x_0)
	{
	 	a = ix - w->img.x_0;
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
	{   a = w->img.y_0 - iy;
		w->shift_y += a;
		w->img.lu_y += a;
		w->img.rd_y += a;
	}
	if (iy >= w->img.y_0)
	{   a = iy - w->img.y_0;
		w->shift_y -= a;
		w->img.lu_y -= a;
		w->img.rd_y -= a;
	}
}

static void calculate_shift(int x, int y, t_win *w)
{
	calculate_shift_x(x, w);
	calculate_shift_y(y, w);
}

int	win_h_mouse_down(int button, int x, int y, t_win *w)
{
	if ((button == MOUSE_SCROLL_DOWN) && (w->zoom < w->iteractions))
	{
		w->zoom++;
		calculate_shift(x, y, w);
		draw_fractal(*w);
	}
	else if ((button == MOUSE_SCROLL_UP) && (w->zoom > INITIAL_ZOOM))
	{
		w->zoom--;
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
